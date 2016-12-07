@echo off
REM grep -l- -d+ TEST_BEGIN ..\src\*.c >collect.log
REM otthoni 
grep -r TEST_BEGIN ../src/* >collect.log
perl collect.pl
