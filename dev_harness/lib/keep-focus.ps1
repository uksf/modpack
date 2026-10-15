param([string]$Match = "", [string]$PidFile = "", [int]$Seconds = 3600, [int]$ParentPid = 0, [string]$Log)
if (-not $Match -and -not $PidFile) { throw "pass -Match <per-run token> or -PidFile <file of PIDs this run started>" }
Add-Type -ReferencedAssemblies System.Management @"
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Management;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;

public static class FocusGuard {
    delegate void WinEventProc(IntPtr hook, uint evt, IntPtr hwnd, int obj, int child, uint thread, uint time);
    delegate bool EnumProc(IntPtr h, IntPtr param);
    [StructLayout(LayoutKind.Sequential)] struct POINT { public int X, Y; }
    [StructLayout(LayoutKind.Sequential)] struct MSG { public IntPtr h; public uint m; public IntPtr w, l; public uint t; public POINT p; }

    [DllImport("user32.dll")] static extern IntPtr SetWinEventHook(uint min, uint max, IntPtr mod, WinEventProc proc, uint pid, uint tid, uint flags);
    [DllImport("user32.dll")] static extern int GetMessage(out MSG msg, IntPtr h, uint min, uint max);
    [DllImport("user32.dll")] static extern bool PostThreadMessage(uint tid, uint msg, IntPtr w, IntPtr l);
    [DllImport("kernel32.dll")] static extern uint GetCurrentThreadId();
    [DllImport("user32.dll")] static extern IntPtr GetForegroundWindow();
    [DllImport("user32.dll")] static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
    [DllImport("user32.dll")] static extern bool SetForegroundWindow(IntPtr h);
    [DllImport("user32.dll")] static extern bool BringWindowToTop(IntPtr h);
    [DllImport("user32.dll")] static extern bool AttachThreadInput(uint a, uint b, bool attach);
    [DllImport("user32.dll")] static extern void keybd_event(byte vk, byte scan, uint flags, UIntPtr extra);
    [DllImport("user32.dll")] static extern bool IsWindow(IntPtr h);
    [DllImport("user32.dll")] static extern bool IsWindowVisible(IntPtr h);
    [DllImport("user32.dll")] static extern bool IsIconic(IntPtr h);
    [DllImport("user32.dll")] static extern bool EnumWindows(EnumProc proc, IntPtr param);
    [DllImport("user32.dll")] static extern bool ShowWindow(IntPtr h, int cmd);
    [DllImport("user32.dll")] static extern bool GetCursorPos(out POINT p);
    [DllImport("user32.dll")] static extern bool SetCursorPos(int x, int y);
    [DllImport("user32.dll")] static extern bool ClipCursor(IntPtr rect);

    const uint EVENT_SYSTEM_FOREGROUND = 3;
    const int SW_MINIMIZE = 6;
    const int SW_SHOWMINNOACTIVE = 7;
    const int FALL_THROUGH_MS = 2000;
    const int CURSOR_LAG_MS = 150;
    const int RESTORE_ATTEMPTS = 4;

    static WinEventProc proc = OnForeground;
    static EnumProc sweeper = SweepWindow;
    static Regex match;
    static string pidFile;
    static string log;
    static HashSet<uint> harness = new HashSet<uint>();
    static IntPtr userWindow = IntPtr.Zero;
    static long lastSteal = -FALL_THROUGH_MS;
    static readonly Stopwatch clock = Stopwatch.StartNew();
    static readonly object cursorLock = new object();
    static readonly Queue<KeyValuePair<long, POINT>> cursor = new Queue<KeyValuePair<long, POINT>>();

    static void Log(string text) {
        if (log == null) return;
        try { File.AppendAllText(log, DateTime.Now.ToString("HH:mm:ss.fff") + " " + text + Environment.NewLine); } catch { }
    }

    static uint Owner(IntPtr h) { uint pid; GetWindowThreadProcessId(h, out pid); return pid; }

    static bool IsHarness(uint pid) { lock (harness) { return harness.Contains(pid); } }

    static string Name(IntPtr h) {
        try { return Process.GetProcessById((int)Owner(h)).ProcessName; } catch { return "none"; }
    }

    static bool IsShell(uint pid) {
        try { return Process.GetProcessById((int)pid).ProcessName.Equals("explorer", StringComparison.OrdinalIgnoreCase); } catch { return false; }
    }

    static void RefreshProcesses(object state) {
        var found = new HashSet<uint>();
        if (pidFile != null) {
            try {
                foreach (var line in File.ReadAllLines(pidFile)) { uint pid; if (uint.TryParse(line.Trim(), out pid)) found.Add(pid); }
            } catch { }
        }
        if (match != null) {
            try {
                using (var search = new ManagementObjectSearcher("SELECT ProcessId, CommandLine FROM Win32_Process WHERE Name LIKE 'arma3%'"))
                    foreach (ManagementObject p in search.Get())
                        if (match.IsMatch((p["CommandLine"] as string) ?? "")) found.Add((uint)p["ProcessId"]);
            } catch { return; }
        }
        lock (harness) {
            foreach (var pid in found) if (!harness.Contains(pid)) Log("tracking pid " + pid);
            harness = found;
        }
    }

