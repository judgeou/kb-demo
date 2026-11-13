// Reference-only D3D8 backbuffer recorder. Not linked into the remake.
#include <windows.h>
#include <cstdio>
#include <cstring>
struct PP {UINT width,height,format,count,multisample,swap;HWND hwnd;BOOL windowed,depth;UINT depthFormat,flags,refresh,interval;};
struct Desc{DWORD format,type,usage,pool,size,multisample,width,height;};
struct Lock {int pitch; void* bits;};
using Create=HRESULT(WINAPI*)(void*,UINT,UINT,HWND,DWORD,PP*,void**);
using Present=HRESULT(WINAPI*)(void*,const RECT*,const RECT*,HWND,const void*);
Create realCreate;Present realPresent;DWORD start;int next=0;int times[]={3,18,35,50,65,80,95,110,125,140,155,170,185,200,215,230,245,260,280,310,340};
void hook(void**vt,int i,void*fn,void**old){DWORD p;VirtualProtect(vt+i,sizeof(void*),PAGE_EXECUTE_READWRITE,&p);*old=vt[i];vt[i]=fn;VirtualProtect(vt+i,sizeof(void*),p,&p);}
HRESULT WINAPI present(void*d,const RECT*a,const RECT*b,HWND w,const void*r){
 DWORD sec=(GetTickCount()-start)/1000;
 if(next<sizeof(times)/sizeof(times[0])&&sec>=(DWORD)times[next]){
  void*s=nullptr;void**vt=*(void***)d;
  if(SUCCEEDED(((HRESULT(WINAPI*)(void*,UINT,UINT,void**))vt[16])(d,0,0,&s))&&s){
   void**sv=*(void***)s;Desc desc={};Lock l={};((HRESULT(WINAPI*)(void*,Desc*))sv[8])(s,&desc);
   if(SUCCEEDED(((HRESULT(WINAPI*)(void*,Lock*,const RECT*,DWORD))sv[9])(s,&l,nullptr,0x10))){
    char name[128];sprintf_s(name,"ref-%03u.bmp",sec);FILE*f=nullptr;fopen_s(&f,name,"wb");
    if(f){BITMAPFILEHEADER h={};BITMAPINFOHEADER bi={};h.bfType=0x4d42;h.bfOffBits=sizeof(h)+sizeof(bi);h.bfSize=h.bfOffBits+desc.width*desc.height*4;bi.biSize=sizeof(bi);bi.biWidth=desc.width;bi.biHeight=-(int)desc.height;bi.biPlanes=1;bi.biBitCount=32;bi.biCompression=BI_RGB;fwrite(&h,sizeof(h),1,f);fwrite(&bi,sizeof(bi),1,f);for(UINT y=0;y<desc.height;y++)fwrite((char*)l.bits+y*l.pitch,desc.width*4,1,f);fclose(f);}
    ((HRESULT(WINAPI*)(void*))sv[10])(s);
   }((ULONG(WINAPI*)(void*))sv[2])(s);
  }next++;
 }
 return realPresent(d,a,b,w,r);
}
HRESULT WINAPI create(void*t,UINT adapter,UINT type,HWND h,DWORD flags,PP*p,void**d){
 p->width=800;p->height=600;p->format=22;p->windowed=TRUE;p->flags|=1;p->refresh=0;p->interval=0;p->swap=1;
 HRESULT hr=realCreate(t,adapter,type,h,flags,p,d); FILE* log=nullptr;fopen_s(&log,"device.log","a");if(log){fprintf(log,"CreateDevice hr=%08lx type=%u flags=%lu size=%u,%u depth=%u\n",hr,type,flags,p->width,p->height,p->depthFormat);fclose(log);}if(SUCCEEDED(hr)){start=GetTickCount();hook(*(void***)*d,15,(void*)present,(void**)&realPresent);}return hr;
}
extern "C" __declspec(dllexport) void* WINAPI Direct3DCreate8(UINT sdk){
 wchar_t path[MAX_PATH];GetModuleFileNameW(nullptr,path,MAX_PATH);wchar_t* slash=wcsrchr(path,L'\\');if(slash)slash[1]=0;wcscat_s(path,L"d3d8to9.dll");HMODULE m=LoadLibraryW(path);if(!m)return nullptr;
 auto f=(void*(WINAPI*)(UINT))GetProcAddress(m,"Direct3DCreate8");void*d=f(sdk);if(d)hook(*(void***)d,15,(void*)create,(void**)&realCreate);return d;
}
BOOL WINAPI DllMain(HINSTANCE,DWORD,void*){return TRUE;}
