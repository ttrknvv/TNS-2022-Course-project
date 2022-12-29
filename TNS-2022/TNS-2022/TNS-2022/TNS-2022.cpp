#include <iostream>
#include "stdafx.h"

#include "PolishNotation.h"
#include "LexAnalysis.h"
#include "SemAnalysis.h"
#include "ERROR.h"
#include "PARM.h"
#include "IN.h"
#include "LOG.h"
#include "OUT.h"
#include "MFST.h"
#include "GenASM.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	//wchar_t b1[] = L"-in:D:\\2k1s\\KPO\\CurseProject\\TNS-2022\\TNS.txt";
	//wchar_t b2[] = L"-out:D:\\2k1s\\KPO\\CurseProject\\TNS-2022\\out.txt";
	//wchar_t b3[] = L"-log:D:\\2k1s\\KPO\\CurseProject\\TNS-2022\\log.txt";
	//_TCHAR* a[] = { (wchar_t*)b1, (wchar_t*)b2, (wchar_t*)b3 }; // SE_Lab20 -in:D:\2k1s\КПО\LP_Lab20(1)\222.txt -out:D:\2k1s\КПО\LP_Lab20(1)\out.txt -log:D:\2k1s\КПО\LP_Lab20(1)\log.txt
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	In::IN in;
	bool lexicalAnalysis;
	bool syntaxisAnalysis = false;
	bool semanticalAnalysis;
	try {
		//Parm::PARM parm = Parm::getparm(3, a); // проверка на ошибки
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log); // открыть поток журнала
		out = Out::getout(parm.out); // открыть поток выходных данных
		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок", ""); // напечать строку в журнал
		Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок", (wchar_t*)L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm); // получить параметры
		in = In::getin(parm.in); // открыть поток исходного файла
		Log::WriteIn(log, in);
		Out::WriteOut(in, out);

		LEX::TableLaI LaItable = LEX::LexicalAnalysis(in, out, log); // лексический анализ
		lexicalAnalysis = LEX::GetError(); // получить информацию о наличии ошибок после лексического анализа

		MFST::Mfst mfst(LaItable, GRB::getGreibach()); // инициализация правил синтаксиса
		if (!lexicalAnalysis) // если лексический анализ без ошибок
		{
			MFST_TRACE_START(log) // начать отладку
			syntaxisAnalysis = mfst.start(log); // получить информацию о наличии ошибок после лексического анализа
			
		}
		if (syntaxisAnalysis && !lexicalAnalysis) // если лексический и синтаксический без ошибок
		{
			SEM::SemanticAnalysis(LaItable, log); // синтаксический анализ
		}
		semanticalAnalysis = SEM::GetError();  // получить информацию о наличии ошибок после семантического анализа
		if (syntaxisAnalysis && !lexicalAnalysis && !semanticalAnalysis) // если все без ошибок, то вывести информацию
		{
			mfst.savededucation();
			mfst.printrules(log);
			POL::PolishStart(LaItable.lextable, LaItable.idtable); // выполнить польскую нотацию
			LEX::WriteLexTeable(LaItable.lextable, log); // вывести в файл таблицу лексем
			LEX::WriteIdTable(LaItable.idtable, log); // вывести в файл таблицу идентификаторов
			GEN::GenerationASM(LaItable, parm, log); // сгенерировать ассемблерный код
		}
		
		Log::Close(log);
		Out::CloseOut(out);
	}
	catch (Error::ERROR e) { // обработчик ошибок
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;
}

