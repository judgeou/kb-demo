#include <windows.h>
#include <d3d9.h>
#include <d3d12.h>
#include <d3d9on12.h>
extern "C" IDirect3D9* WINAPI ForwardCreate9(UINT sdk){
 wchar_t path[MAX_PATH];GetSystemDirectoryW(path,MAX_PATH);wcscat_s(path,L"\\d3d9.dll");auto m=LoadLibraryW(path);
 auto f=(IDirect3D9*(WINAPI*)(UINT,D3D9ON12_ARGS*,UINT))GetProcAddress(m,"Direct3DCreate9On12");
 D3D9ON12_ARGS a={};a.Enable9On12=TRUE;return f?f(sdk,&a,1):nullptr;
}
