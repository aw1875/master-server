@echo off
setlocal

SET SCRIPT_DIR=%~dp0
SET SCRIPT_DIR=%SCRIPT_DIR:~0,-1%

SET "ARCH=%~1" & IF "%ARCH%"=="" SET "ARCH=x64"
SET "VALID_ARCHS=x64 x86 arm64"
SET "ARCH_VALID=0"
for %%A in (%VALID_ARCHS%) do (
    IF "%ARCH%"=="%%A" SET "ARCH_VALID=1"
)
if "%ARCH_VALID%"=="0" (
    echo "Invalid arch: %ARCH%. Valid archs: %VALID_ARCHS%"
    exit /b 1
)

SET "CONFIG=%~2" & IF "%CONFIG%"=="" SET "CONFIG=release"
SET "VALID_CONFIGS=debug release"
SET "CONFIG_VALID=0"
for %%C in (%VALID_CONFIGS%) do (
    IF "%CONFIG%"=="%%C" SET "CONFIG_VALID=1"
)
if "%CONFIG_VALID%"=="0" (
    echo "Invalid config: %CONFIG%. Valid configs: %VALID_CONFIGS%"
    exit /b 1
)

IF NOT EXIST "%SCRIPT_DIR%\..\..\build" (
    echo "Please run the .\scripts\windows\setup.bat first"
    exit /b 1
)

echo "Building %CONFIG%_%ARCH% for Windows"
pushd "%SCRIPT_DIR%\..\..\build"
msbuild /m /v:minimal /p:Configuration=%CONFIG% /p:Platform=%ARCH% "%SCRIPT_DIR%\..\..\build\alterware-master.sln"
popd
