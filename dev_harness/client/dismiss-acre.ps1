param([uint32]$ArmaPid)
Add-Type @"
using System;
using System.Runtime.InteropServices;
using System.Text;
public static class AcreDialog {
  public delegate bool EnumProc(IntPtr h, IntPtr p);
  [DllImport("user32.dll")] public static extern bool EnumWindows(EnumProc f, IntPtr p);
  [DllImport("user32.dll")] public static extern int GetWindowText(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
}
"@
$WM_CLOSE = 0x10
[AcreDialog]::EnumWindows({ param($h, $p)
  $owner = [uint32]0; [void][AcreDialog]::GetWindowThreadProcessId($h, [ref]$owner)
  $title = New-Object System.Text.StringBuilder 256; [void][AcreDialog]::GetWindowText($h, $title, 256)
  if ($owner -eq $ArmaPid -and $title.ToString().StartsWith('ACRE2')) {
    "dismissed '$title'"
    [void][AcreDialog]::PostMessage($h, $WM_CLOSE, [IntPtr]::Zero, [IntPtr]::Zero)
  }
  $true }, [IntPtr]::Zero) | Out-Null
