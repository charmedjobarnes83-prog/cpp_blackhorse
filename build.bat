@echo off
setlocal enabledelayedexpansion

REM Usage: build.bat <absolute path to the main .cpp file>
REM
REM Builds the given .cpp together with every other .cpp in the same
REM folder that does NOT contain "int main". This means:
REM   - open any exercise file (has main) and run it -> compiles fine alone
REM   - drop new implementation files (no main, e.g. class_line.cpp)
REM     into the same folder -> they are picked up automatically.
REM No need to edit tasks.json when adding new files.

set "MAIN=%~1"
set "MAINDIR=%~dp1"
set "ROOT=%~dp0"
set "OUTDIR=%ROOT%bin"
set "HEADERDIR=%ROOT%head"
if not exist "%OUTDIR%" mkdir "%OUTDIR%"

set "SRCS="
for %%f in ("%MAINDIR%*.cpp") do (
    findstr /m /c:"int main" "%%f" >nul 2>&1
    if errorlevel 1 set "SRCS=!SRCS! "%%f""
)

REM 全链路统一 UTF-8：源码 UTF-8 -> exe 内字符串保持 UTF-8。
REM 终端显示由 VS Code 工作区设置里的终端 profile 自动 chcp 65001 配合；
REM F5 调试管道天然按 UTF-8 解读，两种运行方式都不乱码。
g++ -fdiagnostics-color=always -g "%MAIN%" %SRCS% -I "%HEADERDIR%" -o "%OUTDIR%\%~n1.exe" -std=c++17 -finput-charset=UTF-8 -fexec-charset=UTF-8