    static bool SweepWindow(IntPtr h, IntPtr param) {
        uint pid = Owner(h);
        if (IsWindowVisible(h) && !IsIconic(h) && IsHarness(pid)) {
            if (h == GetForegroundWindow()) { OnForeground(IntPtr.Zero, 0, h, 0, 0, 0, 0); return true; }
            ShowWindow(h, SW_SHOWMINNOACTIVE);
            Log("minimised pid " + pid + " window in the background");
        }
        return true;
    }

    static void Sweep(object state) { EnumWindows(sweeper, IntPtr.Zero); }

    static void SampleCursor(object state) {
        IntPtr fg = GetForegroundWindow();
        if (fg == IntPtr.Zero || IsHarness(Owner(fg))) return;
        POINT p; if (!GetCursorPos(out p)) return;
        lock (cursorLock) {
            cursor.Enqueue(new KeyValuePair<long, POINT>(clock.ElapsedMilliseconds, p));
            while (cursor.Count > 40) cursor.Dequeue();
        }
    }

    static void RestoreCursor(long stolenAt) {
        POINT best = new POINT(); bool found = false;
        lock (cursorLock) {
            foreach (var sample in cursor) if (sample.Key <= stolenAt - CURSOR_LAG_MS) { best = sample.Value; found = true; }
        }
        ClipCursor(IntPtr.Zero);
        if (found) SetCursorPos(best.X, best.Y);
    }

    static bool FocusIsBack() {
        IntPtr fg = GetForegroundWindow();
        return fg != IntPtr.Zero && !IsHarness(Owner(fg)) && !IsShell(Owner(fg));
    }

    static bool Restore() {
        for (int attempt = 0; attempt < RESTORE_ATTEMPTS && !FocusIsBack(); attempt++) {
            GiveBack(userWindow);
            System.Threading.Thread.Sleep(30);
        }
        return FocusIsBack();
    }

    static void GiveBack(IntPtr target) {
        if (target == IntPtr.Zero || !IsWindow(target)) return;
        uint me = GetCurrentThreadId();
        uint pid;
        uint fgThread = GetWindowThreadProcessId(GetForegroundWindow(), out pid);
        AttachThreadInput(me, fgThread, true);
        keybd_event(0x12, 0, 0, UIntPtr.Zero);
        keybd_event(0x12, 0, 2, UIntPtr.Zero);
        BringWindowToTop(target);
        SetForegroundWindow(target);
        AttachThreadInput(me, fgThread, false);
    }

    static void OnForeground(IntPtr hook, uint evt, IntPtr hwnd, int obj, int child, uint thread, uint time) {
        if (hwnd == IntPtr.Zero) return;
        uint pid = Owner(hwnd);
        long now = clock.ElapsedMilliseconds;
        if (IsHarness(pid)) {
            lastSteal = now;
            ShowWindow(hwnd, SW_MINIMIZE);
            bool restored = Restore();
            RestoreCursor(now);
            POINT at; GetCursorPos(out at);
            Log("pushed back pid " + pid + ", focus " + (restored ? "now " : "FAILED, now ") + Name(GetForegroundWindow()) + ", cursor " + at.X + "," + at.Y);
            return;
        }
        if (hwnd == userWindow) return;
        if (now - lastSteal < FALL_THROUGH_MS && IsShell(pid)) {
            bool restored = Restore();
            RestoreCursor(lastSteal);
            Log("focus fell to the shell after a steal, restored " + (restored ? "focus to " + Name(GetForegroundWindow()) : "FAILED"));
            return;
        }
        userWindow = hwnd;
    }

    static void Watch(object state) {
        int parent = (int)state;
        try { if (Process.GetProcessById(parent).HasExited) Stop(); } catch { Stop(); }
    }

    static uint loopThread;
    static void Stop() { PostThreadMessage(loopThread, 0x12, IntPtr.Zero, IntPtr.Zero); }

    public static void Run(string pattern, string pids, int seconds, int parentPid, string logPath) {
        log = string.IsNullOrEmpty(logPath) ? null : logPath;
        match = string.IsNullOrEmpty(pattern) ? null : new Regex(pattern, RegexOptions.IgnoreCase);
        pidFile = string.IsNullOrEmpty(pids) ? null : pids;
        loopThread = GetCurrentThreadId();
        userWindow = GetForegroundWindow();
        RefreshProcesses(null);
        SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND, IntPtr.Zero, proc, 0, 0, 0);
        var timers = new List<System.Threading.Timer> {
            new System.Threading.Timer(RefreshProcesses, null, 1000, 1000),
            new System.Threading.Timer(Sweep, null, 0, 50),
            new System.Threading.Timer(SampleCursor, null, 0, 50),
            new System.Threading.Timer(s => Stop(), null, seconds * 1000L, System.Threading.Timeout.Infinite),
        };
        if (parentPid > 0) timers.Add(new System.Threading.Timer(Watch, parentPid, 1000, 1000));
        Log("guard started, token " + (match == null ? "-" : pattern) + ", pid file " + (pidFile ?? "-") + (parentPid > 0 ? ", parent " + parentPid : ""));
        MSG msg;
        while (GetMessage(out msg, IntPtr.Zero, 0, 0) > 0) { }
        timers.ForEach(t => t.Dispose());
        Log("guard stopped");
    }
}
"@
[FocusGuard]::Run($Match, $PidFile, $Seconds, $ParentPid, $Log)
