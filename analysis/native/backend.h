#pragma once
#include <windows.h>
#include <memory>
#include <cstdint>
#include "../d3d8to9/source/d3d8.hpp"
struct NativeVertex {float p[3],n[3];uint32_t color;float uv[2],uv1[2];};
struct NativeState {D3DMATRIX world,view,projection,texture0,texture1;DWORD rs[256],ts[8][33];D3DVIEWPORT8 viewport;DWORD textures[2];};
class NativeBackend {
 struct Impl;std::unique_ptr<Impl> p;
 public:
 NativeBackend(HWND hwnd,unsigned w,unsigned h,bool debug=false);~NativeBackend();
 void texture(unsigned id,unsigned w,unsigned h,unsigned levels,unsigned fmt,unsigned usage);
 void upload(unsigned id,unsigned level,const void* bytes,unsigned pitch);
 void clear(unsigned flags,unsigned color,float z);
 void draw(const NativeState&,const NativeVertex*,unsigned count,const uint16_t*,unsigned indices);
 void present(const wchar_t* capture=nullptr);
 void resize(unsigned w,unsigned h);unsigned width()const;unsigned height()const;uint64_t frame()const;
};
