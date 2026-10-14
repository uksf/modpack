param([int]$Seconds = 3600, [string]$Log)
Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class Focus {
    [DllImport("user32.dll")] public static extern IntPtr GetForegroundWindow();
    [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint pid);
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr hWnd, int cmd);
    [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr hWnd);
    [DllImport("user32.dll")] public static extern bool ClipCursor(IntPtr rect);
}
"@
$SW_MINIMIZE = 6
$end = (Get-Date).AddSeconds($Seconds)
$pids = @()
$refreshAt = Get-Date
$previous = [IntPtr]::Zero
while ((Get-Date) -lt $end) {
    if ((Get-Date) -ge $refreshAt) {
        $pids = @(Get-CimInstance Win32_Process -Filter "Name LIKE 'arma3%'" | Where-Object { $_.CommandLine -match 'LifecycleTest|uksflifecycle' } | ForEach-Object { [uint32]$_.ProcessId })
        $refreshAt = (Get-Date).AddSeconds(2)
    }
    $foreground = [Focus]::GetForegroundWindow()
    $owner = [uint32]0
    [Focus]::GetWindowThreadProcessId($foreground, [ref]$owner) | Out-Null
    if ($pids -contains $owner) {
        [Focus]::ShowWindow($foreground, $SW_MINIMIZE) | Out-Null
        [Focus]::ClipCursor([IntPtr]::Zero) | Out-Null
        if ($previous -ne [IntPtr]::Zero) { [Focus]::SetForegroundWindow($previous) | Out-Null }
        if ($Log) { Add-Content -Path $Log -Value "$(Get-Date -Format HH:mm:ss) minimised pid $owner" }
    } elseif ($foreground -ne [IntPtr]::Zero) {
        $previous = $foreground
    }
    Start-Sleep -Milliseconds 200
}
