@echo on
:loop
makedata.exe > b.in
b.exe
b2.exe
fc b.out b1.out
if not errorlevel 1 goto loop
pause
goto loop