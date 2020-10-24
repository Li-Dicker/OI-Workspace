@echo on
:loop
makedata > b.in
b-make < b.in > b.out
b-dave
fc b.in b1.in
if not errorlevel 1 goto loop
pause
