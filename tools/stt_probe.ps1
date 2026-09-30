# Probe \\.\pipe\uksf_stt without whisper or Arma.
# Run while TeamSpeak has the ACRE plugin enabled.
# Usage: powershell -NoProfile -File tools/stt_probe.ps1 [-Seconds 8]
param([int]$Seconds = 8)

$src = @'
using System;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;

public static class SttProbe {
    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    public static extern SafeFileHandle CreateFile(
        string lpFileName, uint dwDesiredAccess, uint dwShareMode,
        IntPtr lpSecurityAttributes, uint dwCreationDisposition,
        uint dwFlagsAndAttributes, IntPtr hTemplateFile);

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
    public static extern bool WaitNamedPipe(string lpNamedPipeName, uint nTimeOut);

    public const uint GENERIC_READ = 0x80000000;
    public const uint FILE_SHARE_READ = 0x1;
    public const uint FILE_SHARE_WRITE = 0x2;
    public const uint OPEN_EXISTING = 3;
}
'@
Add-Type -TypeDefinition $src -ErrorAction Stop

$pipe = '\\.\pipe\uksf_stt'
$sw = [Diagnostics.Stopwatch]::StartNew()
function Tlog($m) { '{0,7}ms  {1}' -f $sw.ElapsedMilliseconds, $m }

Write-Host (Tlog "probe start $pipe")
if (-not [SttProbe]::WaitNamedPipe($pipe, 2000)) {
    Write-Host (Tlog "WaitNamedPipe failed lastError=$([Runtime.InteropServices.Marshal]::GetLastWin32Error())")
    Write-Host (Tlog 'ACRE plugin is not serving. Enable the plugin in TeamSpeak and retry.')
    exit 2
}
Write-Host (Tlog 'WaitNamedPipe ok')

$h = [SttProbe]::CreateFile($pipe, [SttProbe]::GENERIC_READ, [SttProbe]::FILE_SHARE_READ -bor [SttProbe]::FILE_SHARE_WRITE, [IntPtr]::Zero, [SttProbe]::OPEN_EXISTING, 0, [IntPtr]::Zero)
if ($h.IsInvalid) {
    Write-Host (Tlog "CreateFile failed lastError=$([Runtime.InteropServices.Marshal]::GetLastWin32Error())")
    exit 3
}
Write-Host (Tlog 'CreateFile ok — attached')

$fs = [IO.FileStream]::new($h, [IO.FileAccess]::Read)
$buf = New-Object byte[] 4096
$deadline = [DateTime]::UtcNow.AddSeconds($Seconds)
$total = 0
try {
    while ([DateTime]::UtcNow -lt $deadline) {
        if ($fs.CanRead -and $fs.Length -ge 0) { }
        $read = $fs.Read($buf, 0, $buf.Length)
        if ($read -le 0) {
            Write-Host (Tlog "read=0 (server closed) total=$total")
            break
        }
        $total += $read
        $ftype = [BitConverter]::ToUInt32($buf, 0)
        $len = if ($read -ge 8) { [BitConverter]::ToUInt32($buf, 4) } else { 0 }
        Write-Host (Tlog "read=$read type=$ftype len=$len total=$total")
    }
} catch {
    Write-Host (Tlog "read exception: $($_.Exception.Message)")
    exit 4
} finally {
    $fs.Dispose()
}
Write-Host (Tlog "probe done totalBytes=$total")
if ($total -eq 0) { Write-Host (Tlog 'attached, no frames (speak Direct PTT to produce START/DATA/END)') }
exit 0
