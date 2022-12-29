chcp 1251 >nul
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
ml /c /coff D:\2k1s\KPO\CurseProject\ASMCourse\ASMCourse\code.asm
link /OPT:NOREF /DEBUG D:\2k1s\KPO\CurseProject\ASMCourse\ASMCourse\Debug\code.obj /SUBSYSTEM:CONSOLE /NODEFAULTLIB:library
call D:\2k1s\KPO\CurseProject\ASMCourse\Debug\ASMCourse.exe
pause