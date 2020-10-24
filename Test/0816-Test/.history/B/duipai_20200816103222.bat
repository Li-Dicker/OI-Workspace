@echo on
:loop
makedata > b.in
b < b.in b1.out
b-dave < b.in > b2.out
fc b1.out b2.out
if not errorlevel 1 goto loop
pause