param([string]$Session,[int]$TargetPid,[string]$Executable)
$ErrorActionPreference='Stop'
Add-Type 'using System; using System.Runtime.InteropServices; public class OwnedJob { [DllImport("kernel32.dll",CharSet=CharSet.Unicode)] public static extern IntPtr OpenJobObject(uint a,bool b,string n); [DllImport("kernel32.dll")] public static extern bool IsProcessInJob(IntPtr p,IntPtr j,out bool b); [DllImport("kernel32.dll")] public static extern bool TerminateJobObject(IntPtr j,uint c); [DllImport("kernel32.dll")] public static extern bool CloseHandle(IntPtr h); }'
$p=Get-CimInstance Win32_Process -Filter "ProcessId=$TargetPid"
if(!$p){exit 0}
if($p.ExecutablePath -ne $Executable -or $p.CommandLine -notmatch [regex]::Escape($Session)){throw 'Process ownership mismatch'}
$j=[OwnedJob]::OpenJobObject(0x1f003f,$false,"FR08_Job_$Session")
$owned=$false
try {if(!$j -or ![OwnedJob]::IsProcessInJob((Get-Process -Id $TargetPid).Handle,$j,[ref]$owned) -or !$owned){throw 'Job ownership mismatch'}; if(![OwnedJob]::TerminateJobObject($j,124)){throw 'Termination failed'}} finally {if($j){[void][OwnedJob]::CloseHandle($j)}}
