param([switch]$Warp,[string]$Session=('accept-'+(Get-Date -Format 'yyyyMMdd-HHmmss')+'-'+[guid]::NewGuid().ToString('N').Substring(0,6)))
$ErrorActionPreference='Stop'
$root=$PSScriptRoot
$exe=[IO.Path]::GetFullPath((Join-Path $root 'build\fr08_d3d12.exe'))
$launcher=Join-Path $root 'build\isolated_run.exe'
if(!(Test-Path $exe) -or !(Test-Path $launcher)){throw 'Run build.ps1 first'}
$out=Join-Path $root ('captures\'+$Session)
New-Item -ItemType Directory -Force $out | Out-Null
$argsList=@($exe,$Session,'180','--test','--mute','--debug','--output',$out)
if($Warp){
 $script=Join-Path $out 'commands.txt'
 @('pause 1','hud 0','size 640 360','scene 1','capture warp-passage.png','scene 5','capture warp-red.png','scene 7','time 240','capture warp-rings.png','size 641 359','capture warp-odd.png','quit') | Set-Content -LiteralPath $script -Encoding utf8
 $argsList+=@('--warp','--commands',$script)
}
$start=[datetime]::UtcNow
Push-Location $root
try { & $launcher @argsList; $exit=$LASTEXITCODE } finally { Pop-Location }
$isolationPath=Join-Path $root ('isolation-'+$Session+'.log')
$isolation=Get-Content -LiteralPath $isolationPath -Raw
if($exit -ne 0){throw "Isolated app exit=$exit. Inspect $out and fr08-error.log"}
if($isolation -notmatch 'input_unchanged=1' -or $isolation -notmatch 'desktop_closed=1' -or $isolation -notmatch 'job_timeout_cleanup=0'){throw 'Isolation/cleanup observation failed'}
$testPid=[int]([regex]::Match($isolation,'(?m)^pid=(\d+)').Groups[1].Value)
Add-Type -AssemblyName System.Drawing
$results=@()
foreach($file in Get-ChildItem -LiteralPath $out -Filter '*.png.json'){
 $meta=Get-Content -LiteralPath $file.FullName -Raw | ConvertFrom-Json
 $path=$file.FullName.Substring(0,$file.FullName.Length-5)
 if($meta.session -ne $Session -or $meta.pid -ne $testPid -or $meta.frame -le 0){throw "PID/session/frame mismatch: $path"}
 if((Get-Item -LiteralPath $path).LastWriteTimeUtc -lt $start.AddSeconds(-1)){throw "Stale frame: $path"}
 $bmp=[Drawing.Bitmap]::FromFile($path)
 try {
  if($bmp.Width -ne $meta.width -or $bmp.Height -ne $meta.height){throw "Dimension mismatch: $path"}
  $samples=@(); $stepX=[Math]::Max(1,[int]($bmp.Width/64));$stepY=[Math]::Max(1,[int]($bmp.Height/40))
  for($y=0;$y -lt $bmp.Height;$y+=$stepY){for($x=0;$x -lt $bmp.Width;$x+=$stepX){$c=$bmp.GetPixel($x,$y);$samples+=(.2126*$c.R+.7152*$c.G+.0722*$c.B)}}
  $mean=($samples | Measure-Object -Average).Average
  $variance=0;foreach($sample in $samples){$variance+=($sample-$mean)*($sample-$mean)}
  $deviation=[Math]::Sqrt($variance/$samples.Count)
  if($bmp.Width*$bmp.Height -gt 1 -and ($mean -lt 2 -or $deviation -lt 3)){throw "Black/flat frame: $path mean=$mean std=$deviation"}
 } finally { $bmp.Dispose() }
 if($meta.borderless -and (($meta.window_style -band 0x80000000L) -eq 0 -or ($meta.window_style -band 0x00c00000L) -ne 0)){throw 'Not actually a borderless popup'}
 $results+=[pscustomobject]@{file=[IO.Path]::GetFileName($path);pid=$meta.pid;session=$meta.session;frame=$meta.frame;scene=$meta.scene;width=$meta.width;height=$meta.height;borderless=$meta.borderless;mean=[Math]::Round($mean,2);std=[Math]::Round($deviation,2);capture_ms=$meta.capture_ms;startup_to_capture_ms=$meta.startup_to_capture_ms;sha256=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash}
}
if($Warp -and ($results.Count -ne 4 -or ($results.scene | Sort-Object -Unique).Count -ne 3)){throw 'Incomplete WARP captures'}
if(!$Warp){
 if($results.Count -ne 20){throw 'Incomplete hardware acceptance captures'}
 if(($results.scene | Sort-Object -Unique).Count -ne 8){throw 'Missing one or more scene captures'}
 foreach($size in @(@(913,517),@(517,913),@(1600,500),@(127,83),@(1,1),@(1920,1080),@(3840,2160))){if(!($results | Where-Object {$_.width -eq $size[0] -and $_.height -eq $size[1]})){throw "Missing requested size $size"}}
 $restore=$results | Where-Object {$_.file -in @('restored-1280x720.png','repeated-restore.png','after-minimize.png')}
 if($restore.Count -ne 3 -or ($restore.sha256 | Sort-Object -Unique).Count -ne 1){throw 'Restored fixed-camera images differ'}
}
$run=Get-Content -LiteralPath (Join-Path $out ('run-'+$Session+'.log')) -Raw
if($run -notmatch 'validation_errors=0' -or $run -notmatch 'GPU idle; renderer'){throw 'Missing renderer validation/cleanup'}
$remaining=Get-CimInstance Win32_Process -Filter "ProcessId=$testPid" | Where-Object {$_.ExecutablePath -eq $exe -and $_.CommandLine -match [regex]::Escape($Session)}
if($remaining){throw 'Owned process remains after exit'}
$report=[ordered]@{session=$Session;pid=$testPid;started_utc=$start.ToString('o');ended_utc=[datetime]::UtcNow.ToString('o');warp=[bool]$Warp;passed=$true;debug_layer=($run -match 'debug_layer=enabled');input_desktop_unchanged=$true;process_exited=$true;desktop_closed=$true;isolation_log=$isolationPath;captures=$results}
$report | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $out 'acceptance.json') -Encoding utf8
$results | Format-Table file,scene,width,height,frame,mean,std,capture_ms
Write-Host ('PASS: '+$out+'\acceptance.json')
