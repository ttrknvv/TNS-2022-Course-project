#pragma once

#include "stdafx.h"
#include "ERROR.h"

#define LEXEMA_FIXSIZE 1 // ������������� ������ �������
#define LT_MAXSIZE 4096 // ������������ ���������� ����� � ������� ������
#define LI_TI_NULLIDX 0xffffffff // ��� �������� ������� ���������������
#define LEX_UNSINT32 't' // ������� ��� unsint32
#define LEX_SYMBOL 't' // ������� ��� symbol
#define LEX_LINE 't' // ������� ���� line
#define LEX_BOOLEAN 't' // ������� ���� boolean
#define LEX_ID 'i' // ������� ��������������
#define LEX_LITERAL 'l' // ������� ��������
#define LEX_FUNCTION 'f' // �������� �������
#define LEX_PROCEDURE 'p' // ������� ���������
#define LEX_IF '?' // ������� �������
#define LEX_RETURN 'r' // ������� ��������� return
#define LEX_SEMICOLON ';' // ������� ����� � �������
#define LEX_COMMA ',' // ������� �������
#define LEX_LEFTBRACE '{' // ������� ����� �������� ������
#define LEX_BRACELET '}' // ������� ������ �������� ������
#define LEX_LEFTTHESIS '(' // ������� ����� ������� ������
#define LEX_RIGHTTHESIS ')' // ������� ������ ������� ������
#define LEX_SQUAREBRL '[' // ������� ����� ���������� ������
#define LEX_SQUAREBRR ']' // ������� ������ ���������� ������
#define LEX_PLUS '+' // ������� �����
#define LEX_MINUS '-' // ������� ������
#define LEX_STAR '*' // ������� ���������
#define LEX_DIRSLASH '/' // ������� �������
#define LEX_MAIN 'm' // ������� ������� MAIN
#define LEX_GRAB '=' // ������� ����������
#define LEX_SEPARATOR '|' // ������� ����������
#define LEX_SHIFTLEFT 'q' // ������� ������ �����
#define LEX_SHIFTRIGHT 'w' // ������� ������ �����
#define LEX_MORE '>' // ������� ��������� ������
#define LEX_LESS '<' // ������� ��������� ������
#define LEX_EQUALS 'e' // ������� ��������� ���������
#define LEX_OTHERWISE '!' // ������� otherwise
#define LEX_WRITELN 'n' // ������� writeln
#define LEX_WRITE 'k' // ������� write
#define LEX_ITERATION 'c' // ����
 
namespace LT
{
	struct Entry // ������ ������� ������
	{
		char lexema�[LEXEMA_FIXSIZE]{}; // �������
		int sn = 0; // ����� ������ � �������� ������
		int idxTI = LI_TI_NULLIDX; // ������ � ������� ��������������� ��� LT_TI_NULLIDX
	};

	struct LexTable // ��������� ������� ������
	{
		int maxsize = 0; // ������� ������� ������ < LT_MAXSIZE
		int size = 0; // ������� ������ ������� ������ < maxsize
		Entry* table = NULL; // ������ ����� ������� ������
	};

	LexTable Create(int size); // ������� ������� ������
	void Add(LexTable& lextable, Entry entry); // �������� ������ � ������� ������
	Entry GetEntry(LexTable& lextable, int n); // �������� ������ �� ������� ������
	void Delete(LexTable& lextable); // ������� ������� ������(���������� ������)
}