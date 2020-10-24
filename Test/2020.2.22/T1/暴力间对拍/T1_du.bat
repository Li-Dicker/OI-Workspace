@echo off
:loop
echo 5000|T1_makedata.exe > in.txt
T1_bl2 < in.txt >out1.txt
T1_bl3 < in.txt >out2.txt
fc out1.txt out2.txt
if not errorlevel 1 goto loop
pause
goto loop