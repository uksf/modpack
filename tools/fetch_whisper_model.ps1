#Requires -Version 5
<#
    Provisions the whisper STT model (ggml-base.en.bin) to the modpack root so
    hemtt's [files] include ships it next to uksf_x64.dll.

    Source of truth is HuggingFace's live LFS pointer (its oid sha256), so the
    model auto-updates if upstream changes, but is never re-downloaded when
    unchanged (oid match against the local cache). No sha is hardcoded.
#>
[CmdletBinding()]
param(
    [string]$Dest,
    [string]$CacheDir = (Join-Path $env:LOCALAPPDATA "uksf\whisper")
)

$ErrorActionPreference = "Stop"

# Resolve the modpack root robustly. Normally the script's own folder (tools\)
# gives it; fall back to the current directory when $PSScriptRoot is unset (some
# nested invocation contexts). The model must land at the modpack root so hemtt's
# [files] include ships it next to uksf_x64.dll.
if (-not $Dest) {
    $root = if ($PSScriptRoot) { Split-Path -Parent $PSScriptRoot } else { (Get-Location).Path }
    $Dest = Join-Path $root "ggml-base.en.bin"
}
$ProgressPreference = "SilentlyContinue"  # faster Invoke-WebRequest for the large blob

$ModelFile  = "ggml-base.en.bin"
$PointerUrl = "https://huggingface.co/ggerganov/whisper.cpp/raw/main/$ModelFile"
$BlobUrl    = "https://huggingface.co/ggerganov/whisper.cpp/resolve/main/$ModelFile"

function Get-Sha256([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path)) { return $null }
    (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLower()
}

# 1. Read the upstream LFS pointer (tiny) for the current oid.
$pointer = (Invoke-WebRequest -Uri $PointerUrl -UseBasicParsing).Content
if ($pointer -isnot [string]) { $pointer = [Text.Encoding]::UTF8.GetString($pointer) }
if ($pointer -notmatch 'oid sha256:([0-9a-f]{64})') {
    throw "Could not parse LFS pointer oid from $PointerUrl"
}
$oid = $Matches[1].ToLower()
Write-Host "[whisper-model] upstream oid: $oid"

# 2. Destination already current?
if ((Get-Sha256 $Dest) -eq $oid) {
    Write-Host "[whisper-model] dest already up to date: $Dest"
    exit 0
}

# 3. Ensure cache has the current blob.
New-Item -ItemType Directory -Force -Path $CacheDir | Out-Null
$cachePath = Join-Path $CacheDir $ModelFile
if ((Get-Sha256 $cachePath) -ne $oid) {
    Write-Host "[whisper-model] downloading $BlobUrl ..."
    $tmp = "$cachePath.tmp"
    Invoke-WebRequest -Uri $BlobUrl -OutFile $tmp -UseBasicParsing
    $dl = (Get-FileHash -LiteralPath $tmp -Algorithm SHA256).Hash.ToLower()
    if ($dl -ne $oid) {
        Remove-Item -LiteralPath $tmp -Force
        throw "[whisper-model] downloaded sha $dl != upstream $oid"
    }
    Move-Item -LiteralPath $tmp -Destination $cachePath -Force
    Write-Host "[whisper-model] cached: $cachePath"
} else {
    Write-Host "[whisper-model] cache hit: $cachePath"
}

# 4. Place it at the modpack root for hemtt.
Copy-Item -LiteralPath $cachePath -Destination $Dest -Force
Write-Host "[whisper-model] provisioned -> $Dest"
