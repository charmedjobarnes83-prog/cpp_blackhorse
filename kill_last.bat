@echo off
REM Usage: kill_last.bat <process base name, without .exe>
REM
REM Kills any running instance of the given executable using Windows'
REM native taskkill (no PowerShell, no -Command, no quoting issues).
REM Always exits 0 so the build chain is never blocked by this step.

if "%~1"=="" exit /b 0

taskkill /F /IM "%~1.exe" >nul 2>&1

exit /b 0
