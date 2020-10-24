@echo on
:loop
makedata > b.in
b-make < b.in > b.out
b-dave < b.in > b1.out
fc b.in b1.in
if not errorlevel 1 goto loop
pause
