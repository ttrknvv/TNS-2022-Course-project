#pragma once

#include "LexAnalysis.h"
#include "LOG.h"
#include "OUT.h"
#include "PARM.h"
#include "stdafx.h"
#include <vector>
// начало ассемблера
#define START ".586\n"\
".model flat, stdcall\n"\
"includelib libucrt.lib\n"\
"includelib kernel32.lib\n"\
"includelib D:\\2k1s\\KPO\\CurseProject\\ASMCourse\\Debug\\StandartLib.lib\n"\
"ExitProcess PROTO:DWORD \n"\
".stack 4096\n" 
// конец ассемблера
#define CLOSE "finish:\npush 0\ncall ExitProcess\nmain ENDP\nend main"
// прототипы стандартных функций
#define STANDART "\n writenum PROTO : DWORD\n"\
"\n writestr PROTO : DWORD\n"\
"\n writelnstr PROTO : DWORD\n"\
"\n writelnnum PROTO : DWORD\n"\
"\n getdata PROTO \n"\
"\n gettime PROTO \n"\
"\n getError PROTO \n"
// блок констант
#define CONST ".const\n\t\tnewline byte 13, 10, 0"
// блоак данных
#define DATA ".data\n\t\ttemp sdword ?\n\t\tbuffer byte 256 dup(0)"
// блок кода
#define CODE ".code"

namespace GEN
{
	void GenerationASM(LEX::TableLaI& tables, Parm::PARM& parm, Log::LOG& log);
	std::vector<std::string> GetBeginFile(LEX::TableLaI& table);
	std::string GetFunctionCode(LEX::TableLaI& table, int i, std::string fName);
	std::string GetReturn(LEX::TableLaI& table, int i, std::string fName);
	std::string GetCallFunc(LEX::TableLaI& table, Log::LOG log, int i);
	std::string GetIf(LEX::TableLaI table, int i);
	std::string GetExtantion(LEX::TableLaI table, Log::LOG log, int i);
	std::string GetCycle(LEX::TableLaI table, int i);
};