;@Findstr -bv ;@F "%~f0" | powershell -Command - & pause & goto:eof

# Unzip backwards compatibility (Windows 8)
Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip {
    param([string]$zipfile, [string]$outpath)

    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
}

[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
$client = New-Object Net.WebClient

# Write-Output "=> Downloading HEMTT (Windows) ...`n"
# $client.DownloadFile("https://ci.appveyor.com/api/buildjobs/9cpggqgd6qoe6enx/artifacts/target%2Fx86_64-pc-windows-msvc%2Frelease%2Fhemtt.exe", "..\hemtt.exe")

# Write-Output "HEMTT successfully installed to project!`n"

Write-Output "=> Downloading Bisign (Windows) ...`n"
$client.DownloadFile("https://github.com/synixebrett/bisign/releases/download/v0.2/bisign-win-x86_64.zip", "bisign.zip")
$client.dispose()
Expand-Archive -Path bisign.zip -DestinationPath ".." -Force

Write-Output "Bisign successfully installed to project!`n"
