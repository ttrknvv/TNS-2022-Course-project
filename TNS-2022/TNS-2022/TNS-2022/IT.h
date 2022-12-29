#pragma once

#include "stdafx.h"
#include "ERROR.h"

#define ID_MAXSIZE 15 // ������������ ���������� �������� � ��������������
#define TI_MAXSIZE 4096 // ������������ ���������� ����� � ������� ���������������
#define  TI_UNSINT32_DEFAULT 0x00000000 // �������� �� ��������� ��� ���� unsint32
#define TI_SYMBOL_DEFAULT 0x00 // �������� �� ��������� ��� ���� symbol
#define TI_LINE_DEFAULT 0X00 // �������� �� ��������� ��� ���� line
#define TI_LINE_DEFAULT "false" // �������� �� ��������� ��� ���� boolean
#define TI_NULLIDX 0Xffffffff // ��� �������� ������� ���������������
#define TI_STR_MAXSIZE 255 // ������������ ����� ������
#define PARAMS_COUNTMAX 5 // ������������ ���������� ����������

namespace IT // ������� ���������������
{
	enum IDDATATYPE { UNSINT32 = 1, SYMBOL = 2, LINE = 3, BOOLEAN = 4, NO = 5 }; // ���� ������ ���������������
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, PR = 5, BF = 6 }; // ���� ��������������: ����������, �������, ��������, �������, ���������, ������� �������

	struct Entry // ������ ������� ���������������
	{
		int idxfirstLE = 0; // ������ ������ ������ � ������� ������
		char id[ID_MAXSIZE]{}; // �������������(���������� �� ID_MAXSIZE)
		char nameFunc[ID_MAXSIZE]{}; // ��� �������
		IDDATATYPE iddatatype{}; // ��� ������
		IDTYPE idtype{}; // ��� ��������������E
		union
		{
			unsigned int vunsint32; // �������� ���� unsint32
			struct
			{
				char len{}; // ����� ������
				char str[TI_STR_MAXSIZE - 1]{}; // �������� ������
			} vline[TI_STR_MAXSIZE];
			char vsymbol; // �������� ���� symbol
			bool vboolean = false; // �������� ���� boolean
			struct
			{
				int count;
				IDDATATYPE* typeP;
			} t;
		} value{};
	};
	struct IdTable
	{
		int maxsize; // ������������ ������ ������� ���������������
		int size{}; // ������� ������ ������� ���������������
		Entry* table; // ��������� �� ��������������
	};

	IdTable Create(int size); // ������� ������� ���������������
	void Add(IdTable& idtable, Entry entry); // �������� ������� � �������
	Entry GetEntry(IdTable& idtable, int n); // �������� ������� ������� ���������������
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], IDDATATYPE type, IDTYPE type2, char* nameFunc); // �������� �� �������
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], char* nameFunc);
	void Delete(IdTable& idtable); // �������� �������

	int findLiteral(IdTable& idtable, IDDATATYPE type, char* valueS);
}