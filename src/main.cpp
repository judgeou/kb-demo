#include "demo.h"
#include <shellapi.h>
#include <filesystem>
#include <sstream>
#include <iomanip>
namespace fs=std::filesystem;
namespace {
struct App {
 HWND hwnd{};std::unique_ptr<Renderer> renderer;World world;Audio audio;Options options;
 bool running=true,paused=false,hud=false,fullscreen=false,minimized=false;UINT pendingW=0,pendingH=0;RECT savedRect{};LONG_PTR savedStyle=WS_OVERLAPPEDWINDOW;float clock=0;int requested=-1;std::wstring capture;
 std::ofstream log;std::chrono::steady_clock::time_point start=std::chrono::steady_clock::now();
 double ms()const{return std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-start).count();}
 void event(const std::string&s){log<<std::fixed<<std::setprecision(2)<<ms()<<" ms | "<<s<<std::endl;}
 void toggle(bool enabled){if(enabled==fullscreen)return;if(enabled){GetWindowRect(hwnd,&savedRect);savedStyle=GetWindowLongPtrW(hwnd,GWL_STYLE);MONITORINFO mi={sizeof(mi)};GetMonitorInfoW(MonitorFromWindow(hwnd,MONITOR_DEFAULTTONEAREST),&mi);SetWindowLongPtrW(hwnd,GWL_STYLE,WS_POPUP|WS_VISIBLE);SetWindowPos(hwnd,HWND_NOTOPMOST,mi.rcMonitor.left,mi.rcMonitor.top,mi.rcMonitor.right-mi.rcMonitor.left,mi.rcMonitor.bottom-mi.rcMonitor.top,SWP_FRAMECHANGED|SWP_NOACTIVATE);}else{SetWindowLongPtrW(hwnd,GWL_STYLE,savedStyle);SetWindowPos(hwnd,HWND_NOTOPMOST,savedRect.left,savedRect.top,savedRect.right-savedRect.left,savedRect.bottom-savedRect.top,SWP_FRAMECHANGED|SWP_NOACTIVATE);}fullscreen=enabled;event(enabled?"borderless enter":"borderless restore");}
 void size(int w,int h){if(w<1||h<1||w>16384||h>16384)throw std::runtime_error("Resolution outside D3D12 texture limits [1,16384]");if(fullscreen)toggle(false);RECT r={0,0,w,h};AdjustWindowRectExForDpi(&r,(DWORD)GetWindowLongPtrW(hwnd,GWL_STYLE),FALSE,0,GetDpiForWindow(hwnd));SetWindowPos(hwnd,nullptr,0,0,r.right-r.left,r.bottom-r.top,SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE);}
 void jump(int s){requested=-1;clock=SceneStarts[std::clamp(s,0,7)]+6;audio.seek(clock);}
 void command(const std::string&line){std::istringstream in(line);std::string cmd;in>>cmd;if(cmd.empty()||cmd[0]=='#')return;event("command: "+line);
 if(cmd=="scene"){int s;if(!(in>>s)||s<1||s>8)throw std::runtime_error("scene expects 1..8");jump(s-1);}
 else if(cmd=="time"){float t;if(!(in>>t)||!std::isfinite(t))throw std::runtime_error("Invalid time");clock=std::clamp(t,0.f,439.9f);audio.seek(clock);}
 else if(cmd=="size"){int w,h;if(!(in>>w>>h))throw std::runtime_error("size expects width height");size(w,h);}
 else if(cmd=="fullscreen"){int b=1;in>>b;toggle(b!=0);}
 else if(cmd=="pause"){int b=1;in>>b;paused=b!=0;}
 else if(cmd=="hud"){int b=1;in>>b;hud=b!=0;}
 else if(cmd=="minimize"){ShowWindow(hwnd,SW_MINIMIZE);minimized=true;}
 else if(cmd=="restore"){ShowWindow(hwnd,SW_SHOWNOACTIVATE);minimized=false;RECT r;GetClientRect(hwnd,&r);pendingW=r.right;pendingH=r.bottom;}
 else if(cmd=="capture"){std::string name;in>>name;if(name.empty()||name.find("..")!=std::string::npos||name.find_first_of("/\\:")!=std::string::npos)throw std::runtime_error("Capture requires a simple filename");capture=fs::path(options.out)/fs::path(name);}
 else if(cmd=="quit")running=false;else throw std::runtime_error("Unknown internal command: "+cmd);
 }
};
LRESULT CALLBACK proc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp){auto*a=(App*)GetWindowLongPtrW(hwnd,GWLP_USERDATA);if(msg==WM_NCCREATE){a=(App*)((CREATESTRUCTW*)lp)->lpCreateParams;a->hwnd=hwnd;SetWindowLongPtrW(hwnd,GWLP_USERDATA,(LONG_PTR)a);}if(!a)return DefWindowProcW(hwnd,msg,wp,lp);
 switch(msg){case WM_CLOSE:a->running=false;return 0;case WM_DESTROY:PostQuitMessage(0);return 0;
 case WM_SIZE:a->minimized=wp==SIZE_MINIMIZED;if(!a->minimized){a->pendingW=LOWORD(lp);a->pendingH=HIWORD(lp);}return 0;
 case WM_DPICHANGED:{auto*r=(RECT*)lp;SetWindowPos(hwnd,nullptr,r->left,r->top,r->right-r->left,r->bottom-r->top,SWP_NOZORDER|SWP_NOACTIVATE);return 0;}
 case WM_GETMINMAXINFO:{auto*m=(MINMAXINFO*)lp;m->ptMinTrackSize={1,1};m->ptMaxTrackSize={16448,16448};return 0;}
 case WM_WINDOWPOSCHANGING:return 0; // Do not let DefWindowProc clamp explicit client sizes to caption/monitor metrics.
 case WM_ERASEBKGND:return 1;
 case WM_SYSKEYDOWN:if(wp==VK_RETURN&&(lp&(1<<29))){a->toggle(!a->fullscreen);return 0;}break;
 case WM_KEYDOWN:if(lp&(1<<30))return 0;if(wp==VK_ESCAPE)a->running=false;else if(wp==VK_F11)a->toggle(!a->fullscreen);else if(wp==VK_SPACE)a->paused=!a->paused;else if(wp=='H')a->hud=!a->hud;else if(wp=='M')a->options.muted=!a->options.muted;else if(wp>='1'&&wp<='8')a->jump((int)wp-'1');else if(wp==VK_LEFT){a->clock=std::max(0.f,a->clock-5);a->audio.seek(a->clock);}else if(wp==VK_RIGHT){a->clock=std::min(439.9f,a->clock+5);a->audio.seek(a->clock);}else if(wp==VK_HOME){a->clock=0;a->audio.seek(0);}else if(wp==VK_F12){a->capture=fs::path(a->options.out)/(L"frame-"+std::to_wstring(a->renderer?a->renderer->frameNumber:0)+L".png");}return 0;
 }return DefWindowProcW(hwnd,msg,wp,lp);
}
std::string utf8(const std::wstring&s){if(s.empty())return {};int n=WideCharToMultiByte(CP_UTF8,0,s.data(),(int)s.size(),nullptr,0,nullptr,nullptr);std::string b(n,0);WideCharToMultiByte(CP_UTF8,0,s.data(),(int)s.size(),b.data(),n,nullptr,nullptr);return b;}
std::wstring desktop(HDESK d){wchar_t name[256]={};DWORD n=0;if(d)GetUserObjectInformationW(d,UOI_NAME,name,sizeof(name),&n);return name;}
Options parse(){Options o;int n;auto v=CommandLineToArgvW(GetCommandLineW(),&n);try{for(int i=1;i<n;i++){std::wstring a=v[i];auto next=[&](){if(i+1>=n)throw std::runtime_error("Missing option argument");return std::wstring(v[++i]);};if(a==L"--width")o.width=std::stoi(next());else if(a==L"--height")o.height=std::stoi(next());else if(a==L"--scene")o.scene=std::stoi(next())-1;else if(a==L"--time")o.time=std::stof(next());else if(a==L"--fullscreen")o.fullscreen=true;else if(a==L"--mute")o.muted=true;else if(a==L"--warp")o.warp=true;else if(a==L"--debug")o.debug=true;else if(a==L"--test"){o.test=true;o.muted=true;}else if(a==L"--session")o.session=next();else if(a==L"--output")o.out=next();else if(a==L"--commands")o.script=next();else throw std::runtime_error("Unknown command-line option");}}catch(...){LocalFree(v);throw;}LocalFree(v);
 if(o.width<1||o.width>16384||o.height<1||o.height>16384||o.scene < -1||o.scene>7||!std::isfinite(o.time))throw std::runtime_error("Invalid resolution, scene or time");if(o.session.empty()||o.session.size()>100||o.session.find_first_not_of(L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_")!=std::wstring::npos)throw std::runtime_error("Invalid session tag");return o;}
}
int WINAPI wWinMain(HINSTANCE instance,HINSTANCE,PWSTR,int){
 SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);CoInitializeEx(nullptr,COINIT_APARTMENTTHREADED);int result=0;
 try{
 App a;a.options=parse();fs::create_directories(a.options.out);a.log.open(fs::path(a.options.out)/(L"run-"+a.options.session+L".log"));
 HDESK input=OpenInputDesktop(0,FALSE,DESKTOP_READOBJECTS);auto inputName=desktop(input),ownName=desktop(GetThreadDesktop(GetCurrentThreadId()));if(input)CloseDesktop(input);a.event("pid="+std::to_string(GetCurrentProcessId())+" session="+utf8(a.options.session)+" desktop="+utf8(ownName)+" input_desktop="+utf8(inputName));if(a.options.test&&ownName==inputName)throw std::runtime_error("--test refuses to run on the active input desktop. Use isolated_run.");
 a.event("geometry build begin");a.world.build();a.event("geometry ready vertices="+std::to_string(a.world.vertices.size()));
 WNDCLASSEXW wc={sizeof(wc)};wc.lpfnWndProc=proc;wc.hInstance=instance;wc.hCursor=LoadCursorW(nullptr,IDC_ARROW);wc.lpszClassName=L"FR08_D3D12_Rebuilt";if(!RegisterClassExW(&wc))throw std::runtime_error("RegisterClassEx failed");RECT rect={0,0,a.options.width,a.options.height};AdjustWindowRectExForDpi(&rect,WS_OVERLAPPEDWINDOW,FALSE,0,GetDpiForSystem());HWND hwnd=CreateWindowExW(0,wc.lpszClassName,L"fr-08: .the .product | C++ / D3D12 reconstruction",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,rect.right-rect.left,rect.bottom-rect.top,nullptr,nullptr,instance,&a);if(!hwnd)throw std::runtime_error("CreateWindowEx failed");ShowWindow(hwnd,SW_SHOWNOACTIVATE);GetClientRect(hwnd,&rect);
 a.event("window ready");a.renderer=std::make_unique<Renderer>(hwnd,rect.right,rect.bottom,a.options.warp,a.options.debug,a.world);a.event("renderer ready init_ms="+std::to_string(a.renderer->initMs)+" adapter="+a.renderer->adapterName);a.pendingW=a.pendingH=0;
 a.clock=std::clamp(a.options.time,0.f,439.9f);if(a.options.scene>=0)a.clock=SceneStarts[a.options.scene]+6;if(a.options.fullscreen)a.toggle(true);
 std::vector<std::string> commands;std::size_t commandIndex=0;UINT64 tick=0;bool first=true;auto last=std::chrono::steady_clock::now();
 if(a.options.test&&a.options.script.empty())commands={"pause 1","hud 0","scene 1","capture 01-passage.png","scene 2","time 30","capture 02-castle.png","time 42","capture 02-gate.png","scene 3","capture 03-turbines.png","scene 4","capture 04-shaft.png","scene 5","capture 05-red-chamber.png","scene 6","capture 06-industrial.png","scene 7","time 240","capture 07-rings.png","scene 8","time 300","capture 08-credits.png","size 913 517","scene 1","capture odd-913x517.png","size 517 913","capture portrait-517x913.png","size 1600 500","capture ultrawide-1600x500.png","size 127 83","capture tiny-127x83.png","size 1 1","capture minimum-1x1.png","size 1920 1080","capture hd-1920x1080.png","size 3840 2160","capture uhd-3840x2160.png","size 1280 720","fullscreen 1","capture borderless.png","fullscreen 0","capture restored-1280x720.png","fullscreen 1","fullscreen 0","fullscreen 1","fullscreen 0","capture repeated-restore.png","minimize","restore","capture after-minimize.png","quit"};
 a.paused=a.options.test;while(a.running){MSG msg;while(PeekMessageW(&msg,nullptr,0,0,PM_REMOVE)){if(msg.message==WM_QUIT)a.running=false;TranslateMessage(&msg);DispatchMessageW(&msg);}if(!a.running)break;
 if(tick%8==0){if(!a.options.script.empty()){std::ifstream script(fs::path(a.options.script));commands.clear();std::string line;while(std::getline(script,line))commands.push_back(line);}if(commandIndex<commands.size())a.command(commands[commandIndex++]);}
 if(!a.running)break;
 if(a.pendingW&&a.pendingH){a.renderer->resize(a.pendingW,a.pendingH);a.event("resize complete "+std::to_string(a.renderer->w())+"x"+std::to_string(a.renderer->h()));a.pendingW=a.pendingH=0;}
 auto now=std::chrono::steady_clock::now();float dt=std::chrono::duration<float>(now-last).count();last=now;if(!a.paused&&!a.minimized){a.clock+=std::min(dt,.1f);if(a.clock>=Duration){a.clock=0;a.audio.seek(0);}}
 a.audio.update(a.clock,a.paused||a.minimized,a.options.muted);if(a.minimized){Sleep(16);tick++;continue;}
 int s=sceneAt(a.clock);float local=sceneLocal(a.clock,s);auto capture=a.capture;a.capture.clear();auto begin=std::chrono::steady_clock::now();a.renderer->render(a.world,s,local,a.hud,a.paused,a.clock,a.fullscreen,capture);
 if(first){a.event("first usable target frame scene="+std::to_string(s+1)+" frame="+std::to_string(a.renderer->frameNumber));first=false;}
 if(!capture.empty()){
 auto cost=std::chrono::duration<double,std::milli>(std::chrono::steady_clock::now()-begin).count();SYSTEMTIME utc;GetSystemTime(&utc);std::ofstream meta(fs::path(capture+L".json"));auto cam=a.world.camera(s,local);meta<<"{\n  \"pid\": "<<GetCurrentProcessId()<<",\n  \"session\": \""<<utf8(a.options.session)<<"\",\n  \"frame\": "<<a.renderer->frameNumber<<",\n  \"scene\": "<<s+1<<",\n  \"time\": "<<a.clock<<",\n  \"width\": "<<a.renderer->w()<<",\n  \"height\": "<<a.renderer->h()<<",\n  \"borderless\": "<<(a.fullscreen?"true":"false")<<",\n  \"window_style\": "<<(unsigned long)GetWindowLongPtrW(hwnd,GWL_STYLE)<<",\n  \"startup_to_capture_ms\": "<<a.ms()<<",\n  \"capture_ms\": "<<cost<<",\n  \"utc\": \""<<utc.wYear<<"-"<<utc.wMonth<<"-"<<utc.wDay<<"T"<<utc.wHour<<":"<<utc.wMinute<<":"<<utc.wSecond<<"."<<utc.wMilliseconds<<"Z\",\n  \"camera\": ["<<cam.eye.x<<","<<cam.eye.y<<","<<cam.eye.z<<"],\n  \"source\": \"D3D12 current backbuffer, COPY_SOURCE, direct queue, fence completed, normal Present\"\n}\n";
 a.event("capture complete frame="+std::to_string(a.renderer->frameNumber)+" scene="+std::to_string(s+1)+" cost_ms="+std::to_string(cost)+" file="+utf8(capture));}
 tick++;
 }
 a.audio.update(a.clock,true,true);if(a.fullscreen)a.toggle(false);a.renderer->idle();auto errors=a.renderer->validationErrors();a.event(std::string("D3D12 debug_layer=")+(a.renderer->debugLayer?"enabled":"unavailable/disabled")+" validation_errors="+std::to_string(errors.size()));for(auto&e:errors)a.event("D3D12 ERROR: "+e);if(!errors.empty())throw std::runtime_error("D3D12 validation errors; see run log");a.renderer.reset();DestroyWindow(hwnd);a.event("GPU idle; renderer, swapchain, window and audio cleaned; no persistent configuration modified");
 }catch(const std::exception&e){std::ofstream error("fr08-error.log",std::ios::app);error<<e.what()<<std::endl;OutputDebugStringA(e.what());result=1;}
 CoUninitialize();return result;
}
