#pragma once
#include "../d3d8to9/source/d3d8.hpp"
void seen(const char*);
struct GenIDirect3D8:public IDirect3D8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3D8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3D8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3D8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void *pInitializeFunction) override {seen("IDirect3D8::RegisterSoftwareDevice");return S_OK;}
UINT STDMETHODCALLTYPE GetAdapterCount() override {seen("IDirect3D8::GetAdapterCount");return (UINT)1;}
HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier) override {seen("IDirect3D8::GetAdapterIdentifier");return S_OK;}
UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT Adapter) override {seen("IDirect3D8::GetAdapterModeCount");return (UINT)1;}
HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode) override {seen("IDirect3D8::EnumAdapterModes");return S_OK;}
HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode) override {seen("IDirect3D8::GetAdapterDisplayMode");return S_OK;}
HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed) override {seen("IDirect3D8::CheckDeviceType");return S_OK;}
HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) override {seen("IDirect3D8::CheckDeviceFormat");return S_OK;}
HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) override {seen("IDirect3D8::CheckDeviceMultiSampleType");return S_OK;}
HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) override {seen("IDirect3D8::CheckDepthStencilMatch");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps) override {seen("IDirect3D8::GetDeviceCaps");return S_OK;}
HMONITOR STDMETHODCALLTYPE GetAdapterMonitor(UINT Adapter) override {seen("IDirect3D8::GetAdapterMonitor");return (HMONITOR)1;}
HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DDevice8 **ppReturnedDeviceInterface) override {seen("IDirect3D8::CreateDevice");return S_OK;}
};
struct GenIDirect3DDevice8:public IDirect3DDevice8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DDevice8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DDevice8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DDevice8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE TestCooperativeLevel() override {seen("IDirect3DDevice8::TestCooperativeLevel");return S_OK;}
UINT STDMETHODCALLTYPE GetAvailableTextureMem() override {seen("IDirect3DDevice8::GetAvailableTextureMem");return (UINT)1;}
HRESULT STDMETHODCALLTYPE ResourceManagerDiscardBytes(DWORD Bytes) override {seen("IDirect3DDevice8::ResourceManagerDiscardBytes");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8 **ppD3D8) override {seen("IDirect3DDevice8::GetDirect3D");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8 *pCaps) override {seen("IDirect3DDevice8::GetDeviceCaps");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE *pMode) override {seen("IDirect3DDevice8::GetDisplayMode");return S_OK;}
HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters) override {seen("IDirect3DDevice8::GetCreationParameters");return S_OK;}
HRESULT STDMETHODCALLTYPE SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface8 *pCursorBitmap) override {seen("IDirect3DDevice8::SetCursorProperties");return S_OK;}
void STDMETHODCALLTYPE SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags) override {seen("IDirect3DDevice8::SetCursorPosition");return;}
BOOL STDMETHODCALLTYPE ShowCursor(BOOL bShow) override {seen("IDirect3DDevice8::ShowCursor");return (BOOL)1;}
HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DSwapChain8 **ppSwapChain) override {seen("IDirect3DDevice8::CreateAdditionalSwapChain");return S_OK;}
HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS8 *pPresentationParameters) override {seen("IDirect3DDevice8::Reset");return S_OK;}
HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) override {seen("IDirect3DDevice8::Present");return S_OK;}
HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) override {seen("IDirect3DDevice8::GetBackBuffer");return S_OK;}
HRESULT STDMETHODCALLTYPE GetRasterStatus(D3DRASTER_STATUS *pRasterStatus) override {seen("IDirect3DDevice8::GetRasterStatus");return S_OK;}
void STDMETHODCALLTYPE SetGammaRamp(DWORD Flags, const D3DGAMMARAMP *pRamp) override {seen("IDirect3DDevice8::SetGammaRamp");return;}
void STDMETHODCALLTYPE GetGammaRamp(D3DGAMMARAMP *pRamp) override {seen("IDirect3DDevice8::GetGammaRamp");return;}
HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8 **ppTexture) override {seen("IDirect3DDevice8::CreateTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture8 **ppVolumeTexture) override {seen("IDirect3DDevice8::CreateVolumeTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture8 **ppCubeTexture) override {seen("IDirect3DDevice8::CreateCubeTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8 **ppVertexBuffer) override {seen("IDirect3DDevice8::CreateVertexBuffer");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8 **ppIndexBuffer) override {seen("IDirect3DDevice8::CreateIndexBuffer");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, IDirect3DSurface8 **ppSurface) override {seen("IDirect3DDevice8::CreateRenderTarget");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8 **ppSurface) override {seen("IDirect3DDevice8::CreateDepthStencilSurface");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, IDirect3DSurface8 **ppSurface) override {seen("IDirect3DDevice8::CreateImageSurface");return S_OK;}
HRESULT STDMETHODCALLTYPE CopyRects(IDirect3DSurface8 *pSourceSurface, const RECT *pSourceRectsArray, UINT cRects, IDirect3DSurface8 *pDestinationSurface, const POINT *pDestPointsArray) override {seen("IDirect3DDevice8::CopyRects");return S_OK;}
HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture) override {seen("IDirect3DDevice8::UpdateTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE GetFrontBuffer(IDirect3DSurface8 *pDestSurface) override {seen("IDirect3DDevice8::GetFrontBuffer");return S_OK;}
HRESULT STDMETHODCALLTYPE SetRenderTarget(IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pNewZStencil) override {seen("IDirect3DDevice8::SetRenderTarget");return S_OK;}
HRESULT STDMETHODCALLTYPE GetRenderTarget(IDirect3DSurface8 **ppRenderTarget) override {seen("IDirect3DDevice8::GetRenderTarget");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface) override {seen("IDirect3DDevice8::GetDepthStencilSurface");return S_OK;}
HRESULT STDMETHODCALLTYPE BeginScene() override {seen("IDirect3DDevice8::BeginScene");return S_OK;}
HRESULT STDMETHODCALLTYPE EndScene() override {seen("IDirect3DDevice8::EndScene");return S_OK;}
HRESULT STDMETHODCALLTYPE Clear(DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) override {seen("IDirect3DDevice8::Clear");return S_OK;}
HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) override {seen("IDirect3DDevice8::SetTransform");return S_OK;}
HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix) override {seen("IDirect3DDevice8::GetTransform");return S_OK;}
HRESULT STDMETHODCALLTYPE MultiplyTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) override {seen("IDirect3DDevice8::MultiplyTransform");return S_OK;}
HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT8 *pViewport) override {seen("IDirect3DDevice8::SetViewport");return S_OK;}
HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8 *pViewport) override {seen("IDirect3DDevice8::GetViewport");return S_OK;}
HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL8 *pMaterial) override {seen("IDirect3DDevice8::SetMaterial");return S_OK;}
HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL8 *pMaterial) override {seen("IDirect3DDevice8::GetMaterial");return S_OK;}
HRESULT STDMETHODCALLTYPE SetLight(DWORD Index, const D3DLIGHT8 *pLight) override {seen("IDirect3DDevice8::SetLight");return S_OK;}
HRESULT STDMETHODCALLTYPE GetLight(DWORD Index, D3DLIGHT8 *pLight) override {seen("IDirect3DDevice8::GetLight");return S_OK;}
HRESULT STDMETHODCALLTYPE LightEnable(DWORD Index, BOOL Enable) override {seen("IDirect3DDevice8::LightEnable");return S_OK;}
HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD Index, BOOL *pEnable) override {seen("IDirect3DDevice8::GetLightEnable");return S_OK;}
HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD Index, const float *pPlane) override {seen("IDirect3DDevice8::SetClipPlane");return S_OK;}
HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD Index, float *pPlane) override {seen("IDirect3DDevice8::GetClipPlane");return S_OK;}
HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE State, DWORD Value) override {seen("IDirect3DDevice8::SetRenderState");return S_OK;}
HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue) override {seen("IDirect3DDevice8::GetRenderState");return S_OK;}
HRESULT STDMETHODCALLTYPE BeginStateBlock() override {seen("IDirect3DDevice8::BeginStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE EndStateBlock(DWORD *pToken) override {seen("IDirect3DDevice8::EndStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE ApplyStateBlock(DWORD Token) override {seen("IDirect3DDevice8::ApplyStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE CaptureStateBlock(DWORD Token) override {seen("IDirect3DDevice8::CaptureStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE DeleteStateBlock(DWORD Token) override {seen("IDirect3DDevice8::DeleteStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD *pToken) override {seen("IDirect3DDevice8::CreateStateBlock");return S_OK;}
HRESULT STDMETHODCALLTYPE SetClipStatus(const D3DCLIPSTATUS8 *pClipStatus) override {seen("IDirect3DDevice8::SetClipStatus");return S_OK;}
HRESULT STDMETHODCALLTYPE GetClipStatus(D3DCLIPSTATUS8 *pClipStatus) override {seen("IDirect3DDevice8::GetClipStatus");return S_OK;}
HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, IDirect3DBaseTexture8 **ppTexture) override {seen("IDirect3DDevice8::GetTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture8 *pTexture) override {seen("IDirect3DDevice8::SetTexture");return S_OK;}
HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue) override {seen("IDirect3DDevice8::GetTextureStageState");return S_OK;}
HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) override {seen("IDirect3DDevice8::SetTextureStageState");return S_OK;}
HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD *pNumPasses) override {seen("IDirect3DDevice8::ValidateDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE GetInfo(DWORD DevInfoID, void *pDevInfoStruct, DWORD DevInfoStructSize) override {seen("IDirect3DDevice8::GetInfo");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY *pEntries) override {seen("IDirect3DDevice8::SetPaletteEntries");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries) override {seen("IDirect3DDevice8::GetPaletteEntries");return S_OK;}
HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT PaletteNumber) override {seen("IDirect3DDevice8::SetCurrentTexturePalette");return S_OK;}
HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT *PaletteNumber) override {seen("IDirect3DDevice8::GetCurrentTexturePalette");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) override {seen("IDirect3DDevice8::DrawPrimitive");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount) override {seen("IDirect3DDevice8::DrawIndexedPrimitive");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) override {seen("IDirect3DDevice8::DrawPrimitiveUP");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const void *pIndexData, D3DFORMAT IndexDataFormat, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) override {seen("IDirect3DDevice8::DrawIndexedPrimitiveUP");return S_OK;}
HRESULT STDMETHODCALLTYPE ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer8 *pDestBuffer, DWORD Flags) override {seen("IDirect3DDevice8::ProcessVertices");return S_OK;}
HRESULT STDMETHODCALLTYPE CreateVertexShader(const DWORD *pDeclaration, const DWORD *pFunction, DWORD *pHandle, DWORD Usage) override {seen("IDirect3DDevice8::CreateVertexShader");return S_OK;}
HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD Handle) override {seen("IDirect3DDevice8::SetVertexShader");return S_OK;}
HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD *pHandle) override {seen("IDirect3DDevice8::GetVertexShader");return S_OK;}
HRESULT STDMETHODCALLTYPE DeleteVertexShader(DWORD Handle) override {seen("IDirect3DDevice8::DeleteVertexShader");return S_OK;}
HRESULT STDMETHODCALLTYPE SetVertexShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) override {seen("IDirect3DDevice8::SetVertexShaderConstant");return S_OK;}
HRESULT STDMETHODCALLTYPE GetVertexShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) override {seen("IDirect3DDevice8::GetVertexShaderConstant");return S_OK;}
HRESULT STDMETHODCALLTYPE GetVertexShaderDeclaration(DWORD Handle, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DDevice8::GetVertexShaderDeclaration");return S_OK;}
HRESULT STDMETHODCALLTYPE GetVertexShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DDevice8::GetVertexShaderFunction");return S_OK;}
HRESULT STDMETHODCALLTYPE SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT Stride) override {seen("IDirect3DDevice8::SetStreamSource");return S_OK;}
HRESULT STDMETHODCALLTYPE GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride) override {seen("IDirect3DDevice8::GetStreamSource");return S_OK;}
HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex) override {seen("IDirect3DDevice8::SetIndices");return S_OK;}
HRESULT STDMETHODCALLTYPE GetIndices(IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex) override {seen("IDirect3DDevice8::GetIndices");return S_OK;}
HRESULT STDMETHODCALLTYPE CreatePixelShader(const DWORD *pFunction, DWORD *pHandle) override {seen("IDirect3DDevice8::CreatePixelShader");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPixelShader(DWORD Handle) override {seen("IDirect3DDevice8::SetPixelShader");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPixelShader(DWORD *pHandle) override {seen("IDirect3DDevice8::GetPixelShader");return S_OK;}
HRESULT STDMETHODCALLTYPE DeletePixelShader(DWORD Handle) override {seen("IDirect3DDevice8::DeletePixelShader");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPixelShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) override {seen("IDirect3DDevice8::SetPixelShaderConstant");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPixelShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) override {seen("IDirect3DDevice8::GetPixelShaderConstant");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPixelShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DDevice8::GetPixelShaderFunction");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawRectPatch(UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo) override {seen("IDirect3DDevice8::DrawRectPatch");return S_OK;}
HRESULT STDMETHODCALLTYPE DrawTriPatch(UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo) override {seen("IDirect3DDevice8::DrawTriPatch");return S_OK;}
HRESULT STDMETHODCALLTYPE DeletePatch(UINT Handle) override {seen("IDirect3DDevice8::DeletePatch");return S_OK;}
};
struct GenIDirect3DSwapChain8:public IDirect3DSwapChain8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DSwapChain8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DSwapChain8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DSwapChain8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) override {seen("IDirect3DSwapChain8::Present");return S_OK;}
HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) override {seen("IDirect3DSwapChain8::GetBackBuffer");return S_OK;}
};
struct GenIDirect3DResource8:public IDirect3DResource8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DResource8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DResource8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DResource8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DResource8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DResource8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DResource8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DResource8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DResource8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DResource8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DResource8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DResource8::GetType");return (D3DRESOURCETYPE)1;}
};
struct GenIDirect3DBaseTexture8:public IDirect3DBaseTexture8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DBaseTexture8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DBaseTexture8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DBaseTexture8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DBaseTexture8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DBaseTexture8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DBaseTexture8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DBaseTexture8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DBaseTexture8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DBaseTexture8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DBaseTexture8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DBaseTexture8::GetType");return (D3DRESOURCETYPE)1;}
DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override {seen("IDirect3DBaseTexture8::SetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLOD() override {seen("IDirect3DBaseTexture8::GetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLevelCount() override {seen("IDirect3DBaseTexture8::GetLevelCount");return (DWORD)1;}
};
struct GenIDirect3DTexture8:public IDirect3DTexture8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DTexture8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DTexture8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DTexture8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DTexture8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DTexture8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DTexture8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DTexture8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DTexture8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DTexture8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DTexture8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DTexture8::GetType");return (D3DRESOURCETYPE)1;}
DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override {seen("IDirect3DTexture8::SetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLOD() override {seen("IDirect3DTexture8::GetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLevelCount() override {seen("IDirect3DTexture8::GetLevelCount");return (DWORD)1;}
HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) override {seen("IDirect3DTexture8::GetLevelDesc");return S_OK;}
HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, IDirect3DSurface8 **ppSurfaceLevel) override {seen("IDirect3DTexture8::GetSurfaceLevel");return S_OK;}
HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override {seen("IDirect3DTexture8::LockRect");return S_OK;}
HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level) override {seen("IDirect3DTexture8::UnlockRect");return S_OK;}
HRESULT STDMETHODCALLTYPE AddDirtyRect(const RECT *pDirtyRect) override {seen("IDirect3DTexture8::AddDirtyRect");return S_OK;}
};
struct GenIDirect3DCubeTexture8:public IDirect3DCubeTexture8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DCubeTexture8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DCubeTexture8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DCubeTexture8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DCubeTexture8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DCubeTexture8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DCubeTexture8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DCubeTexture8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DCubeTexture8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DCubeTexture8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DCubeTexture8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DCubeTexture8::GetType");return (D3DRESOURCETYPE)1;}
DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override {seen("IDirect3DCubeTexture8::SetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLOD() override {seen("IDirect3DCubeTexture8::GetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLevelCount() override {seen("IDirect3DCubeTexture8::GetLevelCount");return (DWORD)1;}
HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) override {seen("IDirect3DCubeTexture8::GetLevelDesc");return S_OK;}
HRESULT STDMETHODCALLTYPE GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface8 **ppCubeMapSurface) override {seen("IDirect3DCubeTexture8::GetCubeMapSurface");return S_OK;}
HRESULT STDMETHODCALLTYPE LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override {seen("IDirect3DCubeTexture8::LockRect");return S_OK;}
HRESULT STDMETHODCALLTYPE UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level) override {seen("IDirect3DCubeTexture8::UnlockRect");return S_OK;}
HRESULT STDMETHODCALLTYPE AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect) override {seen("IDirect3DCubeTexture8::AddDirtyRect");return S_OK;}
};
struct GenIDirect3DVolumeTexture8:public IDirect3DVolumeTexture8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DVolumeTexture8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DVolumeTexture8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DVolumeTexture8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DVolumeTexture8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DVolumeTexture8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DVolumeTexture8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DVolumeTexture8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DVolumeTexture8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DVolumeTexture8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DVolumeTexture8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DVolumeTexture8::GetType");return (D3DRESOURCETYPE)1;}
DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override {seen("IDirect3DVolumeTexture8::SetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLOD() override {seen("IDirect3DVolumeTexture8::GetLOD");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetLevelCount() override {seen("IDirect3DVolumeTexture8::GetLevelCount");return (DWORD)1;}
HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DVOLUME_DESC8 *pDesc) override {seen("IDirect3DVolumeTexture8::GetLevelDesc");return S_OK;}
HRESULT STDMETHODCALLTYPE GetVolumeLevel(UINT Level, IDirect3DVolume8 **ppVolumeLevel) override {seen("IDirect3DVolumeTexture8::GetVolumeLevel");return S_OK;}
HRESULT STDMETHODCALLTYPE LockBox(UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) override {seen("IDirect3DVolumeTexture8::LockBox");return S_OK;}
HRESULT STDMETHODCALLTYPE UnlockBox(UINT Level) override {seen("IDirect3DVolumeTexture8::UnlockBox");return S_OK;}
HRESULT STDMETHODCALLTYPE AddDirtyBox(const D3DBOX *pDirtyBox) override {seen("IDirect3DVolumeTexture8::AddDirtyBox");return S_OK;}
};
struct GenIDirect3DSurface8:public IDirect3DSurface8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DSurface8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DSurface8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DSurface8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DSurface8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DSurface8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DSurface8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DSurface8::FreePrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) override {seen("IDirect3DSurface8::GetContainer");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8 *pDesc) override {seen("IDirect3DSurface8::GetDesc");return S_OK;}
HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override {seen("IDirect3DSurface8::LockRect");return S_OK;}
HRESULT STDMETHODCALLTYPE UnlockRect() override {seen("IDirect3DSurface8::UnlockRect");return S_OK;}
};
struct GenIDirect3DVolume8:public IDirect3DVolume8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DVolume8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DVolume8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DVolume8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DVolume8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DVolume8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DVolume8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DVolume8::FreePrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) override {seen("IDirect3DVolume8::GetContainer");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDesc(D3DVOLUME_DESC8 *pDesc) override {seen("IDirect3DVolume8::GetDesc");return S_OK;}
HRESULT STDMETHODCALLTYPE LockBox(D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) override {seen("IDirect3DVolume8::LockBox");return S_OK;}
HRESULT STDMETHODCALLTYPE UnlockBox() override {seen("IDirect3DVolume8::UnlockBox");return S_OK;}
};
struct GenIDirect3DVertexBuffer8:public IDirect3DVertexBuffer8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DVertexBuffer8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DVertexBuffer8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DVertexBuffer8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DVertexBuffer8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DVertexBuffer8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DVertexBuffer8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DVertexBuffer8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DVertexBuffer8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DVertexBuffer8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DVertexBuffer8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DVertexBuffer8::GetType");return (D3DRESOURCETYPE)1;}
HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) override {seen("IDirect3DVertexBuffer8::Lock");return S_OK;}
HRESULT STDMETHODCALLTYPE Unlock() override {seen("IDirect3DVertexBuffer8::Unlock");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC *pDesc) override {seen("IDirect3DVertexBuffer8::GetDesc");return S_OK;}
};
struct GenIDirect3DIndexBuffer8:public IDirect3DIndexBuffer8{
HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override {seen("IDirect3DIndexBuffer8::QueryInterface");*ppv=this;return S_OK;}
ULONG STDMETHODCALLTYPE AddRef() override {seen("IDirect3DIndexBuffer8::AddRef");return (ULONG)1;}
ULONG STDMETHODCALLTYPE Release() override {seen("IDirect3DIndexBuffer8::Release");return (ULONG)1;}
HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override {seen("IDirect3DIndexBuffer8::GetDevice");return S_OK;}
HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override {seen("IDirect3DIndexBuffer8::SetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override {seen("IDirect3DIndexBuffer8::GetPrivateData");return S_OK;}
HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override {seen("IDirect3DIndexBuffer8::FreePrivateData");return S_OK;}
DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override {seen("IDirect3DIndexBuffer8::SetPriority");return (DWORD)1;}
DWORD STDMETHODCALLTYPE GetPriority() override {seen("IDirect3DIndexBuffer8::GetPriority");return (DWORD)1;}
void STDMETHODCALLTYPE PreLoad() override {seen("IDirect3DIndexBuffer8::PreLoad");return;}
D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override {seen("IDirect3DIndexBuffer8::GetType");return (D3DRESOURCETYPE)1;}
HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) override {seen("IDirect3DIndexBuffer8::Lock");return S_OK;}
HRESULT STDMETHODCALLTYPE Unlock() override {seen("IDirect3DIndexBuffer8::Unlock");return S_OK;}
HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC *pDesc) override {seen("IDirect3DIndexBuffer8::GetDesc");return S_OK;}
};