#pragma once

#include "stdafx.h"
#include "ERROR.h"

#define LEXEMA_FIXSIZE 1 // фиксированный размер лексемы
#define LT_MAXSIZE 4096 // маскимальное количество строк в таблице лексем
#define LI_TI_NULLIDX 0xffffffff // нет элемента таблицы идентификаторов
#define LEX_UNSINT32 't' // лексема тип unsint32
#define LEX_SYMBOL 't' // лексема тип symbol
#define LEX_LINE 't' // лексема типа line
#define LEX_BOOLEAN 't' // лексема типа boolean
#define LEX_ID 'i' // лексмеа идентификатора
#define LEX_LITERAL 'l' // лексема литерала
#define LEX_FUNCTION 'f' // лсексема функции
#define LEX_PROCEDURE 'p' // лексема процедуры
#define LEX_IF '?' // лексема услови€
#define LEX_RETURN 'r' // лексема оператора return
#define LEX_SEMICOLON ';' // лексема точки с зап€той
#define LEX_COMMA ',' // лексема зап€той
#define LEX_LEFTBRACE '{' // лексема левой фигурной скобки
#define LEX_BRACELET '}' // лексема правой фигурной скобки
#define LEX_LEFTTHESIS '(' // лексема левой круглой скобки
#define LEX_RIGHTTHESIS ')' // лексема правой круглой скобки
#define LEX_SQUAREBRL '[' // лексема левой квадратной скобки
#define LEX_SQUAREBRR ']' // лексема правой квадратной скобки
#define LEX_PLUS '+' // лексема плюса
#define LEX_MINUS '-' // лексема минуса
#define LEX_STAR '*' // лексема умножени€
#define LEX_DIRSLASH '/' // лексема делени€
#define LEX_MAIN 'm' // лексема функции MAIN
#define LEX_GRAB '=' // лексема присвоени€
#define LEX_SEPARATOR '|' // лексема сепаратора
#define LEX_SHIFTLEFT 'q' // лексема сдвига влево
#define LEX_SHIFTRIGHT 'w' // лексема сдвига право
#define LEX_MORE '>' // лексема оператора больше
#define LEX_LESS '<' // лексема оператора меньше
#define LEX_EQUALS 'e' // лексема оператора сравнени€
#define LEX_OTHERWISE '!' // лексема otherwise
#define LEX_WRITELN 'n' // лексема writeln
#define LEX_WRITE 'k' // лексема write
#define LEX_ITERATION 'c' // цикл
 
namespace LT
{
	struct Entry // строка таблицы лексем
	{
		char lexemaх[LEXEMA_FIXSIZE]{}; // лексема
		int sn = 0; // номер строки в исходном тексте
		int idxTI = LI_TI_NULLIDX; // индекс в таблице идентефикаторов или LT_TI_NULLIDX
	};

	struct LexTable // экземпл€р таблицы лексем
	{
		int maxsize = 0; // емкость таблицы лексем < LT_MAXSIZE
		int size = 0; // текущий размер таблицы лексем < maxsize
		Entry* table = NULL; // массив строк таблицы лексем
	};

	LexTable Create(int size); // создать таблицы лексем
	void Add(LexTable& lextable, Entry entry); // добавить строку в таблицу лексем
	Entry GetEntry(LexTable& lextable, int n); // получить строку из таблицы лексем
	void Delete(LexTable& lextable); // удалить таблицу лексем(освободить пам€ть)
}