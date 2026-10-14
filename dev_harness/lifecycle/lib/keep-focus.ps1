param([int]$Seconds = 3600, [string]$Log, [string]$Match = 'LifecycleTest|uksflifecycle')
Add-Type -ReferencedAssemblies System.Management @"
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Management;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;

public static class FocusGuard {
    delegate void WinEventProc(IntPtr hook, uint evt, IntPtr hwnd, int obj, int child, uint thread, uint time);
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
    [DllImport("user32.dll")] static extern bool SetWindowPos(IntPtr h, IntPtr after, int x, int y, int cx, int cy, uint flags);
    [DllImport("user32.dll")] static extern bool IsWindow(IntPtr h);
    [DllImport("user32.dll")] static extern bool GetCursorPos(out POINT p);
    [DllImport("user32.dll")] static extern bool SetCursorPos(int x, int y);
    [DllImport("user32.dll")] static extern bool ClipCursor(IntPtr rect);

    const uint EVENT_SYSTEM_FOREGROUND = 3;
    const uint SWP_NOSIZE = 1, SWP_NOMOVE = 2, SWP_NOACTIVATE = 0x10;
    static readonly IntPtr HWND_BOTTOM = new IntPtr(1);
    const int FALL_THROUGH_MS = 2000;
    const int CURSOR_LAG_MS = 150;

    static WinEventProc proc = OnForeground;
    static Regex match;
    static string log;
    static readonly Dictionary<uint, bool> harness = new Dictionary<uint, bool>();
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

    static bool IsHarness(uint pid) {
        bool known;
        if (harness.TryGetValue(pid, out known)) return known;
        string line = "";
        try {
            using (var search = new ManagementObjectSearcher("SELECT CommandLine FROM Win32_Process WHERE ProcessId = " + pid))
                foreach (ManagementObject p in search.Get()) line = (p["CommandLine"] as string) ?? "";
        } catch { }
        known = match.IsMatch(line);
        harness[pid] = known;
        return known;
    }

    static bool IsShell(uint pid) {
        try { return Process.GetProcessById((int)pid).ProcessName.Equals("explorer", StringComparison.OrdinalIgnoreCase); } catch { return false; }
    }

    static void Warm(object state) {
        try {
            using (var search = new ManagementObjectSearcher("SELECT ProcessId, CommandLine FROM Win32_Process WHERE Name LIKE 'arma3%'"))
                foreach (ManagementObject p in search.Get()) {
                    uint pid = (uint)p["ProcessId"];
                    bool isHarness = match.IsMatch((p["CommandLine"] as string) ?? "");
                    lock (harness) { harness[pid] = isHarness; }
                }
        } catch { }
    }

    static void SampleCursor(object state) {
        IntPtr fg = GetForegroundWindow();
        if (fg == IntPtr.Zero || IsHarnessCached(Owner(fg))) return;
        POINT p; if (!GetCursorPos(out p)) return;
        lock (cursorLock) {
            cursor.Enqueue(new KeyValuePair<long, POINT>(clock.ElapsedMilliseconds, p));
            while (cursor.Count > 40) cursor.Dequeue();
        }
    }

    static bool IsHarnessCached(uint pid) { bool known; lock (harness) { return harness.TryGetValue(pid, out known) && known; } }

    static void RestoreCursor(long stolenAt) {
        POINT best = new POINT(); bool found = false;
        lock (cursorLock) {
            foreach (var sample in cursor) if (sample.Key <= stolenAt - CURSOR_LAG_MS) { best = sample.Value; found = true; }
        }
        ClipCursor(IntPtr.Zero);
        if (found) SetCursorPos(best.X, best.Y);
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
        bool isHarness;
        lock (harness) { isHarness = IsHarness(pid); }
        long now = clock.ElapsedMilliseconds;
        if (isHarness) {
            lastSteal = now;
            SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);
            GiveBack(userWindow);
            RestoreCursor(now);
            POINT at; GetCursorPos(out at);
            Log("pushed back pid " + pid + ", restored " + (GetForegroundWindow() == userWindow ? "focus" : "FAILED") + ", cursor " + at.X + "," + at.Y);
            return;
        }
        if (hwnd == userWindow) return;
        if (now - lastSteal < FALL_THROUGH_MS && IsShell(pid)) {
            GiveBack(userWindow);
            RestoreCursor(lastSteal);
            Log("focus fell to the shell after a steal, restored " + (GetForegroundWindow() == userWindow ? "focus" : "FAILED"));
            return;
        }
        userWindow = hwnd;
    }

    public static void Run(int seconds, string logPath, string pattern) {
        log = string.IsNullOrEmpty(logPath) ? null : logPath;
        match = new Regex(pattern, RegexOptions.IgnoreCase);
        userWindow = GetForegroundWindow();
        SetWinEventHook(EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND, IntPtr.Zero, proc, 0, 0, 0);
        var sampler = new System.Threading.Timer(SampleCursor, null, 0, 50);
        var warmer = new System.Threading.Timer(Warm, null, 0, 1000);
        uint tid = GetCurrentThreadId();
        var stopper = new System.Threading.Timer(s => PostThreadMessage(tid, 0x12, IntPtr.Zero, IntPtr.Zero), null, seconds * 1000L, System.Threading.Timeout.Infinite);
        Log("guard started, matching " + pattern);
        MSG msg;
        while (GetMessage(out msg, IntPtr.Zero, 0, 0) > 0) { }
        sampler.Dispose(); warmer.Dispose(); stopper.Dispose();
    }
}
"@
[FocusGuard]::Run($Seconds, $Log, $Match)
