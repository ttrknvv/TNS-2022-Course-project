chcp 1251 >nul
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
call "D:\2k1s\KPO\CurseProject\TNS-2022\TNS-2022\Debug\TNS-2022.exe" -in:"D:\2k1s\KPO\CurseProject\TNS-2022\TNS.txt" -log:"D:\2k1s\KPO\CurseProject\TNS-2022\log.txt" m l i
pause
ml /c /coff D:\2k1s\KPO\CurseProject\ASMCourse\ASMCourse\code.asm
link /OPT:NOREF /DEBUG D:\2k1s\KPO\CurseProject\TNS-2022\code.obj /SUBSYSTEM:CONSOLE /NODEFAULTLIB:library
call D:\2k1s\KPO\CurseProject\TNS-2022\code.exe
pause