#pragma once
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <string>
#include <vector>
#include <array>
#include <memory>
#include <fstream>
#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using Microsoft::WRL::ComPtr;
using namespace DirectX;
inline void check(HRESULT hr,const char* what){if(FAILED(hr)){char b[256];sprintf_s(b,"%s (HRESULT 0x%08X)",what,(unsigned)hr);throw std::runtime_error(b);}}
struct Vertex {XMFLOAT3 p,n;XMFLOAT2 uv;XMFLOAT4 color;};
struct Range {UINT first=0,count=0;};
struct Object {Range mesh;XMFLOAT4X4 world;XMFLOAT4 tint={1,1,1,1};int material=0;int motion=0;float seed=0;};
struct Scene {std::string name;std::vector<Object> objects;XMFLOAT3 fog={.02f,.04f,.06f};float density=.015f;};
struct Camera {XMFLOAT3 eye,target;float fov=1.0f;};
struct World {
 std::vector<Vertex> vertices;std::array<Scene,8> scenes;
 Range cube,sphere,cylinder,cone,torus,plane,arch,gear,knot;
 void build();Camera camera(int scene,float t)const;
 XMMATRIX transform(const Object&o,float t)const;
};
struct FrameData {XMFLOAT4X4 vp;XMFLOAT4 eyeTime,fogDensity,light,screen;};
struct ObjectData {XMFLOAT4X4 world,normalWorld;XMFLOAT4 tint;XMFLOAT4 params;};
struct Options {int width=1280,height=720,scene=-1;float time=0;bool fullscreen=false,muted=false,warp=false,test=false,debug=false;std::wstring session=L"interactive",out=L"captures",script;};
class Renderer {
 static constexpr UINT N=3;HWND hwnd{};UINT width{},height{},index{},rtvSize{};bool warp{};
 ComPtr<IDXGIFactory6> factory;ComPtr<ID3D12Device> device;ComPtr<ID3D12CommandQueue> queue;ComPtr<IDXGISwapChain3> swap;
 ComPtr<ID3D12DescriptorHeap> rtvHeap,dsvHeap,srvHeap;ComPtr<ID3D12Resource> targets[N],depth,sceneTarget,atlas,vertexBuffer,overlayBuffer,constants;
 ComPtr<ID3D12CommandAllocator> alloc[N];ComPtr<ID3D12GraphicsCommandList> list;ComPtr<ID3D12Fence> fence;HANDLE event{};UINT64 serial=0,frameFence[N]={};
 ComPtr<ID3D12RootSignature> root;ComPtr<ID3D12PipelineState> meshPSO,skyPSO,postPSO,textPSO;
 FrameData* mapped{};Vertex* overlayMapped{};D3D12_VERTEX_BUFFER_VIEW meshView{},overlayView{};std::vector<Vertex> overlay;
 D3D12_CPU_DESCRIPTOR_HANDLE rtv(UINT i)const;void sizeResources();void makePipelines();void makeAtlas();
 void wait(UINT64 value);void barrier(ID3D12Resource*,D3D12_RESOURCE_STATES,D3D12_RESOURCE_STATES);
 public:
 std::string adapterName;UINT64 frameNumber=0;double initMs=0;bool debugLayer=false;
 std::vector<std::string> validationErrors()const;
 Renderer(HWND w,UINT width,UINT height,bool forceWarp,bool debug,const World&world);~Renderer();
 void idle();void resize(UINT w,UINT h);void text(float x,float y,float height,const std::string&s,XMFLOAT4 color={1,1,1,1});
 void render(const World&,int scene,float t,bool hud,bool paused,float total,bool fullscreen,const std::wstring&capture=L"");
 UINT w()const{return width;}UINT h()const{return height;}
};
class Audio {
 struct Impl;std::unique_ptr<Impl> p;
 public: Audio();~Audio();void update(float seconds,bool paused,bool mute);void seek(float seconds);
};
inline constexpr float Duration=440;
inline constexpr float SceneStarts[]={0,18,50,92,112,156,216,280,440};
inline int sceneAt(float t){for(int i=0;i<8;i++)if(t<SceneStarts[i+1])return i;return 7;}
inline float sceneLocal(float t,int scene){return t-SceneStarts[scene];}
