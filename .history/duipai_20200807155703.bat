@echo on
:loop
makedata > in.txt
std1 < in.txt > out1.txt
std2 < in.txt > out2.txt
fc out1.txt out2.txt
if not errorlevel 1 goto loop
pause