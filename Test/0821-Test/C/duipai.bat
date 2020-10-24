@echo on
:loop
makedata > c.in
c-maz < c.in > c.out
c-dave < c.in > c1.out
fc c.out c1.out
if not errorlevel 1 goto loop
pause
