# 当前状态：正在直接解析原始 D3D8 二进制

用户已明确拒绝下方早期视觉近似版；该近似版不是最终交付。当前实际工作与原始数据证据见[二进制解析进度](<analysis/STATUS.md>)，新的[直接 D3D12 后端](<analysis/native/backend.cpp>)使用原程序生成的网格、纹理、状态及矩阵。正在继续恢复原始场景图和时间轴，不把兼容后端验证冒称独立引擎移植完成。

---

# 早期测试基线：C++ / D3D12 视觉重建（已被否决）

这是参照 Farbrausch 的 **fr-08: .the .product (2000 / v1.01)** 制作的可运行重建工程。

**范围说明：**不是原程序的反编译移植，也不是逐帧一致的高保真复制。目前重新编写了七个主要场景的程序化几何、纹理和镜头，并加入尾部滚屏。原版的精确模型、纹理算子、镜头曲线、字效、合成器和逐拍剪辑没有恢复；场景切换时间是参照公开录像重新安排的。不要把本工程当成原版 64 KB intro。

画面由 C++ + D3D12 实时生成，**不启动原 EXE、不播放参考视频、不用原视频帧充当渲染画面**。运行时不需要网络。附带的 MP3 是原作者公开发布的主音轨，不是重新实现原合成器。

## 运行

程序：[fr08_d3d12.exe](<build/fr08_d3d12.exe>)。Windows 10/11 x64，支持 D3D12 的显卡；没有硬件设备时自动尝试 WARP。

在项目根目录运行：

~~~powershell
.\build\fr08_d3d12.exe
.\build\fr08_d3d12.exe --width 1537 --height 865
.\build\fr08_d3d12.exe --fullscreen
.\build\fr08_d3d12.exe --scene 7 --mute
~~~

- 初始客户区默认 1280×720，可自由拖动、最大化、最小化和恢复。
- 支持非预设、奇数、纵向和超宽分辨率；视口、投影、HDR 渲染目标、深度缓冲及交换链均随客户区重建，不把固定分辨率画面拉伸到窗口。
- D3D12 纹理单边上限为 16384；超大尺寸能否分配还取决于显存，不承诺无限尺寸。
- 无边框全屏覆盖窗口所在显示器，使用原生显示模式，不改变系统分辨率；退出后恢复原窗口样式和位置。
- HUD 默认隐藏，按 H 查看操作提示。

| 操作 | 按键 |
|---|---|
| 无边框全屏 / 恢复窗口 | F11、Alt+Enter |
| 暂停 / 继续 | Space |
| 场景直接跳转 | 1–8 |
| 前后跳转五秒 | ← / → |
| 回到开头 | Home |
| 显示 / 隐藏 HUD | H |
| 静音 | M |
| 原生 GPU 后缓冲截图 | F12 |
| 退出 | Esc |

场景顺序：石廊 → 城堡 → 风机房 → 圆形砖井 → 红色木室 → 工业塔 → 水上环塔 → 尾部滚屏。全长约 7 分 20 秒并循环。

音轨需要与程序相邻的 [assets/the_product_main.mp3](<build/assets/the_product_main.mp3>)；缺失时仍可静音观看。自动验收始终静音，未以自动测试验证扬声器实际输出。

## 构建

安装 Visual Studio 的“使用 C++ 的桌面开发”、Windows SDK 和 CMake。工程没有第三方 C++ 包、运行时下载或外部图形引擎。

~~~powershell
.\build.ps1
~~~

[构建脚本](<build.ps1>)会寻找 MSVC，优先使用 Ninja，未找到时使用 NMake。只构建，不启动程序。构建输出保存在项目下，不向 AppData 安装内容。

也可以在 x64 Native Tools 开发者命令行中运行：

~~~bat
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
~~~

## 不抢前台的自动验收

~~~powershell
.\test.ps1
.\test.ps1 -Warp
~~~

