#pragma once

#include "stdafx.h"
#include "ERROR.h"

#define ID_MAXSIZE 15 // максимальное количество символов в идентификаторе
#define TI_MAXSIZE 4096 // максимальное количество строк в таблице идентификаторов
#define  TI_UNSINT32_DEFAULT 0x00000000 // значение по умолчанию для типа unsint32
#define TI_SYMBOL_DEFAULT 0x00 // значение по умолчанию для типа symbol
#define TI_LINE_DEFAULT 0X00 // значение по умолчанию для типа line
#define TI_LINE_DEFAULT "false" // значение по умолчанию для типа boolean
#define TI_NULLIDX 0Xffffffff // нет элемента таблицы идентификаторов
#define TI_STR_MAXSIZE 255 // максимальная длина строки
#define PARAMS_COUNTMAX 5 // максимальное количество параметром

namespace IT // таблица идентификаторов
{
	enum IDDATATYPE { UNSINT32 = 1, SYMBOL = 2, LINE = 3, BOOLEAN = 4, NO = 5 }; // типы данных идентификаторов
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, PR = 5, BF = 6 }; // типы иднтификаторов: переменная, функция, параметр, литерал, процедура, базовая функция

	struct Entry // строка таблицы идентификаторов
	{
		int idxfirstLE = 0; // индекс первой строки в таблице лексем
		char id[ID_MAXSIZE]{}; // идентификатор(отсекается до ID_MAXSIZE)
		char nameFunc[ID_MAXSIZE]{}; // имя функции
		IDDATATYPE iddatatype{}; // тип данных
		IDTYPE idtype{}; // тип идентификатораE
		union
		{
			unsigned int vunsint32; // значение типа unsint32
			struct
			{
				char len{}; // длина строки
				char str[TI_STR_MAXSIZE - 1]{}; // значение строки
			} vline[TI_STR_MAXSIZE];
			char vsymbol; // значение типа symbol
			bool vboolean = false; // значение типа boolean
			struct
			{
				int count;
				IDDATATYPE* typeP;
			} t;
		} value{};
	};
	struct IdTable
	{
		int maxsize; // максимальный размер таблицы идентификаторов
		int size{}; // текущий размер таблицы идентификаторов
		Entry* table; // указатель на идентификаторы
	};

	IdTable Create(int size); // создать таблицу идентификаторов
	void Add(IdTable& idtable, Entry entry); // добавить элемент в таблицу
	Entry GetEntry(IdTable& idtable, int n); // получить элемент таблицы идентификаторов
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], IDDATATYPE type, IDTYPE type2, char* nameFunc); // проверка на наличие
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], char* nameFunc);
	void Delete(IdTable& idtable); // удаление таблицы

	int findLiteral(IdTable& idtable, IDDATATYPE type, char* valueS);
}