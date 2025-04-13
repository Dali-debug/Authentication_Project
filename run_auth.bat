@echo off
g++ main.cpp user.cpp file_handler.cpp hash.cpp -lssl -lcrypto -o auth_system
if %ERRORLEVEL% NEQ 0 (
    echo Compilation failed.
    pause
    exit /b %ERRORLEVEL%
)
auth_system.exe
pause
