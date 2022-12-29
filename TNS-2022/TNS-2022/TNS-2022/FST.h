#pragma once

#include "stdafx.h"

namespace FST
{
	struct RELATION // ����� : ������ -> ������� ����� ��������� ��
	{
		char symbol; // ������ ��������
		short nnode; // ����� ������� �������
		RELATION(const char c = 0x00, short ns = NULL);
	};
	struct NODE // ������� ������ ���������
	{
		short n_relation; // ���������� ����������� ������
		RELATION* relations; // ����������� �����
		NODE();
		NODE(short n, RELATION rel, ...);
	};
	struct FST // ������������������� �������� �������
	{
		const char* string; // �������( � ����� 0�00)
		short position; // ������� ������� � �������
		short nstates; // ���������� ��������� ��������
		NODE* nodes; // ���� ��������� 0 - ���������, nstates - 1 - ��������
		short* rstates; // ��������� ��������� �������� �� ������ �������
		FST(const char* s, short ns, NODE n, ...);
	};
	bool step(FST& fst, short*& rstates);
	bool execute(FST& fst); // ��������� ������������� �������
}