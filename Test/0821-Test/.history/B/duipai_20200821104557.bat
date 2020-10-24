@echo on
:loop
makedata > b.in
b-make < b.in > b.out
b-dave < b.in > b1.out
fc b.out b1.out
if not errorlevel 1 goto loop
pause
