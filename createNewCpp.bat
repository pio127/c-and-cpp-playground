@ECHO OFF
IF NOT EXIST %1.cpp type TEMPLATE.cpp> %1.cpp
start notepad++ %1.cpp