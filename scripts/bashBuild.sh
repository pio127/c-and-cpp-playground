#!/bin/bash

# Cpp compilation with clang compiler
clang-cl $1 -o bin/outputCl.exe -std:c++14
cd bin
echo -------------------------------------------------------------
./outputCl.exe
echo
echo -------------------------------------------------------------
cd ..
