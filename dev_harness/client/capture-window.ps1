param([uint32]$ArmaPid, [string]$OutPath)
Add-Type -ReferencedAssemblies System.Drawing @"
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
public static class WindowCapture {
  public delegate bool EnumProc(IntPtr h, IntPtr p);
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int Left, Top, Right, Bottom; }
  [DllImport("user32.dll")] static extern bool EnumWindows(EnumProc f, IntPtr p);
  [DllImport("user32.dll")] static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] static extern bool GetClientRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] static extern bool PrintWindow(IntPtr h, IntPtr hdc, uint flags);
  [DllImport("user32.dll")] static extern bool SetProcessDPIAware();
  [DllImport("user32.dll")] static extern bool IsIconic(IntPtr h);
  [DllImport("user32.dll")] static extern bool ShowWindow(IntPtr h, int cmd);
  [DllImport("user32.dll")] static extern bool GetWindowPlacement(IntPtr h, ref WINDOWPLACEMENT p);
  [DllImport("user32.dll")] static extern bool SetWindowPlacement(IntPtr h, ref WINDOWPLACEMENT p);
  [StructLayout(LayoutKind.Sequential)] public struct POINT { public int X, Y; }
  [StructLayout(LayoutKind.Sequential)] public struct WINDOWPLACEMENT {
    public int length, flags, showCmd; public POINT minPos, maxPos; public RECT normal;
  }
  const uint PW_CLIENTONLY = 1, PW_RENDERFULLCONTENT = 2;
  const int SW_SHOWNOACTIVATE = 4, SW_SHOWMINNOACTIVE = 7;
  const int OFF_SCREEN_X = -20000;

  static IntPtr FindLargestWindow(uint pid) {
    IntPtr best = IntPtr.Zero; long bestArea = 0;
    EnumWindows((h, p) => {
      uint owner; GetWindowThreadProcessId(h, out owner);
      RECT r;
      if (owner == pid && IsWindowVisible(h)) {
        WINDOWPLACEMENT wp = new WINDOWPLACEMENT(); wp.length = Marshal.SizeOf(wp);
        GetWindowPlacement(h, ref wp);
        r = wp.normal;
        long area = (long)(r.Right - r.Left) * (r.Bottom - r.Top);
        if (area > bestArea) { bestArea = area; best = h; }
      }
      return true;
    }, IntPtr.Zero);
    return best;
  }

  public static string Capture(uint pid, string path) {
    SetProcessDPIAware();
    IntPtr h = FindLargestWindow(pid);
    if (h == IntPtr.Zero) return "no window";
    bool wasMinimised = IsIconic(h);
    WINDOWPLACEMENT original = new WINDOWPLACEMENT(); original.length = Marshal.SizeOf(original);
    GetWindowPlacement(h, ref original);
    if (wasMinimised) {
      WINDOWPLACEMENT wp = original;
      int w = wp.normal.Right - wp.normal.Left, ht = wp.normal.Bottom - wp.normal.Top;
      wp.normal.Left = OFF_SCREEN_X; wp.normal.Right = OFF_SCREEN_X + w; wp.normal.Bottom = wp.normal.Top + ht;
      wp.showCmd = SW_SHOWNOACTIVATE;
      SetWindowPlacement(h, ref wp);
      System.Threading.Thread.Sleep(1000);
    }
    try { return Save(h, path); }
    finally {
      if (wasMinimised) {
        original.showCmd = SW_SHOWMINNOACTIVE;
        SetWindowPlacement(h, ref original);
      }
    }
  }

  static string Save(IntPtr h, string path) {
    RECT r; GetClientRect(h, out r);
    if (r.Right - r.Left <= 0) return "window has no client area";
    using (var bmp = new Bitmap(r.Right - r.Left, r.Bottom - r.Top, PixelFormat.Format32bppArgb))
    using (var g = Graphics.FromImage(bmp)) {
      IntPtr hdc = g.GetHdc();
      bool ok = PrintWindow(h, hdc, PW_CLIENTONLY | PW_RENDERFULLCONTENT);
      g.ReleaseHdc(hdc);
      if (!ok) return "PrintWindow failed";
      bmp.Save(path, ImageFormat.Png);
    }
    return "ok";
  }
}
"@
[WindowCapture]::Capture($ArmaPid, $OutPath)
