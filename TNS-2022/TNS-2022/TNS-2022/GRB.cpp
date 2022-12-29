#include "GRB.h"
#define GRB_ERROR_SERIES 300
namespace GRB
{
	Greibach greibach(NS('S'), TS('$'),
		16,
		Rule(NS('S'), GRB_ERROR_SERIES + 0, 5, // программная конструкция
			Rule::Chain(7, TS('f'), TS('t'), TS('i'), NS('P'), NS('T'), TS(';'), NS('S')),
			Rule::Chain(6, TS('f'), TS('t'), TS('i'), NS('P'), NS('T'), NS('S')),
			Rule::Chain(5, TS('p'), TS('i'), NS('P'), NS('J'), NS('S')),
			Rule::Chain(5, TS('m'), TS('{'), NS('K'), TS('}'),TS(';')),
			Rule::Chain(4, TS('m'), TS('{'), NS('K'), TS('}'))
		),
		Rule(NS('P'), GRB_ERROR_SERIES + 1, 2, // конструкция параметров функции
			Rule::Chain(3, TS('('), NS('L'), TS(')')),
			Rule::Chain(2, TS('('), TS(')'))
		),
		Rule(NS('L'), GRB_ERROR_SERIES + 2, 2, // список параметров функции
			Rule::Chain(2, TS('t'), TS('i')),	
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('L'))
		),
		Rule(NS('T'), GRB_ERROR_SERIES + 3, 4,				// тело функции
			Rule::Chain(5, TS('{'), TS('r'), NS('D'), TS(';'), TS('}')),
			Rule::Chain(6, TS('{'), NS('K'), TS('r'), NS('D'), TS(';'), TS('}')),
			Rule::Chain(6, TS('{'), TS('r'), NS('D'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(7, TS('{'), NS('K'), TS('r'), NS('D'), TS(';'), TS('}'), TS(';'))
		),
		Rule(NS('D'), GRB_ERROR_SERIES + 4, 2,				// требование только идентификатора или литерала
			Rule::Chain(1, TS('l')),
			Rule::Chain(1, TS('i'))
		),
		Rule(NS('K'), GRB_ERROR_SERIES + 5, 18,				// конструкция тела функции
			Rule::Chain(6, TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('K')),  //
			Rule::Chain(4, TS('t'), TS('i'), TS(';'), NS('K')), //
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('K')),//
			Rule::Chain(4, TS('i'), NS('C'), TS(';'), NS('K')), //
			Rule::Chain(5, TS('t'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('t'), TS('i'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('i'), NS('C'), TS(';')),
			Rule::Chain(5, TS('?'), NS('Z'), NS('R'), NS('M'), NS('K')),  //
			Rule::Chain(3, TS('?'), NS('Z'), NS('R')),
			Rule::Chain(4, TS('?'), NS('Z'), NS('R'), NS('K')), //
			Rule::Chain(4, TS('?'), NS('Z'), NS('R'), NS('M')),
			Rule::Chain(3, TS('c'), NS('Z'), NS('R')),
			Rule::Chain(4, TS('c'), NS('Z'), NS('R'), NS('K')),
			Rule::Chain(3, TS('k'), NS('D'), TS(';')),
			Rule::Chain(3, TS('n'), NS('D'), TS(';')),
			Rule::Chain(4, TS('k'), NS('D'), TS(';'), NS('K')),
			Rule::Chain(4, TS('n'), NS('D'), TS(';'), NS('K'))
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 6, 8, // арифметические выражения языка
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(5, TS('('), NS('E'), TS(')'), NS('A'), NS('E')),
			Rule::Chain(3, TS('i'), NS('A'), NS('E')),
			Rule::Chain(4, TS('i'), NS('C'), NS('A'), NS('E')),
			Rule::Chain(2, TS('i'), NS('C')),
			Rule::Chain(3, TS('l'), NS('A'), NS('E'))
		),
		Rule(NS('A'), GRB_ERROR_SERIES + 7, 6, // арифметические операции
			Rule::Chain(1, TS('+')),
			Rule::Chain(1, TS('-')),
			Rule::Chain(1, TS('*')),
			Rule::Chain(1, TS('/')),
			Rule::Chain(1, TS('q')),
			Rule::Chain(1, TS('w'))
		),
		Rule(NS('C'), GRB_ERROR_SERIES + 8, 2, // передаваемые аргументы
			Rule::Chain(3, TS('('), NS('N'), TS(')')),
			Rule::Chain(2, TS('('), TS(')'))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 9, 4, // список аргументов передаваемых в функцию
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('N')),
			Rule::Chain(3, TS('l'), TS(','), NS('N'))
		),
		Rule(NS('J'), GRB_ERROR_SERIES + 10, 4, // конструкция процедуры
			Rule::Chain(5, TS('{'), TS('r'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(4, TS('{'), TS('r'), TS(';'), TS('}')),
			Rule::Chain(6, TS('{'), NS('K'), TS('r'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(5, TS('{'), NS('K'), TS('r'), TS(';'), TS('}'))
		),
		Rule(NS('Z'), GRB_ERROR_SERIES + 11, 5, // условное выражение
			Rule::Chain(5, TS('['), TS('i'), NS('O'), TS('i'), TS(']')),
			Rule::Chain(5, TS('['), TS('l'), NS('O'), TS('i'), TS(']')),
			Rule::Chain(5, TS('['), TS('l'), NS('O'), TS('l'), TS(']')),
			Rule::Chain(5, TS('['), TS('i'), NS('O'), TS('l'), TS(']')),
			Rule::Chain(3, TS('['), NS('D'), TS(']'))
		),
		Rule(NS('O'), GRB_ERROR_SERIES + 12, 3, // операторы сравнения
			Rule::Chain(1, TS('>')),
			Rule::Chain(1, TS('<')),
			Rule::Chain(1, TS('e'))
		),
		Rule(NS('R'), GRB_ERROR_SERIES + 13, 2, // конструкция тела условного выражения
			Rule::Chain(3, TS('{'), NS('X'), TS('}')),
			Rule::Chain(4, TS('{'), NS('X'), TS('}'), TS(';'))
		),
		Rule(NS('X'), GRB_ERROR_SERIES + 14, 8, // конструкция в теле условного выражения
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('X')),
			Rule::Chain(4, TS('i'), NS('C'), TS(';'), NS('X')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('i'), NS('C'), TS(';')),
			Rule::Chain(3, TS('k'), NS('D'), TS(';')),
			Rule::Chain(3, TS('n'), NS('D'), TS(';')),
			Rule::Chain(4, TS('k'), NS('D'), TS(';'), NS('K')),
			Rule::Chain(4, TS('n'), NS('D'), TS(';'), NS('K'))
		),
		Rule(NS('M'), GRB_ERROR_SERIES + 15, 1, // конструкция иначе
			Rule::Chain(2, TS('!'), NS('R')))
	);


	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)
	{
		nt = new GRBALPHABET[size = psize];
		int* p = (int*)&s;
		for (short i = 0; i < psize; ++i)
		{
			nt[i] = (GRBALPHABET)p[i];
		};
	}
	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...)
	{
		nn = pnn;
		iderror = piderror;
		chains = new Chain[size = psize];
		Chain* p = &c;
		for (int i = 0; i < size; i++)
		{
			chains[i] = p[i];
		}
	};
	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)
	{
		startN = pstartN;
		stbottomT = pstbottom;
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i = 0; i < size; i++)
		{
			rules[i] = p[i];
		};
	};
	Greibach getGreibach()
	{
		return greibach;
	}
	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)
	{
		short rc = -1;
		short  k = 0;
		while (k < size && rules[k].nn != pnn)
			k++;
		if (k < size)
		{
			prule = rules[rc = k];
		}
		return rc;
	}
	Rule Greibach::getRule(short n)
	{
		Rule rc;
		if (n < size)
		{
			rc = rules[n];
		}
		return rc;
	}
	char* Rule::getCRule(char* b, short nchain)
	{
		char bchain[200];
		b[0] = Chain::alphabet_to_char(nn);
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		chains[nchain].getCChain(bchain);
		strcat_s(b, sizeof(bchain) + 5, bchain);
		return b;
	}
	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)
	{
		short rc = -1;
		while (j < size && chains[j].nt[0] != t)
		{
			++j;
		}
		rc = (j < size ? j : -1);
		if (rc >= 0)
		{
			pchain = chains[rc];
		}
		return rc;
	};
	char* Rule::Chain::getCChain(char* b)
	{
		for (int i = 0; i < size; i++)
		{
			b[i] = alphabet_to_char(nt[i]);
		}
		b[size] = 0x00;
		return b;
	}

};