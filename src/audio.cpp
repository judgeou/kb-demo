#include "demo.h"
#include <mmsystem.h>
#include <filesystem>
struct Audio::Impl {bool opened=false,playing=false;float expected=-1;bool silent=false;};
Audio::Audio():p(std::make_unique<Impl>()){}
Audio::~Audio(){if(p->opened)mciSendStringW(L"close fr08audio",nullptr,0,nullptr);}
void Audio::seek(float seconds){if(p->opened){wchar_t cmd[128];swprintf_s(cmd,L"seek fr08audio to %u",(unsigned)(seconds*1000));mciSendStringW(cmd,nullptr,0,nullptr);p->playing=false;p->expected=seconds;}}
void Audio::update(float seconds,bool paused,bool mute){
 if(!p->opened&&!mute){wchar_t exe[32768];GetModuleFileNameW(nullptr,exe,32768);auto file=std::filesystem::path(exe).parent_path()/L"assets"/L"the_product_main.mp3";if(std::filesystem::exists(file)){std::wstring cmd=L"open \""+file.wstring()+L"\" type mpegvideo alias fr08audio";p->opened=mciSendStringW(cmd.c_str(),nullptr,0,nullptr)==0;if(p->opened){mciSendStringW(L"set fr08audio time format milliseconds",nullptr,0,nullptr);seek(seconds);}}}
 if(!p->opened)return;
 if(mute||paused){if(p->playing)mciSendStringW(L"pause fr08audio",nullptr,0,nullptr);p->playing=false;p->expected=-1;return;}
 if(p->expected<0||std::abs(seconds-p->expected)>.45f)seek(seconds);
 if(!p->playing){mciSendStringW(L"play fr08audio",nullptr,0,nullptr);p->playing=true;}p->expected=seconds;
}
