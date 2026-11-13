param([string]$Configuration='Release')
$ErrorActionPreference='Stop'
$root=$PSScriptRoot
$vswhere=Join-Path ([Environment]::GetEnvironmentVariable('ProgramFiles(x86)')) 'Microsoft Visual Studio\Installer\vswhere.exe'
if(!(Test-Path $vswhere)){throw 'Install Visual Studio C++ Desktop workload and Windows SDK first.'}
$vs=& $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if(!$vs){throw 'MSVC x64 toolchain not found'}
$vc=Join-Path $vs 'VC\Auxiliary\Build\vcvars64.bat'
$env:VSLANG='1033'
$cmake=(Get-Command cmake -ErrorAction SilentlyContinue).Source
if(!$cmake){$cmake=Join-Path $vs 'Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe'}
if(!(Test-Path $cmake)){throw 'CMake is required'}
# All outputs stay in the project. No package installation and no AppData storage.
$generator=if(Get-Command ninja -ErrorAction SilentlyContinue){'Ninja'}else{'NMake Makefiles'}
$cmd='call "'+$vc+'" >nul && "'+$cmake+'" -S "'+$root+'" -B "'+$root+'\build" -G "'+$generator+'" -DCMAKE_BUILD_TYPE='+$Configuration+' && "'+$cmake+'" --build "'+$root+'\build"'
& cmd.exe /d /c $cmd
if($LASTEXITCODE -ne 0){throw "Build failed: $LASTEXITCODE"}
Write-Host 'Built build\fr08_d3d12.exe. This script never launches the demo.'
