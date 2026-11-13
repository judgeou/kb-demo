// Silent, process-local DirectSound sink. Never calls the real audio device.
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define DIRECTSOUND_VERSION 0x0800
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
struct Buffer:IDirectSoundBuffer{
 LONG refs=1;std::vector<BYTE> data;WAVEFORMATEX fmt={WAVE_FORMAT_PCM,2,44100,176400,4,16,0};DWORD start=0,position=0,flags=0,number=0;bool playing=false;LONG volume=0,pan=0;
 Buffer(const DSBUFFERDESC*d){static DWORD next=0;number=next++;if(d->lpwfxFormat)fmt=*d->lpwfxFormat;data.resize(std::max<DWORD>(4096,d->dwBufferBytes));flags=d->dwFlags;FILE*f=nullptr;fopen_s(&f,"audio-sink.log","a");if(f){fprintf(f,"buffer=%lu bytes=%zu rate=%lu channels=%u bits=%u flags=%08lx\n",number,data.size(),fmt.nSamplesPerSec,fmt.nChannels,fmt.wBitsPerSample,flags);fclose(f);}}
 HRESULT STDMETHODCALLTYPE QueryInterface(REFIID,void**p)override{*p=this;AddRef();return S_OK;}ULONG STDMETHODCALLTYPE AddRef()override{return ++refs;}ULONG STDMETHODCALLTYPE Release()override{return --refs;}
 HRESULT STDMETHODCALLTYPE GetCaps(DSBCAPS*p)override{DWORD size=p->dwSize;memset(p,0,size);p->dwSize=sizeof(*p);p->dwFlags=flags;p->dwBufferBytes=(DWORD)data.size();return S_OK;}
 DWORD cursor(){DWORD offset=playing?DWORD((ULONGLONG)(GetTickCount()-start)*fmt.nAvgBytesPerSec/1000):0;return (position+offset)%data.size();}
 HRESULT STDMETHODCALLTYPE GetCurrentPosition(DWORD*play,DWORD*write)override{DWORD c=cursor();if(play)*play=c;if(write)*write=(c+fmt.nAvgBytesPerSec/20)%data.size();return S_OK;}
 HRESULT STDMETHODCALLTYPE GetFormat(WAVEFORMATEX*p,DWORD n,DWORD*written)override{if(written)*written=sizeof(fmt);if(p)memcpy(p,&fmt,std::min(n,(DWORD)sizeof(fmt)));return S_OK;}
 HRESULT STDMETHODCALLTYPE GetVolume(LONG*p)override{*p=volume;return S_OK;}HRESULT STDMETHODCALLTYPE GetPan(LONG*p)override{*p=pan;return S_OK;}HRESULT STDMETHODCALLTYPE GetFrequency(DWORD*p)override{*p=fmt.nSamplesPerSec;return S_OK;}
 HRESULT STDMETHODCALLTYPE GetStatus(DWORD*p)override{*p=playing?DSBSTATUS_PLAYING|DSBSTATUS_LOOPING:0;return S_OK;}
 HRESULT STDMETHODCALLTYPE Initialize(IDirectSound*,const DSBUFFERDESC*)override{return S_OK;}
 HRESULT STDMETHODCALLTYPE Lock(DWORD offset,DWORD size,void**p1,DWORD*n1,void**p2,DWORD*n2,DWORD lockFlags)override{if(lockFlags&DSBLOCK_ENTIREBUFFER){offset=0;size=(DWORD)data.size();}offset%=data.size();size=std::min(size,(DWORD)data.size());*n1=std::min(size,(DWORD)data.size()-offset);*p1=*n1?data.data()+offset:nullptr;if(p2)*p2=size>*n1?data.data():nullptr;if(n2)*n2=size-*n1;return S_OK;}
 HRESULT STDMETHODCALLTYPE Play(DWORD,DWORD,DWORD)override{if(!playing){start=GetTickCount();playing=true;}return S_OK;}
 HRESULT STDMETHODCALLTYPE SetCurrentPosition(DWORD p)override{position=p%data.size();start=GetTickCount();return S_OK;}
 HRESULT STDMETHODCALLTYPE SetFormat(const WAVEFORMATEX*p)override{fmt=*p;return S_OK;}
 HRESULT STDMETHODCALLTYPE SetVolume(LONG v)override{volume=v;return S_OK;}HRESULT STDMETHODCALLTYPE SetPan(LONG v)override{pan=v;return S_OK;}HRESULT STDMETHODCALLTYPE SetFrequency(DWORD v)override{fmt.nSamplesPerSec=v;fmt.nAvgBytesPerSec=v*fmt.nBlockAlign;return S_OK;}
 HRESULT STDMETHODCALLTYPE Stop()override{position=cursor();playing=false;return S_OK;}
 HRESULT STDMETHODCALLTYPE Unlock(void*p1,DWORD n1,void*p2,DWORD n2)override{if(!(flags&DSBCAPS_PRIMARYBUFFER)){char name[80];sprintf_s(name,"audio-%02lu.pcm",number);FILE*f=nullptr;fopen_s(&f,name,"ab");if(f){if(p1&&n1)fwrite(p1,n1,1,f);if(p2&&n2)fwrite(p2,n2,1,f);fclose(f);}}return S_OK;}
 HRESULT STDMETHODCALLTYPE Restore()override{return S_OK;}
};
struct Sound:IDirectSound8{
 LONG refs=1;HRESULT STDMETHODCALLTYPE QueryInterface(REFIID,void**p)override{*p=this;AddRef();return S_OK;}ULONG STDMETHODCALLTYPE AddRef()override{return ++refs;}ULONG STDMETHODCALLTYPE Release()override{return --refs;}
 HRESULT STDMETHODCALLTYPE CreateSoundBuffer(const DSBUFFERDESC*d,IDirectSoundBuffer**p,IUnknown*)override{*p=new Buffer(d);return S_OK;}
 HRESULT STDMETHODCALLTYPE GetCaps(DSCAPS*p)override{DWORD size=p->dwSize;memset(p,0,size);p->dwSize=sizeof(*p);p->dwFlags=DSCAPS_CONTINUOUSRATE|DSCAPS_PRIMARY16BIT|DSCAPS_PRIMARYSTEREO;p->dwMinSecondarySampleRate=100;p->dwMaxSecondarySampleRate=192000;return S_OK;}
 HRESULT STDMETHODCALLTYPE DuplicateSoundBuffer(IDirectSoundBuffer*p,IDirectSoundBuffer**out)override{*out=p;p->AddRef();return S_OK;}
 HRESULT STDMETHODCALLTYPE SetCooperativeLevel(HWND,DWORD)override{return S_OK;}HRESULT STDMETHODCALLTYPE Compact()override{return S_OK;}
 HRESULT STDMETHODCALLTYPE GetSpeakerConfig(DWORD*p)override{*p=DSSPEAKER_STEREO;return S_OK;}HRESULT STDMETHODCALLTYPE SetSpeakerConfig(DWORD)override{return S_OK;}
 HRESULT STDMETHODCALLTYPE Initialize(const GUID*)override{return S_OK;}HRESULT STDMETHODCALLTYPE VerifyCertification(DWORD*p)override{*p=1;return S_OK;}
};
extern "C" HRESULT WINAPI SinkCreate(const GUID*,IDirectSound**p,IUnknown*){*p=new Sound;return S_OK;}
extern "C" HRESULT WINAPI SinkCreate8(const GUID*,IDirectSound8**p,IUnknown*){*p=new Sound;return S_OK;}
BOOL WINAPI DllMain(HINSTANCE,DWORD,void*){return TRUE;}
