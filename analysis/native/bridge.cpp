// Original FR-08 D3D8 contract recorder. Analysis only: no guessed meshes or textures.
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <intrin.h>
#include <cstdio>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <float.h>
#include "../recorder/generated_interfaces.h"
#include "backend.h"
static NativeBackend* native=nullptr;static volatile LONG nativeMS=5000,nativeClockCalls=0;static bool nativeTest=false;static ULONGLONG processStartTick=0;static HWND nativeWindow=nullptr;static UINT pendingWidth=0,pendingHeight=0;
void resetOriginalTimeline(){auto*base=(BYTE*)GetModuleHandleW(nullptr);const BYTE*sig=base+0x88b7;const BYTE expected[]={0x33,0xd2,0x39,0x15,0x54,0xa4,0x52,0x00};if(memcmp(sig,expected,sizeof(expected))!=0)throw std::runtime_error("Original timeline reset signature mismatch");((void(__cdecl*)())(base+0x88b7))();}
DWORD __cdecl clockForOriginal(){InterlockedIncrement(&nativeClockCalls);return (DWORD)nativeMS;}
void patchOriginalClock(){BYTE*addr=(BYTE*)GetModuleHandleW(nullptr)+0x9ae3;const BYTE expected[]={0x55,0x8b,0xec,0x51,0x53};if(memcmp(addr,expected,5)!=0)throw std::runtime_error("Original clock signature mismatch");DWORD old;VirtualProtect(addr,5,PAGE_EXECUTE_READWRITE,&old);addr[0]=0xe9;*(int32_t*)(addr+1)=(int32_t)((BYTE*)clockForOriginal-(addr+5));DWORD tmp;VirtualProtect(addr,5,old,&tmp);FlushInstructionCache(GetCurrentProcess(),addr,5);}
WNDPROC oldProc=nullptr;static bool nativeFull=false;static RECT savedWindow={};static LONG_PTR savedWindowStyle=0;
void nativeFullscreen(bool on){if(on==nativeFull)return;if(on){GetWindowRect(nativeWindow,&savedWindow);savedWindowStyle=GetWindowLongPtrW(nativeWindow,GWL_STYLE);MONITORINFO mi={sizeof(mi)};GetMonitorInfoW(MonitorFromWindow(nativeWindow,MONITOR_DEFAULTTONEAREST),&mi);SetWindowLongPtrW(nativeWindow,GWL_STYLE,WS_POPUP|WS_VISIBLE);SetWindowPos(nativeWindow,HWND_NOTOPMOST,mi.rcMonitor.left,mi.rcMonitor.top,mi.rcMonitor.right-mi.rcMonitor.left,mi.rcMonitor.bottom-mi.rcMonitor.top,SWP_NOACTIVATE|SWP_FRAMECHANGED);}else{SetWindowLongPtrW(nativeWindow,GWL_STYLE,savedWindowStyle);SetWindowPos(nativeWindow,HWND_NOTOPMOST,savedWindow.left,savedWindow.top,savedWindow.right-savedWindow.left,savedWindow.bottom-savedWindow.top,SWP_NOACTIVATE|SWP_FRAMECHANGED);}nativeFull=on;}
void nativeClient(UINT w,UINT h){if(nativeFull)nativeFullscreen(false);RECT r={0,0,(LONG)w,(LONG)h};AdjustWindowRectExForDpi(&r,(DWORD)GetWindowLongPtrW(nativeWindow,GWL_STYLE),FALSE,0,GetDpiForWindow(nativeWindow));SetWindowPos(nativeWindow,nullptr,0,0,r.right-r.left,r.bottom-r.top,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOZORDER);}

