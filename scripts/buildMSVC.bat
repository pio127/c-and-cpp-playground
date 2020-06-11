@ECHO OFF
call  "C:\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvars64.bat" x64
cl %1 -o bin/outputMSVC.exe -std:c++14
if errorlevel 1 (
echo BUILD PROBLEM
) else (
cd bin
echo -------------------------------------------------------------
outputMSVC.exe
echo.
echo -------------------------------------------------------------
cd ..
)
echo.