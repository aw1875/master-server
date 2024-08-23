@echo off

SET SCRIPT_DIR=%~dp0
SET SCRIPT_DIR=%SCRIPT_DIR:~0,-1%

git submodule update --init --recursive
"%SCRIPT_DIR%\..\..\tools\premake5.exe" vs2022
