@ECHO OFF
g++ %1 -g -o bin/output.exe -Wall -std=c++14
if errorlevel 1 (
echo BUILD PROBLEM
) else (
cd bin
echo ------------------------------------------------------------
output.exe
echo.
echo ------------------------------------------------------------
cd ..
)
echo.
echo.