$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$out=Join-Path $root 'analysis\native-build'
New-Item -ItemType Directory -Force $out | Out-Null
$vswhere=Join-Path ([Environment]::GetEnvironmentVariable('ProgramFiles(x86)')) 'Microsoft Visual Studio\Installer\vswhere.exe'
$vs=& $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if(!$vs){throw 'MSVC x86 toolchain not found'}
$vc=Join-Path $vs 'VC\Auxiliary\Build\vcvars32.bat'
$shader=(Join-Path $PSScriptRoot 'ffp.hlsl').Replace('\','/')
('201 RCDATA "'+$shader+'"') | Set-Content -LiteralPath (Join-Path $out 'native.rc') -Encoding utf8
$bridge=Join-Path $PSScriptRoot 'bridge.cpp';$backend=Join-Path $PSScriptRoot 'backend.cpp'
$def=Join-Path $root 'analysis\recorder\d3d8.def';$audio=Join-Path $root 'analysis\recorder\silent_dsound.cpp';$audioDef=Join-Path $root 'analysis\recorder\dsound.def'
$command='call "'+$vc+'" >nul && rc /nologo /fo native.res native.rc && cl /nologo /EHsc /MT /std:c++17 /O2 "'+$bridge+'" "'+$backend+'" native.res /Fe:d3d8.dll /LD /link /DEF:"'+$def+'" user32.lib d3d12.lib dxgi.lib d3dcompiler.lib dxguid.lib ole32.lib windowscodecs.lib && cl /nologo /EHsc /MT /std:c++17 /O2 "'+$audio+'" /Fe:dsound.dll /LD /link /DEF:"'+$audioDef+'"'
Push-Location $out
try{& cmd.exe /d /c $command;if($LASTEXITCODE -ne 0){throw "Native backend build failed: $LASTEXITCODE"}}finally{Pop-Location}
Write-Host 'Built original-data D3D12 backend. No program was launched.'
