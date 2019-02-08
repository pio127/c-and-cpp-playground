@ECHO OFF
clang-cl %1 -o bin/outputCl.exe -std:c++14  /GX
if errorlevel 1 (
echo BUILD PROBLEM
) else (
cd bin
echo ------------------------------------------------------------
outputCl.exe
echo.
echo ------------------------------------------------------------
cd ..
)
echo.
echo.