#include "IT.h"

namespace IT
{
	IdTable Create(int size) // создать таблицу идентификаторов
	{
		if (size >= TI_MAXSIZE)
		{
			throw ERROR_THROW(200)
		}
		IdTable tableID;
		tableID.maxsize = TI_MAXSIZE;
		tableID.size = 0;
		tableID.table = new Entry[size];
		return tableID;
	}
	void Add(IdTable& idtable, Entry entry)  // добавить элемент в таблицу
	{
		if (idtable.size >= TI_MAXSIZE)
		{
			throw ERROR_THROW(200)
		}
		idtable.table[idtable.size++] = entry;
	}
	Entry GetEntry(IdTable& idtable, int n) // получить элемент таблицы идентификаторов
	{
		if (n >= idtable.size)
		{
			throw ERROR_THROW(202)
		}
		return idtable.table[n];
	}
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], IDDATATYPE type, IDTYPE type2, char* nameFunc) // проверка на наличие
	{
		if (type2 == IDTYPE::F || type2 == IDTYPE::PR || type2 == IDTYPE::BF)
		{
			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].iddatatype == type && idtable.table[i].idtype == type2 && strcmp(id, idtable.table[i].id) == 0
					&& strcmp(idtable.table[i].nameFunc, id) == 0)
				{
					return i;
				}
			}
		}
		else
		{
			for (int i = 0; i < idtable.size; i++)
			{
				if (strcmp(idtable.table[i].id, id) == 0 && idtable.table[i].iddatatype == type && idtable.table[i].idtype == type2
					&& strcmp(nameFunc, idtable.table[i].nameFunc) == 0)
				{
					return i;
				}
			}
		}
		return TI_NULLIDX;
	}
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], char* nameFunc)
	{
		for (int i = 0; i < idtable.size; i++)
		{
			if (strcmp(id, idtable.table[i].id) == 0 && (strcmp(nameFunc, idtable.table[i].nameFunc) == 0 
				|| strcmp(id, idtable.table[i].nameFunc) == 0))
			{
				return i;
			}
		}
		return TI_NULLIDX;
	}
	void Delete(IdTable& idtable) // удаление таблицы
	{
		idtable.size = 0;
		idtable.maxsize = 0;
		delete []idtable.table;
	}
	int findLiteral(IdTable& idtable, IDDATATYPE type, char* valueS)
	{
		if (type == IDDATATYPE::UNSINT32)
		{
			int a = atoi(valueS);
			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].idtype == IDTYPE::L && idtable.table[i].iddatatype == type && idtable.table[i].value.vunsint32 == a)
				{
					return i;
				}
			}
		}
		else if (type == IDDATATYPE::LINE)
		{
			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].idtype == IDTYPE::L && idtable.table[i].iddatatype == type && strcmp(idtable.table[i].value.vline->str, valueS) == 0)
				{
					return i;
				}
			}
		}
		else if (type == IDDATATYPE::SYMBOL)
		{
			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].idtype == IDTYPE::L && idtable.table[i].iddatatype == type && idtable.table[i].value.vsymbol == valueS[0])
				{
					return i;
				}
			}
		}
		else if (type == IDDATATYPE::BOOLEAN)
		{
			char a[] = "false";
			char b[] = "true";
			bool point;
			if (strcmp(a, valueS) == 0)
			{
				point = false;
			}
			else
			{
				point = true;
			}
			for (int i = 0; i < idtable.size; i++)
			{
				if (idtable.table[i].idtype == IDTYPE::L && idtable.table[i].iddatatype == type && idtable.table[i].value.vboolean == point)
				{
					return i;
				}
			}
		}
		return TI_NULLIDX;
	}
}