#pragma once

#include "stdafx.h"
#include "IN.h"
#include "ERROR.h"
#include "LT.h"
#include "IT.h"
#include "PARM.h"
#include "stdafx.h"
#include "OUT.h"
#include "FST.h"
#include "LOG.h"

namespace LEX
{
	struct TableLaI // таблица токенов
	{  
		LT::LexTable lextable;  // таблица лексем
		IT::IdTable idtable; // таблица идентификаторов
	};

	struct UsingType // флаги использования определенных типов
	{
		bool UseUnsInt32 = false;
		bool UseSymbol = false;
		bool UseLine = false;
		bool UseBoolean = false;
		bool UseFunc = false;
		bool UseMain = false;
		bool UseProc = false;
		bool UseLeftFigure = false;
		bool UseRightFigure = false;
		bool UseLeftCircle = false;
		bool UseRightCircle = false;
		bool DataInFunc = false;
		bool UseIf = false;
		bool Error = false;
		bool UseCycle = false;
	};

	bool typeIteration(char type[]);
	bool typeUnsInt32(char type[]);
	bool typeSymbol(char type[]);
	bool typeLine(char type[]);
	bool typeBoolean(char type[]);
	bool typeID(char type[]); 
	bool typeLitInt(char type[]); 
	bool typeLitIntMinus(char type[]);
	bool typeLitStr(char type[]); 
	bool typeLitTrue(char type[]); 
	bool typeLitFalse(char type[]); 
	bool typeLitSymbol(char type[]); 
	bool typeWhen(char type[]); 
	bool typeFunc(char type[]);
	bool typeProc(char type[]);
	bool typeRet(char type[]);
	bool typeMain(char type[]);
	bool typeLeftFigure(char type[]);
	bool typeRightFigure(char type[]);
	bool typeLeftCircle(char type[]);
	bool typeRightCircle(char type[]);
	bool typeSemicolon(char type[]);
	bool typeComma(char type[]);
	bool typePlus(char type[]);
	bool typeMinus(char type[]);
	bool typeStar(char type[]);
	bool typeDirSlash(char type[]);
	bool typeGrab(char type[]);
	bool typeEquals(char type[]);
	bool typeLexSepar(char type[]);
	bool typeLexMore(char type[]);
	bool typeLexLess(char type[]);
	bool typeShiftLeft(char type[]);
	bool typeShiftRight(char type[]);
	bool typeSquareBrR(char type[]);
	bool typeWriteln(char type[]);
	bool typeWrite(char type[]);
	bool typeSquareBrL(char type[]);
	bool typeBaseFunc(char type[]);
	bool typeBaseFunc2(char type[]);

	TableLaI LexicalAnalysis(In::IN inputData, Out::OUT out, Log::LOG log);
	In::Word* EditTextInWords(In::IN& data, Log::LOG log);
	void inputWord(In::IN& data, char* word, short col, short line);
	void inputLexema(int line, char lex);
	void inputLexForLit(char lex, In::Word word, IT::IDDATATYPE a, int& countL);
	void inputLexId(char lex, In::Word word, IT::IDDATATYPE a, IT::IDTYPE type, char* nameFunc);
	void inputLexId(char lex, In::Word word, int id);
	void WriteLexTeable(LT::LexTable lextable, Log::LOG log);
	void WriteIdTable(IT::IdTable idtable, Log::LOG log);
	bool GetError();
}