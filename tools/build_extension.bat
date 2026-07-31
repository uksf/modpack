@echo off
REM Build the UKSF Arma extension (uksf_x64.dll).
REM
REM whisper-rs-sys runs bindgen at build time, which needs two header sources the bare build
REM shell lacks:
REM   1. MSVC / Windows SDK headers (stdio.h, ...) on INCLUDE -> provided by vcvars64.
REM      (cc finds MSVC on its own, but bindgen's libclang does not.)
REM   2. clang's own builtin headers (stdbool.h, ...) -> libclang locates these only when LLVM
REM      is on PATH; MSVC's INCLUDE does not reliably carry stdbool.h.
REM Without both, bindgen silently falls back to the crate's Linux-generated bindings, which
REM fail to compile under windows-msvc and break the whole modpack build.
REM
REM vswhere lives at a fixed Microsoft-guaranteed path and discovers VS dynamically, and LLVM is
REM referenced at its default install location, so this is not tied to any specific build machine.
REM Prereqs on any build box: Rust, VS Build Tools (Desktop C++ + Windows SDK), LLVM.
REM Extra args pass through to cargo (e.g. --release).
setlocal

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" ( echo ERROR: vswhere not found at "%VSWHERE%" & exit /b 1 )

set "VSINSTALL="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSINSTALL=%%i"
if not defined VSINSTALL ( echo ERROR: no Visual Studio with C++ tools found by vswhere & exit /b 1 )

call "%VSINSTALL%\VC\Auxiliary\Build\vcvars64.bat" >nul || exit /b 1

if exist "%ProgramFiles%\LLVM\bin\clang.exe" set "PATH=%ProgramFiles%\LLVM\bin;%PATH%"

REM Point bindgen's libclang at clang's builtin headers (stdbool.h, ...) explicitly; loaded as a
REM library it does not reliably self-locate its resource dir. -print-resource-dir keeps this
REM independent of the installed LLVM version.
set "CLANG_RES="
for /f "usebackq tokens=*" %%r in (`clang -print-resource-dir 2^>nul`) do set "CLANG_RES=%%r"
if defined CLANG_RES set "BINDGEN_EXTRA_CLANG_ARGS=-isystem "%CLANG_RES%\include""

cd /d "%~dp0..\extension" || exit /b 1
cargo build %*
exit /b %ERRORLEVEL%
