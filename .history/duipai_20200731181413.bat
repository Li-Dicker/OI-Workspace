@echo on
:loop
makedata > in.txt
test < in.txt > out1.txt
test2 < in.txt > out2.txt
fc out1.txt out2.txt
if not errorlevel 1 goto loop
pause
