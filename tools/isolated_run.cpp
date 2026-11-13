#define UNICODE
#define _UNICODE
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
int wmain(int argc,wchar_t**argv){
 if(argc<4)return 2;
 std::wstring exe=argv[1],tag=argv[2]; DWORD timeout=_wtoi(argv[3])*1000;
 if(exe.size()<3||exe[1]!=L':')return 3;
 std::wstring dn=L"FR08_Test_"+tag;
 HDESK input=OpenInputDesktop(0,FALSE,DESKTOP_READOBJECTS); wchar_t before[256]={}; DWORD n; if(input)GetUserObjectInformationW(input,UOI_NAME,before,sizeof(before),&n);
 HDESK desk=CreateDesktopW(dn.c_str(),nullptr,nullptr,0,GENERIC_ALL,nullptr); if(!desk)return 4;
 HANDLE job=CreateJobObjectW(nullptr,(L"FR08_Job_"+tag).c_str()); JOBOBJECT_EXTENDED_LIMIT_INFORMATION li={};li.BasicLimitInformation.LimitFlags=JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;SetInformationJobObject(job,JobObjectExtendedLimitInformation,&li,sizeof(li));
 std::wstring cmd=L"\""+exe+L"\" --session "+tag;for(int i=4;i<argc;i++){cmd+=L" \"";cmd+=argv[i];cmd+=L"\"";}
 STARTUPINFOW si={sizeof(si)}; si.lpDesktop=dn.data();PROCESS_INFORMATION pi={};
 HWND foregroundBefore=GetForegroundWindow();DWORD foregroundPidBefore=0;GetWindowThreadProcessId(foregroundBefore,&foregroundPidBefore);ULONGLONG start=GetTickCount64(); if(!CreateProcessW(exe.c_str(),cmd.data(),nullptr,nullptr,FALSE,CREATE_SUSPENDED,nullptr,nullptr,&si,&pi)){CloseDesktop(desk);return 5;}
 if(!AssignProcessToJobObject(job,pi.hProcess)){TerminateProcess(pi.hProcess,6);return 6;} ResumeThread(pi.hThread);
 DWORD wait=WAIT_TIMEOUT,exit=0;bool killed=false; while(GetTickCount64()-start<timeout){ wait=WaitForSingleObject(pi.hProcess,100); if(wait!=WAIT_TIMEOUT)break; if(GetFileAttributesW((L"stop-"+tag).c_str())!=INVALID_FILE_ATTRIBUTES)break; }
 if(wait==WAIT_TIMEOUT){wchar_t actual[32768];DWORD count=32768;BOOL inJob=FALSE;QueryFullProcessImageNameW(pi.hProcess,0,actual,&count);IsProcessInJob(pi.hProcess,job,&inJob);if(inJob&&_wcsicmp(exe.c_str(),actual)==0){TerminateJobObject(job,124);killed=true;WaitForSingleObject(pi.hProcess,5000);}}
 GetExitCodeProcess(pi.hProcess,&exit);HDESK afterDesk=OpenInputDesktop(0,FALSE,DESKTOP_READOBJECTS);wchar_t after[256]={};if(afterDesk)GetUserObjectInformationW(afterDesk,UOI_NAME,after,sizeof(after),&n);
 HWND foregroundAfter=GetForegroundWindow();DWORD foregroundPidAfter=0;GetWindowThreadProcessId(foregroundAfter,&foregroundPidAfter);std::wofstream log(L"isolation-"+tag+L".log");log<<L"foreground_before="<<foregroundBefore<<L" pid="<<foregroundPidBefore<<L"\nforeground_after="<<foregroundAfter<<L" pid="<<foregroundPidAfter<<L"\n";log<<L"session="<<tag<<L"\npid="<<pi.dwProcessId<<L"\nexe="<<exe<<L"\ndesktop="<<dn<<L"\ninput_before="<<before<<L"\ninput_after="<<after<<L"\ninput_unchanged="<<(_wcsicmp(before,after)==0)<<L"\nexit="<<exit<<L"\njob_timeout_cleanup="<<killed<<L"\nelapsed_ms="<<GetTickCount64()-start<<L"\n";
 CloseHandle(pi.hThread);CloseHandle(pi.hProcess);CloseHandle(job);BOOL closed=CloseDesktop(desk);log<<L"desktop_closed="<<closed<<L"\n";if(input)CloseDesktop(input);if(afterDesk)CloseDesktop(afterDesk);return wait==WAIT_TIMEOUT?124:(int)exit;
}
