param([int]$Seconds = 3600, [string]$Log)
Add-Type @"
using System;
using System.Text;
using System.Runtime.InteropServices;
public static class AcreDialogs {
    delegate bool EnumProc(IntPtr hWnd, IntPtr lParam);
    [DllImport("user32.dll")] static extern bool EnumWindows(EnumProc cb, IntPtr lParam);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] static extern int GetWindowText(IntPtr hWnd, StringBuilder text, int max);
    [DllImport("user32.dll")] static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint pid);
    [DllImport("user32.dll")] static extern bool PostMessage(IntPtr hWnd, uint msg, IntPtr w, IntPtr l);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] static extern int GetClassName(IntPtr hWnd, StringBuilder name, int max);
    [DllImport("user32.dll")] static extern bool IsWindowVisible(IntPtr hWnd);
    [DllImport("user32.dll")] static extern bool EnumChildWindows(IntPtr parent, EnumProc cb, IntPtr lParam);
    static string ChildText(IntPtr h) {
        var text = new StringBuilder();
        EnumChildWindows(h, (c, l) => {
            var t = new StringBuilder(1024); GetWindowText(c, t, 1024);
            if (t.Length > 0) text.Append(t.ToString().Replace((char)13, (char)32).Replace((char)10, (char)32)).Append(" | ");
            return true;
        }, IntPtr.Zero);
        return text.Length > 300 ? text.ToString(0, 300) : text.ToString();
    }
    public static string Dialogs(uint[] pids) {
        var found = new StringBuilder();
        EnumWindows((h, l) => {
            uint pid; GetWindowThreadProcessId(h, out pid);
            if (Array.IndexOf(pids, pid) < 0 || !IsWindowVisible(h)) return true;
            var cls = new StringBuilder(256); GetClassName(h, cls, 256);
            if (cls.ToString() != "#32770") return true;
            var title = new StringBuilder(256); GetWindowText(h, title, 256);
            found.AppendFormat("[{0}] pid {1} <{2}>; ", title, pid, ChildText(h));
            return true;
        }, IntPtr.Zero);
        return found.ToString();
    }
    public static string CloseAll(uint[] pids) {
        var closed = new StringBuilder();
        EnumWindows((h, l) => {
            var title = new StringBuilder(256);
            GetWindowText(h, title, 256);
            uint pid; GetWindowThreadProcessId(h, out pid);
            if (title.ToString().StartsWith("ACRE2") && Array.IndexOf(pids, pid) >= 0) {
                PostMessage(h, 0x0010, IntPtr.Zero, IntPtr.Zero);
                closed.AppendFormat("{0} pid {1}; ", title, pid);
            }
            return true;
        }, IntPtr.Zero);
        return closed.ToString();
    }
}
"@
$end = (Get-Date).AddSeconds($Seconds)
while ((Get-Date) -lt $end) {
    $pids = [uint32[]]@(Get-CimInstance Win32_Process -Filter "Name LIKE 'arma3%'" | Where-Object { $_.CommandLine -match 'LifecycleTest|uksflifecycle' } | ForEach-Object { $_.ProcessId })
    $closed = [AcreDialogs]::CloseAll($pids)
    if ($closed -and $Log) { Add-Content -Path $Log -Value "$(Get-Date -Format HH:mm:ss) closed $closed" }
    $dialogs = [AcreDialogs]::Dialogs($pids)
    if ($dialogs -and $Log -and $dialogs -ne $script:lastDialogs) { Add-Content -Path $Log -Value "$(Get-Date -Format HH:mm:ss) dialogs $dialogs" }
    $script:lastDialogs = $dialogs
    Start-Sleep -Seconds 2
}
