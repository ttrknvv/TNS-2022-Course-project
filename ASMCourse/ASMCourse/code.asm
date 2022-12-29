.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib D:\2k1s\KPO\CurseProject\ASMCourse\Debug\StandartLib.lib
ExitProcess PROTO:DWORD 
.stack 4096


 writenum PROTO : DWORD

 writestr PROTO : DWORD

 writelnstr PROTO : DWORD

 writelnnum PROTO : DWORD

 getdata PROTO 

 gettime PROTO 

 getError PROTO 

.const
		newline byte 13, 10, 0
		L0 sdword 1
		L1 byte ' ', 0
		L2 byte 'Вызов функции нахождения наименьшего: ', 0
		L3 sdword 99
		L4 sdword 1000
		L5 byte 'Вызов процедуры вывода последовательности чисел: ', 0
		L6 sdword 5
		L7 sdword 500
		L8 sdword 600
		L9 byte 'Результат выражения 500 - 600: ', 0
		L10 byte 'Н', 0
		L11 byte 'Курсовой проект TNS-2022', 0
		L12 sdword 12345
		L13 dword 1
		L14 byte 'Вывод основных типов данных: ', 0
		L15 byte 'Сдвиг числа ', 0
		L16 byte ' на 3 разряда влево: ', 0
		L17 sdword 3
		L18 byte ' на 3 разряда вправо: ', 0
		L19 sdword 7
		L20 byte 'Значение выражения: ', 0
		L21 dword 0
		L22 byte 'Значение logical true', 0
		L23 byte 'Значение logical false', 0
		L24 byte 'Тестирование закончилось!', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
		resultFindMin sdword 0
		iPrintNumb sdword 0
		resultMAIN sdword 0
		exprMAIN sdword 0
		test1MAIN dword ?
		test2MAIN dword ?
		test3MAIN sdword 0
		test4MAIN dword 0
		test5MAIN sdword 0
		test6MAIN sdword 0
		timeNowMAIN dword ?
.code

FindMin PROC, 
	xFindMin : sdword, yFindMin : sdword
 
push ebx
push edx

push xFindMin

pop ebx
cmp ebx, 0
jnl minus0
neg ebx
minus0:
mov resultFindMin, ebx

mov edx, xFindMin
cmp edx, yFindMin

jl right1
jg wrong1
right1:
push xFindMin

pop ebx
cmp ebx, 0
jnl minus1
neg ebx
minus1:
mov resultFindMin, ebx

jmp next1
wrong1:
push yFindMin

pop ebx
cmp ebx, 0
jnl minus2
neg ebx
minus2:
mov resultFindMin, ebx

next1:

pop edx
pop ebx
mov eax, resultFindMin
ret
FindMin ENDP


PrintNumb PROC, 
	nPrintNumb : sdword
 
push ebx
push edx

push L0

pop ebx
cmp ebx, 0
jnl minus3
neg ebx
minus3:
mov iPrintNumb, ebx

mov edx, iPrintNumb
cmp edx, nPrintNumb

jl cycle1
jmp cyclenext1
cycle1:


push iPrintNumb
call writenum


push offset L1
call writestr

push iPrintNumb
push L0
pop ebx
pop eax
add eax, ebx
push eax

pop ebx
cmp ebx, 0
jnl minus4
neg ebx
minus4:
mov iPrintNumb, ebx

mov edx, iPrintNumb
cmp edx, nPrintNumb

jl cycle1
cyclenext1:

pop edx
pop ebx
ret
PrintNumb ENDP


main PROC

push offset L2
call writestr


 push L4
 push L3
 call FindMin
push eax

pop ebx
cmp ebx, 0
jnl minus5
neg ebx
minus5:
mov resultMAIN, ebx


push resultMAIN
call writelnnum


push offset L5
call writestr


 push L6
 call PrintNumb


push offset L1
call writelnstr

push L7
push L8
pop ebx
pop eax
sub eax, ebx
push eax

pop ebx
cmp ebx, 0
jnl minus6
neg ebx
minus6:
mov exprMAIN, ebx


push offset L9
call writestr


push exprMAIN
call writelnnum

mov test1MAIN, offset L10
mov test2MAIN, offset L11
push L12

pop ebx
cmp ebx, 0
jnl minus7
neg ebx
minus7:
mov test3MAIN, ebx


push L13
pop ebx
mov test4MAIN, ebx


push offset L14
call writestr


push test1MAIN
call writestr


push offset L1
call writestr


push test2MAIN
call writestr


push offset L1
call writestr


push test3MAIN
call writenum


push offset L1
call writestr


push test4MAIN
call writelnnum

push L0

pop ebx
cmp ebx, 0
jnl minus8
neg ebx
minus8:
mov test5MAIN, ebx


push offset L15
call writestr


push test5MAIN
call writenum


push offset L16
call writestr

push test5MAIN
push L17
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
cmp ebx, 0
jnl minus9
neg ebx
minus9:
mov test5MAIN, ebx


push test5MAIN
call writelnnum


push offset L15
call writestr


push test5MAIN
call writenum


push offset L18
call writestr

push test5MAIN
push L17
pop ebx 
pop eax 
mov cl, bl 
shr eax, cl
push eax

pop ebx
cmp ebx, 0
jnl minus10
neg ebx
minus10:
mov test5MAIN, ebx


push test5MAIN
call writelnnum

push test5MAIN
push test3MAIN
push L6
pop ebx
pop eax
cmp ebx, 0

jnz nozero0
call getError
jmp finish
nozero0:
cdq
idiv ebx
push eax
pop ebx
pop eax
add eax, ebx
push eax

 push L19
 push L17
 call FindMin
push eax
push L6
pop ebx
pop eax
imul eax, ebx
push eax
pop ebx
pop eax
sub eax, ebx
push eax
push L0
pop ebx 
pop eax 
mov cl, bl 
shl eax, cl
push eax

pop ebx
cmp ebx, 0
jnl minus11
neg ebx
minus11:
mov test6MAIN, ebx


push offset L20
call writestr


push test6MAIN
call writelnnum


push L21
pop ebx
mov test4MAIN, ebx

mov edx, test4MAIN
cmp edx, 1
jz right2
jnz wrong2
right2:

push offset L22
call writelnstr

jmp next2
wrong2:

push offset L23
call writelnstr

next2:

 call gettime
mov timeNowMAIN, eax
xor eax, eax

push timeNowMAIN
call writelnstr


 call getdata
mov timeNowMAIN, eax
xor eax, eax

push timeNowMAIN
call writelnstr


push offset L24
call writelnstr

finish:
push 0
call ExitProcess
main ENDP
end main