[验收脚本](<test.ps1>)使用[独立桌面启动器源码](<tools/isolated_run.cpp>)，不在活动输入桌面运行测试、不调用 SwitchDesktop、不注入全局键鼠输入、不操作其他游戏。每次生成新的会话标记，使用完整 EXE 路径和专属 Job 确认进程所有权。程序的 --test 还会拒绝在活动输入桌面启动。

验收覆盖：

1. 自主启动，内部命令进入七个主要场景和滚屏，直接定位固定时间与镜头。
2. 保留正常 Present，用同一 D3D12 direct queue 把真实后缓冲复制到 readback 资源，资源状态转换正确，fence 完成后才读 CPU 数据，再保存 PNG。
3. 核对图片 PID、会话、帧号、尺寸、新鲜度、亮度变化，防止黑屏/平色帧被误当成成功。
4. 覆盖 913×517、517×913、1600×500、127×83、1×1、1920×1080、3840×2160，以及显示器原生无边框分辨率。
5. 反复全屏切换、最小化后恢复；对恢复后的固定镜头图片做 SHA-256 一致性检查。
6. 记录初始化、首帧、到达指定截图的耗时、同一实例取图耗时、D3D12 调试层错误、输入桌面/前台观测及退出清理。

这些测试证明窗口模式、渲染链和指定场景确实运行，**不证明与原作画面一致，也不代替音频听感验收**。

### 同一实例的内部控制

--commands 指定一个 UTF-8 文本文件，每行一个受限命令。程序定期读取新增命令，无需反复重启。不能执行任意代码或 shell。测试完成需追加 quit。

~~~text
pause 1
scene 7
time 240
size 1537 865
capture rings.png
fullscreen 1
capture rings-fullscreen.png
fullscreen 0
quit
~~~

~~~powershell
.\build\isolated_run.exe "$PWD\build\fr08_d3d12.exe" my-session 120 --test --mute --commands "$PWD\commands.txt" --output "$PWD\captures\my-session"
~~~

可用命令：scene 1..8、time 0..439.9、size w h、fullscreen 0/1、pause 0/1、hud 0/1、capture 简单文件名、minimize、restore、quit。截图命令不允许目录跳转。没有持久化配置或存档；全屏状态在正常退出时恢复。输出默认留在工作目录，不写用户 AppData。

## 工程布局

- [CMakeLists.txt](<CMakeLists.txt>)：MSVC / Windows SDK 构建。
- [main.cpp](<src/main.cpp>)：Win32、DPI、窗口恢复、时间轴、内部命令及截图身份记录。
- [renderer.cpp](<src/renderer.cpp>)：D3D12 三缓冲、fence、HDR 场景、后处理、字形图集与 GPU 原生读回。
- [scenes.cpp](<src/scenes.cpp>)：几何生成、场景实例和镜头。
- [shaders.hlsl](<src/shaders.hlsl>)：程序纹理、光照、雾、色调映射及文字。构建时嵌入 EXE。
- [audio.cpp](<src/audio.cpp>)：Windows MCI 原曲播放、暂停和跳转。

## 原作与参考

原作及音乐版权属于原作者。此工程为非官方重建，未获得 Farbrausch 背书。

- [原作发布页及作者名单](https://www.pouet.net/prod.php?which=1221)
- [Hugi 原作制作访谈及截图](https://hugi.scene.org/online/hugi22/adfr08.htm)
- [kb 原作公开主音轨](https://files.scene.org/view/music/groups/farb-rausch/008b-kb-the_product_main.mp3)
- [kb 公开参考录像](https://ftp.untergrund.net/users/kb/videos/Farbrausch%20-%20fr-08%20.the%20.product.avi)

原作：设计 fiver / 5r2，代码 chaos，合成器及音乐 kb，压缩 ryg / torus，附加代码 yoda。下载的参考录像、原 EXE 以及调试兼容层只用于分析，不属于运行依赖，也不包含在运行包中。