LRESULT CALLBACK nativeProc(HWND h,UINT m,WPARAM w,LPARAM l){if(m==WM_TIMER&&w==0xF808){KillTimer(h,0xF808);ShowWindow(h,SW_SHOWNOACTIVATE);return 0;}if((m==WM_KEYDOWN&&w==VK_F11)||(m==WM_SYSKEYDOWN&&w==VK_RETURN&&(l&(1<<29)))){nativeFullscreen(!nativeFull);return 0;}if(m==WM_GETMINMAXINFO){auto*p=(MINMAXINFO*)l;p->ptMinTrackSize={1,1};p->ptMaxTrackSize={16448,16448};return 0;}if(m==WM_WINDOWPOSCHANGING)return 0;if(m==WM_SIZE&&w!=SIZE_MINIMIZED){pendingWidth=LOWORD(l);pendingHeight=HIWORD(l);}return CallWindowProcW(oldProc,h,m,w,l);}
ULONGLONG originalProcessAge(){FILETIME create,exit,kernel,user,now;GetProcessTimes(GetCurrentProcess(),&create,&exit,&kernel,&user);GetSystemTimePreciseAsFileTime(&now);ULARGE_INTEGER a,b;a.LowPart=create.dwLowDateTime;a.HighPart=create.dwHighDateTime;b.LowPart=now.dwLowDateTime;b.HighPart=now.dwHighDateTime;return (b.QuadPart-a.QuadPart)/10000;}
void openNative(HWND h){processStartTick=GetTickCount64()-originalProcessAge();nativeTest=wcsstr(GetCommandLineW(),L"--native-test")!=nullptr;SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);nativeWindow=h;oldProc=(WNDPROC)SetWindowLongPtrW(h,GWLP_WNDPROC,(LONG_PTR)nativeProc);SetWindowLongPtrW(h,GWL_STYLE,WS_OVERLAPPEDWINDOW|WS_VISIBLE);RECT r={0,0,1280,720};AdjustWindowRectExForDpi(&r,WS_OVERLAPPEDWINDOW,FALSE,0,GetDpiForWindow(h));SetWindowPos(h,HWND_NOTOPMOST,80,80,r.right-r.left,r.bottom-r.top,SWP_FRAMECHANGED|SWP_NOACTIVATE);try{native=new NativeBackend(h,1280,720,true);}catch(const std::exception&e){FILE*f=nullptr;fopen_s(&f,"native-error.log","a");if(f){fprintf(f,"%s\n",e.what());fclose(f);}ExitProcess(2);}pendingWidth=pendingHeight=0;if(nativeTest)patchOriginalClock();}
static FILE* traceFile;static DWORD nextId=1,frameNo=0,startTick=0;static std::unordered_map<void*,DWORD> ids;static std::unordered_set<std::string> calls;
void seen(const char*n){if(calls.insert(n).second){FILE*f=nullptr;fopen_s(&f,"calls.log","a");if(f){fprintf(f,"%s\n",n);fclose(f);}}}
void packet(DWORD op,const void*data,DWORD bytes){if(native)return;if(!traceFile)fopen_s(&traceFile,"trace.d8","wb");if(traceFile){fwrite(&op,4,1,traceFile);fwrite(&bytes,4,1,traceFile);if(bytes)fwrite(data,bytes,1,traceFile);}}
template<class T>void record(DWORD op,const T&v){packet(op,&v,sizeof(v));}
DWORD id(void*p){auto it=ids.find(p);return it==ids.end()?0:it->second;}
void dump(const char*prefix,DWORD uid,UINT level,const void*data,size_t size){if(native)return;char path[128];sprintf_s(path,"%s-%04lu-%02u.bin",prefix,uid,level);FILE*f=nullptr;fopen_s(&f,path,"wb");if(f){fwrite(data,size,1,f);fclose(f);}}
LONG WINAPI fault(EXCEPTION_POINTERS*p){FILE*f=nullptr;fopen_s(&f,"fault.log","w");if(f){auto*c=p->ContextRecord;fprintf(f,"exception=%08lx address=%p eip=%08lx esp=%08lx eax=%08lx ebx=%08lx ecx=%08lx edx=%08lx esi=%08lx edi=%08lx\n",p->ExceptionRecord->ExceptionCode,p->ExceptionRecord->ExceptionAddress,c->Eip,c->Esp,c->Eax,c->Ebx,c->Ecx,c->Edx,c->Esi,c->Edi);for(int i=0;i<24;i++)fprintf(f,"stack[%d]=%08lx\n",i,((DWORD*)c->Esp)[i]);fclose(f);}if(traceFile)fflush(traceFile);return EXCEPTION_EXECUTE_HANDLER;}
void imageDump(){BYTE* base=(BYTE*)GetModuleHandleW(nullptr);auto*dos=(IMAGE_DOS_HEADER*)base;auto*nt=(IMAGE_NT_HEADERS*)(base+dos->e_lfanew);DWORD size=nt->OptionalHeader.SizeOfImage;std::vector<BYTE> data(size);for(DWORD offset=0;offset<size;){MEMORY_BASIC_INFORMATION m={};if(!VirtualQuery(base+offset,&m,sizeof(m)))break;size_t bytes=std::min<size_t>(size_t(size-offset),m.RegionSize-(size_t(base+offset)-size_t(m.BaseAddress)));if(m.State==MEM_COMMIT&&!(m.Protect&(PAGE_NOACCESS|PAGE_GUARD)))memcpy(data.data()+offset,base+offset,bytes);offset+=(DWORD)bytes;}dump("unpacked",0,0,data.data(),data.size());FILE*f=nullptr;fopen_s(&f,"module.log","w");if(f){fprintf(f,"pid=%lu\nbase=%p\nsize=%lu\nDirect3DCreate8_return=%p\n",GetCurrentProcessId(),base,size,_ReturnAddress());fclose(f);}}
void oracleParameters(){static bool done=false;if(done||!nativeTest)return;done=true;BYTE*base=(BYTE*)GetModuleHandleW(nullptr);DWORD nodes=*(DWORD*)(base+0x1282ec),count=0;for(DWORD i=0;i<nodes;i++)count+=base[0x45010+i*12+4];FILE*f=nullptr;fopen_s(&f,"oracle-parameters.bin","wb");if(f){fwrite(base+0xe72e0,4,count,f);fclose(f);}unsigned short cw;__asm { fnstcw cw }fopen_s(&f,"oracle-counts.log","w");if(f){fprintf(f,"nodes=%lu parameters=%lu events=%lu channels=%lu keys=%lu x87_control_word=%04x\n",nodes,count,*(DWORD*)(base+0x12a454),*(DWORD*)(base+0x1272e0),*(DWORD*)(base+0xccad0),cw);fclose(f);}}
void oracleCurves(){static bool done=false;if(done||!nativeTest||!nativeClockCalls)return;done=true;BYTE*base=(BYTE*)GetModuleHandleW(nullptr);DWORD count=*(DWORD*)(base+0xccad0),channels=*(DWORD*)(base+0x1272e0);BYTE*keys=*(BYTE**)(base+0x1282f0);FILE*f=nullptr;fopen_s(&f,"oracle-keys.bin","wb");if(f){fwrite(keys,24,count,f);fclose(f);}fopen_s(&f,"oracle-evaluations.bin","wb");if(f){const float times[]={0,.1f,.333f,.5f,.75f,.9f,1};auto evaluate=(float(__stdcall*)(void*,float))(base+0x87e5);for(DWORD i=0;i<channels;i++)for(float t:times){float value=evaluate(base+0xe4ae0+i*24,t);fwrite(&value,4,1,f);}fclose(f);}}
void caps(D3DCAPS8*p){memset(p,0,sizeof(*p));p->DeviceType=D3DDEVTYPE_HAL;p->Caps=0xffffffff;p->Caps2=0xffffffff;p->DevCaps=0xffffffff;p->TextureCaps=0xffffffff;p->TextureFilterCaps=0xffffffff;p->TextureAddressCaps=0xffffffff;p->TextureOpCaps=0xffffffff;p->SrcBlendCaps=p->DestBlendCaps=p->PrimitiveMiscCaps=p->RasterCaps=0xffffffff;p->MaxTextureWidth=p->MaxTextureHeight=4096;p->MaxTextureRepeat=8192;p->MaxTextureAspectRatio=8192;p->MaxAnisotropy=16;p->MaxActiveLights=8;p->MaxTextureBlendStages=p->MaxSimultaneousTextures=8;p->MaxVertexIndex=0x00ffffff;p->MaxPrimitiveCount=0x00ffffff;p->MaxStreams=16;p->MaxStreamStride=255;p->MaxVertexShaderConst=96;p->MaxPointSize=256;p->VertexShaderVersion=0xfffe0101;p->PixelShaderVersion=0xffff0101;}
struct Surface:GenIDirect3DSurface8{
 DWORD uid,texId=0,texLevel=0;UINT w,h,bpp;D3DFORMAT fmt;std::vector<BYTE> own;std::vector<BYTE>*pixels;
 Surface(UINT W,UINT H,D3DFORMAT F,std::vector<BYTE>*p=nullptr):w(W),h(H),fmt(F){uid=nextId++;ids[this]=uid;bpp=(F==D3DFMT_R5G6B5||F==D3DFMT_A1R5G5B5||F==D3DFMT_X1R5G5B5)?2:4;if(!p)own.resize(size_t(w)*h*bpp);pixels=p?p:&own;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8*p)override{*p={};p->Format=fmt;p->Type=D3DRTYPE_SURFACE;p->Width=w;p->Height=h;p->Size=w*h*bpp;p->Pool=D3DPOOL_SYSTEMMEM;return S_OK;}
 HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT*p,const RECT*r,DWORD)override{p->Pitch=w*bpp;p->pBits=pixels->data()+(r?r->top*w*bpp+r->left*bpp:0);return S_OK;}
 HRESULT STDMETHODCALLTYPE UnlockRect()override{dump("surface",uid,0,pixels->data(),pixels->size());if(native&&texId)native->upload(texId,texLevel,pixels->data(),w*bpp);return S_OK;}
};
struct Texture:GenIDirect3DTexture8{
 DWORD uid;UINT w,h,levels,bpp;D3DFORMAT fmt;std::vector<std::vector<BYTE>> data;std::vector<Surface*> surfaces;
 Texture(UINT W,UINT H,UINT L,D3DFORMAT F,DWORD usage):w(W),h(H),fmt(F){uid=nextId++;ids[this]=uid;bpp=(F==D3DFMT_R5G6B5||F==D3DFMT_A1R5G5B5||F==D3DFMT_X1R5G5B5)?2:4;if(!L){L=1;for(UINT q=std::max(W,H);q>1;q>>=1)L++;}levels=L;data.resize(L);surfaces.resize(L);for(UINT i=0;i<L;i++){UINT x=std::max(1u,w>>i),y=std::max(1u,h>>i);data[i].resize(size_t(x)*y*bpp);surfaces[i]=new Surface(x,y,F,&data[i]);surfaces[i]->texId=uid;surfaces[i]->texLevel=i;}DWORD a[]={uid,w,h,levels,(DWORD)fmt,bpp};packet(1,a,sizeof(a));if(uid==13)oracleParameters();if(native)native->texture(uid,w,h,levels,(UINT)fmt,usage);}
 DWORD STDMETHODCALLTYPE GetLevelCount()override{return levels;}
 D3DRESOURCETYPE STDMETHODCALLTYPE GetType()override{return D3DRTYPE_TEXTURE;}
 HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT l,D3DSURFACE_DESC8*p)override{return l<levels?surfaces[l]->GetDesc(p):D3DERR_INVALIDCALL;}
 HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT l,IDirect3DSurface8**p)override{*p=surfaces[l];return S_OK;}
 HRESULT STDMETHODCALLTYPE LockRect(UINT l,D3DLOCKED_RECT*p,const RECT*r,DWORD f)override{return l<levels?surfaces[l]->LockRect(p,r,f):D3DERR_INVALIDCALL;}
 HRESULT STDMETHODCALLTYPE UnlockRect(UINT l)override{if(l>=levels)return D3DERR_INVALIDCALL;dump("texture",uid,l,data[l].data(),data[l].size());if(native)native->upload(uid,l,data[l].data(),std::max(1u,w>>l)*bpp);return S_OK;}
};
struct VB:GenIDirect3DVertexBuffer8{
 DWORD uid,usage,fvf;std::vector<BYTE> bytes;UINT locks=0;
 VB(UINT n,DWORD u,DWORD f):usage(u),fvf(f){uid=nextId++;ids[this]=uid;bytes.resize(n);DWORD a[]={uid,n,u,f};packet(2,a,sizeof(a));}
 HRESULT STDMETHODCALLTYPE Lock(UINT offset,UINT size,BYTE**p,DWORD)override{if(offset+size>bytes.size())return D3DERR_INVALIDCALL;*p=bytes.data()+offset;return S_OK;}
 HRESULT STDMETHODCALLTYPE Unlock()override{locks++;dump("vertices",uid,0,bytes.data(),bytes.size());return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC*p)override{*p={};p->Format=D3DFMT_VERTEXDATA;p->Type=D3DRTYPE_VERTEXBUFFER;p->Size=(UINT)bytes.size();p->FVF=fvf;p->Usage=usage;p->Pool=D3DPOOL_MANAGED;return S_OK;}
};
struct IB:GenIDirect3DIndexBuffer8{
 DWORD uid,usage;D3DFORMAT format;std::vector<BYTE> bytes;UINT locks=0;
 IB(UINT n,DWORD u,D3DFORMAT f):usage(u),format(f){uid=nextId++;ids[this]=uid;bytes.resize(n);DWORD a[]={uid,n,u,(DWORD)f};packet(3,a,sizeof(a));}
 HRESULT STDMETHODCALLTYPE Lock(UINT offset,UINT size,BYTE**p,DWORD)override{if(offset+size>bytes.size())return D3DERR_INVALIDCALL;*p=bytes.data()+offset;return S_OK;}
 HRESULT STDMETHODCALLTYPE Unlock()override{locks++;dump("indices",uid,0,bytes.data(),bytes.size());return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC*p)override{*p={};p->Format=format;p->Type=D3DRTYPE_INDEXBUFFER;p->Size=(UINT)bytes.size();p->Usage=usage;p->Pool=D3DPOOL_MANAGED;return S_OK;}
};
struct Device:GenIDirect3DDevice8{
 IDirect3D8*owner;Surface*back,*depth;DWORD rs[256]={},ts[8][33]={};D3DMATRIX transforms[512]={};D3DVIEWPORT8 vp={0,0,800,600,0,1};IDirect3DBaseTexture8*textures[8]={};VB*vb=nullptr;IB*ib=nullptr;UINT stride=0,baseVertex=0;DWORD fvf=0;
 Device(IDirect3D8*p,HWND hwnd):owner(p){openNative(hwnd);rs[7]=1;rs[14]=1;rs[19]=2;rs[20]=1;rs[22]=3;rs[23]=4;rs[25]=8;rs[137]=1;rs[141]=1;for(int stage=0;stage<8;stage++){ts[stage][1]=stage?1:4;ts[stage][13]=ts[stage][14]=1;}back=new Surface(800,600,D3DFMT_X8R8G8B8);depth=new Surface(800,600,D3DFMT_D16);startTick=GetTickCount();seen("Recorder::DeviceCreated");}
 HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8**p)override{*p=owner;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8*p)override{caps(p);return S_OK;}
 UINT STDMETHODCALLTYPE GetAvailableTextureMem()override{return 512*1024*1024;}
 HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateTexture(UINT W,UINT H,UINT L,DWORD U,D3DFORMAT F,D3DPOOL P,IDirect3DTexture8**p)override{seen("CreateTexture");*p=new Texture(W,H,L,F,U);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT n,DWORD u,DWORD f,D3DPOOL,IDirect3DVertexBuffer8**p)override{seen("CreateVertexBuffer");*p=new VB(n,u,f);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT n,DWORD u,D3DFORMAT f,D3DPOOL,IDirect3DIndexBuffer8**p)override{seen("CreateIndexBuffer");*p=new IB(n,u,f);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateImageSurface(UINT w,UINT h,D3DFORMAT f,IDirect3DSurface8**p)override{*p=new Surface(w,h,f);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT w,UINT h,D3DFORMAT f,D3DMULTISAMPLE_TYPE,IDirect3DSurface8**p)override{seen("CreateDepthStencilSurface");*p=new Surface(w,h,f);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT w,UINT h,D3DFORMAT f,D3DMULTISAMPLE_TYPE,BOOL,IDirect3DSurface8**p)override{seen("CreateRenderTarget");*p=new Surface(w,h,f);return S_OK;}
 HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT,D3DBACKBUFFER_TYPE,IDirect3DSurface8**p)override{*p=back;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetRenderTarget(IDirect3DSurface8**p)override{*p=back;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface8**p)override{*p=depth;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE s,D3DMATRIX*p)override{*p=transforms[(UINT)s%512];return S_OK;}
 HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE s,const D3DMATRIX*p)override{seen("SetTransform");transforms[(UINT)s%512]=*p;struct{DWORD state;D3DMATRIX m;}a={(DWORD)s,*p};record(10,a);return S_OK;}
 HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT8*p)override{vp=*p;record(11,*p);return S_OK;}
 HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8*p)override{*p=vp;return S_OK;}
 HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE s,DWORD value)override{seen("SetRenderState");rs[(UINT)s%256]=value;DWORD a[]={(DWORD)s,value};packet(12,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE s,DWORD*p)override{*p=rs[(UINT)s%256];return S_OK;}
 HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD stage,D3DTEXTURESTAGESTATETYPE type,DWORD value)override{seen("SetTextureStageState");if(stage<8&&(UINT)type<33)ts[stage][type]=value;DWORD a[]={stage,(DWORD)type,value};packet(13,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD stage,D3DTEXTURESTAGESTATETYPE type,DWORD*p)override{*p=stage<8&&(UINT)type<33?ts[stage][type]:0;return S_OK;}
 HRESULT STDMETHODCALLTYPE SetTexture(DWORD stage,IDirect3DBaseTexture8*t)override{if(stage<8)textures[stage]=t;DWORD a[]={stage,id(t)};packet(14,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE GetTexture(DWORD stage,IDirect3DBaseTexture8**p)override{*p=stage<8?textures[stage]:nullptr;return S_OK;}
 HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD h)override{seen("SetVertexShader");fvf=h;record(15,h);return S_OK;}
 HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD*p)override{*p=fvf;return S_OK;}
 HRESULT STDMETHODCALLTYPE SetStreamSource(UINT s,IDirect3DVertexBuffer8*p,UINT st)override{seen("SetStreamSource");if(s==0){vb=(VB*)p;stride=st;}DWORD a[]={s,id(p),st};packet(16,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer8*p,UINT base)override{seen("SetIndices");ib=(IB*)p;baseVertex=base;DWORD a[]={id(p),base};packet(17,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL8*p)override{seen("SetMaterial");record(18,*p);return S_OK;}
 HRESULT STDMETHODCALLTYPE SetLight(DWORD index,const D3DLIGHT8*p)override{seen("SetLight");struct{DWORD index;D3DLIGHT8 light;}a={index,*p};record(19,a);return S_OK;}
 HRESULT STDMETHODCALLTYPE LightEnable(DWORD index,BOOL enable)override{DWORD a[]={index,(DWORD)enable};packet(20,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE Clear(DWORD n,const D3DRECT*,DWORD flags,D3DCOLOR color,float z,DWORD stencil)override{struct{DWORD flags,color;float z;DWORD stencil;}a={flags,color,z,stencil};record(21,a);if(native)native->clear(flags,color,z);return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE type,UINT min,UINT count,UINT first,UINT primitives)override{
 if(native){if(type!=D3DPT_TRIANGLELIST||!vb||!ib||ib->format!=D3DFMT_INDEX16||(fvf!=0x152&&fvf!=0x2c2))throw std::runtime_error("Unsupported original draw format, not approximated");
 if(UINT64(baseVertex+min+count)*stride>vb->bytes.size()||UINT64(first+primitives*3)*2>ib->bytes.size())throw std::runtime_error("Original draw exceeds locked resource");
 std::vector<NativeVertex> verts(count);for(UINT j=0;j<count;j++){const BYTE*src=vb->bytes.data()+SIZE_T(baseVertex+min+j)*stride;auto&v=verts[j];memcpy(v.p,src,12);if(fvf==0x152){memcpy(v.n,src+12,12);memcpy(&v.color,src+24,4);memcpy(v.uv,src+28,8);memcpy(v.uv1,v.uv,8);}else{v.n[0]=v.n[1]=0;v.n[2]=1;memcpy(&v.color,src+12,4);memcpy(v.uv,src+20,8);memcpy(v.uv1,src+28,8);}}
 std::vector<uint16_t> ix(primitives*3);auto*src=(const uint16_t*)ib->bytes.data()+first;for(UINT j=0;j<primitives*3;j++){if(src[j]<min||src[j]>=min+count)throw std::runtime_error("Original index outside MinIndex range");ix[j]=(uint16_t)(src[j]-min);}
 NativeState st={};st.world=transforms[256];st.view=transforms[2];st.projection=transforms[3];st.texture0=transforms[16];st.texture1=transforms[17];memcpy(st.rs,rs,sizeof(rs));memcpy(st.ts,ts,sizeof(ts));st.viewport=vp;st.textures[0]=id(textures[0]);st.textures[1]=id(textures[1]);native->draw(st,verts.data(),count,ix.data(),(UINT)ix.size());}
seen("DrawIndexedPrimitive");DWORD a[]={(DWORD)type,min,count,first,primitives,id(vb),id(ib),baseVertex,stride,fvf};packet(30,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE type,UINT first,UINT count)override{seen("DrawPrimitive");DWORD a[]={(DWORD)type,first,count,id(vb),stride,fvf};packet(31,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE type,UINT count,const void*data,UINT st)override{seen("DrawPrimitiveUP");DWORD a[]={(DWORD)type,count,st,fvf};packet(32,a,sizeof(a));UINT vertices=type==D3DPT_TRIANGLELIST?count*3:type==D3DPT_LINELIST?count*2:count+2;packet(33,data,vertices*st);return S_OK;}
 HRESULT STDMETHODCALLTYPE Present(const RECT*,const RECT*,HWND,const RGNDATA*)override{oracleCurves();
 struct TestStep{LONG time;UINT w,h;int action;const wchar_t*name;};
 static const TestStep steps[]={
 {5000,1280,720,0,L"native-005000"},{25000,1280,720,0,L"native-025000"},{60000,1280,720,0,L"native-060000"},{98000,1280,720,0,L"native-098000"},{120000,1280,720,0,L"native-120000"},{180000,1280,720,0,L"native-180000"},{240000,1280,720,0,L"native-240000"},{300000,1280,720,0,L"native-300000"},
 {5000,913,517,0,L"native-odd"},{5000,517,913,0,L"native-portrait"},{5000,1600,500,0,L"native-ultrawide"},{5000,127,83,0,L"native-tiny"},{5000,1,1,0,L"native-minimum"},{5000,1920,1080,0,L"native-hd"},{5000,3840,2160,0,L"native-uhd"},{5000,1280,720,0,L"native-base"},
 {5000,0,0,1,L"native-borderless"},{5000,0,0,2,L"native-restored"},{5000,0,0,3,L"native-repeat-restore"},{5000,0,0,4,L"native-minimize-restore"}};
 static unsigned stage=0,stable=0;static ULONGLONG start=GetTickCount64();std::wstring capture;
 if(nativeClockCalls&&nativeTest&&++stable==16)capture=std::wstring(steps[stage].name)+L".png";
 ULONGLONG before=GetTickCount64();native->present(capture.empty()?nullptr:capture.c_str());frameNo++;
 if(!capture.empty()){
 wchar_t jsonName[128];swprintf_s(jsonName,L"%s.json",steps[stage].name);FILE*f=nullptr;_wfopen_s(&f,jsonName,L"w");
 wchar_t session[128]=L"unknown";const wchar_t*arg=wcsstr(GetCommandLineW(),L"--session ");if(arg){arg+=10;UINT i=0;while(arg[i]&&arg[i]!=L' '&&arg[i]!=L'"'&&i<127){session[i]=arg[i];i++;}session[i]=0;}char sessionA[128];WideCharToMultiByte(CP_UTF8,0,session,-1,sessionA,128,nullptr,nullptr);SYSTEMTIME utc;GetSystemTime(&utc);
 if(f){fprintf(f,"{\"pid\":%lu,\"session\":\"%s\",\"frame\":%llu,\"original_time_ms\":%ld,\"clock_calls\":%ld,\"width\":%u,\"height\":%u,\"borderless\":%s,\"window_style\":%lu,\"startup_to_target_capture_ms\":%llu,\"capture_ms\":%llu,\"utc\":\"%04u-%02u-%02uT%02u:%02u:%02u.%03uZ\",\"source\":\"Original x86 engine, original D3D8 locked buffers/textures/state, direct D3D12 GPU backbuffer readback\"}\n",GetCurrentProcessId(),sessionA,native->frame(),steps[stage].time,nativeClockCalls,native->width(),native->height(),nativeFull?"true":"false",(DWORD)GetWindowLongPtrW(nativeWindow,GWL_STYLE),GetTickCount64()-processStartTick,GetTickCount64()-before,utc.wYear,utc.wMonth,utc.wDay,utc.wHour,utc.wMinute,utc.wSecond,utc.wMilliseconds);fclose(f);}
 stable=0;if(++stage==sizeof(steps)/sizeof(steps[0])){if(nativeFull)nativeFullscreen(false);delete native;native=nullptr;ExitProcess(0);}LONG previousTime=InterlockedExchange(&nativeMS,steps[stage].time);if(steps[stage].time<previousTime)resetOriginalTimeline();auto&s=steps[stage];
 if(s.action==0)nativeClient(s.w,s.h);else if(s.action==1)nativeFullscreen(true);else if(s.action==2)nativeFullscreen(false);else if(s.action==3){nativeFullscreen(true);nativeFullscreen(false);nativeFullscreen(true);nativeFullscreen(false);}else if(s.action==4){ShowWindow(nativeWindow,SW_MINIMIZE);SetTimer(nativeWindow,0xF808,200,nullptr);}
 }
 if(pendingWidth&&pendingHeight){native->resize(pendingWidth,pendingHeight);pendingWidth=pendingHeight=0;}return S_OK;}

};
struct D3D:GenIDirect3D8{
 UINT STDMETHODCALLTYPE GetAdapterCount()override{return 1;}
 UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT)override{return 1;}
 HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT,UINT,D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT,D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT,DWORD,D3DADAPTER_IDENTIFIER8*p)override{memset(p,0,sizeof(*p));strcpy_s(p->Description,"FR08 original API recorder");return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT,D3DDEVTYPE,D3DCAPS8*p)override{caps(p);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateDevice(UINT,D3DDEVTYPE,HWND h,DWORD flags,D3DPRESENT_PARAMETERS8*pp,IDirect3DDevice8**p)override{record(50,*pp);*p=new Device(this,h);if(!(flags&D3DCREATE_FPU_PRESERVE))_controlfp(_PC_24|_RC_NEAR|_MCW_EM,_MCW_PC|_MCW_RC|_MCW_EM);return S_OK;}
};
extern "C" __declspec(dllexport) IDirect3D8* WINAPI Direct3DCreate8(UINT sdk){seen("Direct3DCreate8");SetUnhandledExceptionFilter(fault);imageDump();record(0,sdk);return new D3D;}
BOOL WINAPI DllMain(HINSTANCE,DWORD reason,void*){if(reason==DLL_PROCESS_ATTACH)SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);return TRUE;}