@echo off
cd /d "%~dp0"
echo Compiling Overtale...
gcc main.c util.c story.c -o overtale
if %errorlevel% neq 0 (
    echo [Error] Ada error saat compile!
    pause
) else (
    echo [Success] Running the game...
    echo -------------------------------
    overtale.exe
)

