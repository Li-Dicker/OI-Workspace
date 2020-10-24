@echo on
:loop
makedata.exe > b.in
b.exe < b.in >  b1.out
b-dave.exe < b.in > b2.out
fc b1.out b2.out
if not errorlevel 1 goto loop
pause