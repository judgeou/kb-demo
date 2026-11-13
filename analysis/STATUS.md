# 原二进制解析进度（不是完成交付）

用户明确拒绝视觉近似版。根目录早期 src/ 是被否决的测试基线，不是最终复刻成果。新的工作必须依据原二进制真实数据。

## 已验证的事实

- 原件 SHA256: 2B6F58BA715909BE1D1276A3F93442421C2A20D89CB1188E6B5D2B7BCA840E97；分析运行副本相同，未修改磁盘 EXE。
- PE32 x86，PE 头偏移 0x0c，映像基址 0x400000，SizeOfImage 0x32b000，压缩入口 RVA 0x3296b0。
- 已在 Direct3DCreate8 入口转储解包映像，保存于 [原始映像](<analysis/runtime/unpacked-0000-00.bin>)。
- [反汇编用映像](<analysis/unpacked-inspect.exe>)仅修正了节的文件布局，不能当成重建后的可运行 EXE。
- 原件静态导入 DSOUND ordinal 11 = DirectSoundCreate8。记录器用完全进程内静音接口处理，没有打开真实音频设备。
- 原 D3D8 驱动在非活动桌面失败；自行实现 COM 接口后，原生成器可以正常执行。不是将旧驱动失败视为阻塞。
- original-trace-04 自主隔离运行成功；600 帧，21.875 秒，76,305 次 DrawIndexedPrimitive，全为 triangle list。
- 68 次 CreateTexture：3 张 512² render target + 65 张 256² A8R8G8B8、9 mip 的真实原作纹理。已直接解码 65 张，无视频取帧。
- 13 个 VB，16 个 IB；FVF 0x152（XYZ/NORMAL/DIFFUSE/TEX1，36 字节）和 0x2c2（XYZ/DIFFUSE/SPECULAR/TEX2，36 字节）。索引格式 101 = INDEX16。
- 原始状态、矩阵、材质、视口、纹理绑定和绘制参数记录在 [调用流](<analysis/runtime/trace.d8>)。
- 原作视口：加载时 800×600，场景时 x=0,y=45,w=800,h=510（宽屏画面）。
- 状态样本：CullMode=3；AlphaTestEnable=1、AlphaRef=6、AlphaFunc=5；stage0 MODULATE(texture,diffuse)，stage1 常禁用或 ADDSIGNED；stage1 TexCoordIndex 曾为 0x30001（camera-space reflection vector）。
- 变换状态只有 VIEW=2、PROJECTION=3、TEXTURE0=16、TEXTURE1=17、WORLD=256。材质原始全白，Ambient=0xffffffff；顶点颜色不能由近似灯光替代。

## 已反汇编的时钟与音频协议

- 0x40a064: 原始 float->int16 样本转换；它检查锁定块指针非空而不检查 size==0。静音接口必须在无 wrap 时返回第二指针 NULL，否则 LOOP 在零长度下下溢。这个问题已按真实指令定位并修复。
- 0x40a335: 原始环形 DS 缓冲时钟，返回累计字节。
- 0x409ae3: 原演出时钟，调用 0x40a335，减全局 0x592df0，乘1000再除176400，返回毫秒。无参数 cdecl。
- 可用该函数安装带签名验证的进程内跳转，以受限内部命令精确驱动原场景时间，不发送全局键鼠。

## WIP 提交时的最新进度

- 已新增 [C++ 直接 D3D12 后端](<analysis/native/backend.cpp>)及[原程序接口桥接](<analysis/native/bridge.cpp>)。它读取原始 CPU 锁定资源、固定功能状态和矩阵，不调用系统 D3D8/D3D9 绘制。
- original-native-03 已完成 20 张真实 GPU 截图：8 个原始时间点及奇数、竖屏、超宽、1×1、1080p、4K、2880×1800 原生无边框、恢复窗口与最小化恢复；D3D12 调试层零错误，隔离桌面和前台观测通过。采样文件保留在本地运行目录，不纳入 Git。
- 已反编译原始引擎函数，恢复了内容图格式：3015 节点、65 纹理根、55 场景根、277 时间事件、1206 动画通道、3235 关键帧、15629 压缩参数、70 自定义表、136 字符串，21 类算子分派。
- [独立 C++ 内容解析器](<analysis/parser/fr08_content.cpp>)已可完整解码上述数据，所有相对节点引用和曲线字段绑定均有效。
- 正在进行参数、曲线系数与原求值函数的逐位 oracle 对照，尚未完成。最近一次真值采样因通道数组基址误判而失败，已依据反汇编修正为 0x004ccad8；修正后的版本尚待重新验证。
- 最新代码补齐了 D3D8 默认 x87 单精度控制契约，并对倒退寻址调用原时间轴重置入口。不能把此前版本的验收结论直接套用到这些未完成复验的修改。
- 当前真实 D3D12 渲染路径仍执行原始 x86 生成器/演出代码，不是独立引擎移植完成；21 类原始算子和场景执行逻辑还需继续恢复、移植和对照。
- 外国网站访问按用户要求使用 socks5://127.0.0.1:4322。Ghidra 后续缓存已显式改为项目目录。
- analysis/d3d8to9 作为锁定版本的 Git 子模块，仅用于 D3D8 接口/结构体声明，未使用其 D3D9 渲染实现。

## 下一步

1. 给记录器补齐 SetRenderTarget/纹理 usage/每次 buffer 更新，避免把第一次 Unlock 的不完整静态缓冲当最终网格。
2. 实现原固定功能流水线的直接 D3D12 后端。优先在原进程中用当前 CPU 锁定资源、原矩阵和原渲染状态绘制，取得真实 GPU backbuffer 读回证据。
3. 原件执行加 D3D12 API 兼容后端只算忠实后端验证，不能冒称已经完成独立 C++ 引擎移植。继续解析内容图/时间轴并明确剩余范围。
4. 所有运行仍须独立非活动 Win32 桌面、专属 Job、完整路径+会话所有权、静音、不碰前台。既有 isolated_run 与读回/fence 代码可复用。
