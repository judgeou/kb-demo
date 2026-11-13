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
#include "generated_interfaces.h"
static FILE* traceFile;static DWORD nextId=1,frameNo=0,startTick=0;static std::unordered_map<void*,DWORD> ids;static std::unordered_set<std::string> calls;
void seen(const char*n){if(calls.insert(n).second){FILE*f=nullptr;fopen_s(&f,"calls.log","a");if(f){fprintf(f,"%s\n",n);fclose(f);}}}
void packet(DWORD op,const void*data,DWORD bytes){if(!traceFile)fopen_s(&traceFile,"trace.d8","wb");if(traceFile){fwrite(&op,4,1,traceFile);fwrite(&bytes,4,1,traceFile);if(bytes)fwrite(data,bytes,1,traceFile);}}
template<class T>void record(DWORD op,const T&v){packet(op,&v,sizeof(v));}
DWORD id(void*p){auto it=ids.find(p);return it==ids.end()?0:it->second;}
void dump(const char*prefix,DWORD uid,UINT level,const void*data,size_t size){char path[128];sprintf_s(path,"%s-%04lu-%02u.bin",prefix,uid,level);FILE*f=nullptr;fopen_s(&f,path,"wb");if(f){fwrite(data,size,1,f);fclose(f);}}
LONG WINAPI fault(EXCEPTION_POINTERS*p){FILE*f=nullptr;fopen_s(&f,"fault.log","w");if(f){auto*c=p->ContextRecord;fprintf(f,"exception=%08lx address=%p eip=%08lx esp=%08lx eax=%08lx ebx=%08lx ecx=%08lx edx=%08lx esi=%08lx edi=%08lx\n",p->ExceptionRecord->ExceptionCode,p->ExceptionRecord->ExceptionAddress,c->Eip,c->Esp,c->Eax,c->Ebx,c->Ecx,c->Edx,c->Esi,c->Edi);for(int i=0;i<24;i++)fprintf(f,"stack[%d]=%08lx\n",i,((DWORD*)c->Esp)[i]);fclose(f);}if(traceFile)fflush(traceFile);return EXCEPTION_EXECUTE_HANDLER;}
void imageDump(){BYTE* base=(BYTE*)GetModuleHandleW(nullptr);auto*dos=(IMAGE_DOS_HEADER*)base;auto*nt=(IMAGE_NT_HEADERS*)(base+dos->e_lfanew);DWORD size=nt->OptionalHeader.SizeOfImage;std::vector<BYTE> data(size);for(DWORD offset=0;offset<size;){MEMORY_BASIC_INFORMATION m={};if(!VirtualQuery(base+offset,&m,sizeof(m)))break;size_t bytes=std::min<size_t>(size_t(size-offset),m.RegionSize-(size_t(base+offset)-size_t(m.BaseAddress)));if(m.State==MEM_COMMIT&&!(m.Protect&(PAGE_NOACCESS|PAGE_GUARD)))memcpy(data.data()+offset,base+offset,bytes);offset+=(DWORD)bytes;}dump("unpacked",0,0,data.data(),data.size());FILE*f=nullptr;fopen_s(&f,"module.log","w");if(f){fprintf(f,"pid=%lu\nbase=%p\nsize=%lu\nDirect3DCreate8_return=%p\n",GetCurrentProcessId(),base,size,_ReturnAddress());fclose(f);}}
void caps(D3DCAPS8*p){memset(p,0,sizeof(*p));p->DeviceType=D3DDEVTYPE_HAL;p->Caps=0xffffffff;p->Caps2=0xffffffff;p->DevCaps=0xffffffff;p->TextureCaps=0xffffffff;p->TextureFilterCaps=0xffffffff;p->TextureAddressCaps=0xffffffff;p->TextureOpCaps=0xffffffff;p->SrcBlendCaps=p->DestBlendCaps=p->PrimitiveMiscCaps=p->RasterCaps=0xffffffff;p->MaxTextureWidth=p->MaxTextureHeight=4096;p->MaxTextureRepeat=8192;p->MaxTextureAspectRatio=8192;p->MaxAnisotropy=16;p->MaxActiveLights=8;p->MaxTextureBlendStages=p->MaxSimultaneousTextures=8;p->MaxVertexIndex=0x00ffffff;p->MaxPrimitiveCount=0x00ffffff;p->MaxStreams=16;p->MaxStreamStride=255;p->MaxVertexShaderConst=96;p->MaxPointSize=256;p->VertexShaderVersion=0xfffe0101;p->PixelShaderVersion=0xffff0101;}
struct Surface:GenIDirect3DSurface8{
 DWORD uid;UINT w,h,bpp;D3DFORMAT fmt;std::vector<BYTE> own;std::vector<BYTE>*pixels;
 Surface(UINT W,UINT H,D3DFORMAT F,std::vector<BYTE>*p=nullptr):w(W),h(H),fmt(F){uid=nextId++;ids[this]=uid;bpp=(F==D3DFMT_R5G6B5||F==D3DFMT_A1R5G5B5||F==D3DFMT_X1R5G5B5)?2:4;if(!p)own.resize(size_t(w)*h*bpp);pixels=p?p:&own;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8*p)override{*p={};p->Format=fmt;p->Type=D3DRTYPE_SURFACE;p->Width=w;p->Height=h;p->Size=w*h*bpp;p->Pool=D3DPOOL_SYSTEMMEM;return S_OK;}
 HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT*p,const RECT*r,DWORD)override{p->Pitch=w*bpp;p->pBits=pixels->data()+(r?r->top*w*bpp+r->left*bpp:0);return S_OK;}
 HRESULT STDMETHODCALLTYPE UnlockRect()override{dump("surface",uid,0,pixels->data(),pixels->size());return S_OK;}
};
struct Texture:GenIDirect3DTexture8{
 DWORD uid;UINT w,h,levels,bpp;D3DFORMAT fmt;std::vector<std::vector<BYTE>> data;std::vector<Surface*> surfaces;
 Texture(UINT W,UINT H,UINT L,D3DFORMAT F):w(W),h(H),fmt(F){uid=nextId++;ids[this]=uid;bpp=(F==D3DFMT_R5G6B5||F==D3DFMT_A1R5G5B5||F==D3DFMT_X1R5G5B5)?2:4;if(!L){L=1;for(UINT q=std::max(W,H);q>1;q>>=1)L++;}levels=L;data.resize(L);surfaces.resize(L);for(UINT i=0;i<L;i++){UINT x=std::max(1u,w>>i),y=std::max(1u,h>>i);data[i].resize(size_t(x)*y*bpp);surfaces[i]=new Surface(x,y,F,&data[i]);}DWORD a[]={uid,w,h,levels,(DWORD)fmt,bpp};packet(1,a,sizeof(a));}
 DWORD STDMETHODCALLTYPE GetLevelCount()override{return levels;}
 D3DRESOURCETYPE STDMETHODCALLTYPE GetType()override{return D3DRTYPE_TEXTURE;}
 HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT l,D3DSURFACE_DESC8*p)override{return l<levels?surfaces[l]->GetDesc(p):D3DERR_INVALIDCALL;}
 HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT l,IDirect3DSurface8**p)override{*p=surfaces[l];return S_OK;}
 HRESULT STDMETHODCALLTYPE LockRect(UINT l,D3DLOCKED_RECT*p,const RECT*r,DWORD f)override{return l<levels?surfaces[l]->LockRect(p,r,f):D3DERR_INVALIDCALL;}
 HRESULT STDMETHODCALLTYPE UnlockRect(UINT l)override{if(l>=levels)return D3DERR_INVALIDCALL;dump("texture",uid,l,data[l].data(),data[l].size());return S_OK;}
};
struct VB:GenIDirect3DVertexBuffer8{
 DWORD uid,usage,fvf;std::vector<BYTE> bytes;UINT locks=0;
 VB(UINT n,DWORD u,DWORD f):usage(u),fvf(f){uid=nextId++;ids[this]=uid;bytes.resize(n);DWORD a[]={uid,n,u,f};packet(2,a,sizeof(a));}
 HRESULT STDMETHODCALLTYPE Lock(UINT offset,UINT size,BYTE**p,DWORD)override{if(offset+size>bytes.size())return D3DERR_INVALIDCALL;*p=bytes.data()+offset;return S_OK;}
 HRESULT STDMETHODCALLTYPE Unlock()override{if(locks++==0)dump("vertices",uid,0,bytes.data(),bytes.size());return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC*p)override{*p={};p->Format=D3DFMT_VERTEXDATA;p->Type=D3DRTYPE_VERTEXBUFFER;p->Size=(UINT)bytes.size();p->FVF=fvf;p->Usage=usage;p->Pool=D3DPOOL_MANAGED;return S_OK;}
};
struct IB:GenIDirect3DIndexBuffer8{
 DWORD uid,usage;D3DFORMAT format;std::vector<BYTE> bytes;UINT locks=0;
 IB(UINT n,DWORD u,D3DFORMAT f):usage(u),format(f){uid=nextId++;ids[this]=uid;bytes.resize(n);DWORD a[]={uid,n,u,(DWORD)f};packet(3,a,sizeof(a));}
 HRESULT STDMETHODCALLTYPE Lock(UINT offset,UINT size,BYTE**p,DWORD)override{if(offset+size>bytes.size())return D3DERR_INVALIDCALL;*p=bytes.data()+offset;return S_OK;}
 HRESULT STDMETHODCALLTYPE Unlock()override{if(locks++==0)dump("indices",uid,0,bytes.data(),bytes.size());return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC*p)override{*p={};p->Format=format;p->Type=D3DRTYPE_INDEXBUFFER;p->Size=(UINT)bytes.size();p->Usage=usage;p->Pool=D3DPOOL_MANAGED;return S_OK;}
};
struct Device:GenIDirect3DDevice8{
 IDirect3D8*owner;Surface*back,*depth;DWORD rs[256]={},ts[8][33]={};D3DMATRIX transforms[512]={};D3DVIEWPORT8 vp={0,0,800,600,0,1};IDirect3DBaseTexture8*textures[8]={};VB*vb=nullptr;IB*ib=nullptr;UINT stride=0,baseVertex=0;DWORD fvf=0;
 Device(IDirect3D8*p):owner(p){back=new Surface(800,600,D3DFMT_X8R8G8B8);depth=new Surface(800,600,D3DFMT_D16);startTick=GetTickCount();seen("Recorder::DeviceCreated");}
 HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8**p)override{*p=owner;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8*p)override{caps(p);return S_OK;}
 UINT STDMETHODCALLTYPE GetAvailableTextureMem()override{return 512*1024*1024;}
 HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateTexture(UINT W,UINT H,UINT L,DWORD U,D3DFORMAT F,D3DPOOL P,IDirect3DTexture8**p)override{seen("CreateTexture");*p=new Texture(W,H,L,F);return S_OK;}
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
 HRESULT STDMETHODCALLTYPE Clear(DWORD n,const D3DRECT*,DWORD flags,D3DCOLOR color,float z,DWORD stencil)override{struct{DWORD flags,color;float z;DWORD stencil;}a={flags,color,z,stencil};record(21,a);return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE type,UINT min,UINT count,UINT first,UINT primitives)override{seen("DrawIndexedPrimitive");DWORD a[]={(DWORD)type,min,count,first,primitives,id(vb),id(ib),baseVertex,stride,fvf};packet(30,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE type,UINT first,UINT count)override{seen("DrawPrimitive");DWORD a[]={(DWORD)type,first,count,id(vb),stride,fvf};packet(31,a,sizeof(a));return S_OK;}
 HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE type,UINT count,const void*data,UINT st)override{seen("DrawPrimitiveUP");DWORD a[]={(DWORD)type,count,st,fvf};packet(32,a,sizeof(a));UINT vertices=type==D3DPT_TRIANGLELIST?count*3:type==D3DPT_LINELIST?count*2:count+2;packet(33,data,vertices*st);return S_OK;}
 HRESULT STDMETHODCALLTYPE Present(const RECT*,const RECT*,HWND,const RGNDATA*)override{DWORD a[]={frameNo++,GetTickCount()-startTick};packet(40,a,sizeof(a));if(traceFile)fflush(traceFile);Sleep(16);if(frameNo>=600||GetTickCount()-startTick>30000)ExitProcess(0);return S_OK;}
};
struct D3D:GenIDirect3D8{
 UINT STDMETHODCALLTYPE GetAdapterCount()override{return 1;}
 UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT)override{return 1;}
 HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT,UINT,D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT,D3DDISPLAYMODE*p)override{*p={800,600,60,D3DFMT_X8R8G8B8};return S_OK;}
 HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT,DWORD,D3DADAPTER_IDENTIFIER8*p)override{memset(p,0,sizeof(*p));strcpy_s(p->Description,"FR08 original API recorder");return S_OK;}
 HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT,D3DDEVTYPE,D3DCAPS8*p)override{caps(p);return S_OK;}
 HRESULT STDMETHODCALLTYPE CreateDevice(UINT,D3DDEVTYPE,HWND h,DWORD,D3DPRESENT_PARAMETERS8*pp,IDirect3DDevice8**p)override{record(50,*pp);*p=new Device(this);return S_OK;}
};
extern "C" __declspec(dllexport) IDirect3D8* WINAPI Direct3DCreate8(UINT sdk){seen("Direct3DCreate8");SetUnhandledExceptionFilter(fault);imageDump();record(0,sdk);return new D3D;}
BOOL WINAPI DllMain(HINSTANCE,DWORD,void*){return TRUE;}
