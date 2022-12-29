#include "LT.h"

namespace LT
{
	LexTable Create(int size)
	{
		if (size >= LT_MAXSIZE)
		{
			throw ERROR_THROW(203)
		}
		LexTable lextable;
		lextable.maxsize = LT_MAXSIZE;
		lextable.size = 0;
		lextable.table = new Entry[size];
		return lextable;
	}
	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size >= lextable.maxsize)
		{
			throw ERROR_THROW(204)
		}
		lextable.table[lextable.size++] = entry;
	}
	Entry GetEntry(LexTable& lextable, int n)
	{
		if (n >= lextable.size)
		{
			throw ERROR_THROW(205)
		}
		return lextable.table[n];
	}
	void Delete(LexTable& lextable)
	{
		lextable.maxsize = 0; 
		lextable.size = 0;
		delete []lextable.table;
	}
}