#include "PolishNotation.h"
#include <map>
#include <stack>

namespace POL
{
	LT::LexTable lextable2 = LT::Create(LT_MAXSIZE - 1);
	bool PolishNotation(int& lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		bool polGood = true;
		char* str = new char[TI_STR_MAXSIZE] {};
		int sizeSTR = 0;
		int idFunc = 0;
		std::stack<LT::Entry> stack; // a2+b-c*2+(2*5-1)
		std::map<char, int> prioryti = { {'(', 0}, {')', 0}, {'+', 1}, {'-', 1}, {'q', 1}, {'w', 1}, {'/', 2}, {'*', 2} };
		while (lextable.table[lextable_pos].lexema�[0] != ';')
		{
			if (lextable.table[lextable_pos].lexema�[0] == LEX_ID || lextable.table[lextable_pos].lexema�[0] == LEX_LITERAL)
			{
				if (idtable.table[lextable.table[lextable_pos].idxTI].idtype == IT::IDTYPE::F)
				{
					lextable2.table[lextable2.size++] = lextable.table[lextable_pos];
					while (lextable.table[++lextable_pos].lexema�[0] != ')')
					{
						lextable2.table[lextable2.size++] = lextable.table[lextable_pos];
					}
					lextable2.table[lextable2.size++] = lextable.table[lextable_pos];
					/*LT::Entry idFunc = lextable.table[lextable_pos];
					while (lextable.table[++lextable_pos].lexema�[0] != ')')
					{
						if (lextable.table[lextable_pos].idxTI != -1 &&
							(idtable.table[lextable.table[lextable_pos].idxTI].idtype == IT::IDTYPE::V || idtable.table[lextable.table[lextable_pos].idxTI].idtype == IT::IDTYPE::L
								|| idtable.table[lextable.table[lextable_pos].idxTI].idtype == IT::IDTYPE::P))
						{
							lextable2.table[lextable2.size++] = lextable.table[lextable_pos];
						}
					}
					lextable2.table[lextable2.size] = idFunc;
					lextable2.table[lextable2.size++].lexema�[0] = '@';*/
				}
				else
				{
					lextable2.table[lextable2.size++] = lextable.table[lextable_pos];
				}
				if (lextable.table[lextable_pos + 1].lexema�[0] == ';')
				{
					while (!stack.empty())
					{
						lextable2.table[lextable2.size++] = stack.top();
						stack.pop();
					}
				}
			}
			else if (lextable.table[lextable_pos].lexema�[0] == '+' || lextable.table[lextable_pos].lexema�[0] == '-' ||
				lextable.table[lextable_pos].lexema�[0] == '*' || lextable.table[lextable_pos].lexema�[0] == '/' ||
				lextable.table[lextable_pos].lexema�[0] == '(' || lextable.table[lextable_pos].lexema�[0] == ')' ||
				lextable.table[lextable_pos].lexema�[0] == 'w' || lextable.table[lextable_pos].lexema�[0] == 'q')
			{
				if (stack.empty() || stack.top().lexema�[0] == '(' || lextable.table[lextable_pos].lexema�[0] == '(')
				{
					while (!stack.empty() && stack.top().lexema�[0] != '(' && lextable.table[lextable_pos].lexema�[0] != '(')
					{
						if (prioryti[lextable.table[lextable_pos].lexema�[0]] <= prioryti[stack._Get_container()[stack.size() - 1].lexema�[0]])
						{
							lextable2.table[lextable2.size++] = stack.top();
							stack.pop();
						}
						else
						{
							break;
						}
					}
					stack.push(lextable.table[lextable_pos]);
				}
				else if (lextable.table[lextable_pos].lexema�[0] == ')')
				{
					while (!stack.empty() && stack.top().lexema�[0] != '(')
					{
						lextable2.table[lextable2.size++] = stack.top();
						stack.pop();
					}
					stack.pop();
				}
				else if (lextable.table[lextable_pos + 1].lexema�[0] == ';')
				{
					while (!stack.empty())
					{
						lextable2.table[lextable2.size++] = stack.top();
						stack.pop();
					}
				}
				else
				{
					while (!stack.empty() && stack.top().lexema�[0] != '(')
					{
						if (prioryti[lextable.table[lextable_pos].lexema�[0]] <= prioryti[stack._Get_container()[stack.size() - 1].lexema�[0]])
						{
							lextable2.table[lextable2.size++] = stack.top();
							stack.pop();
						}
						else
						{
							break;
						}
					}
					stack.push(lextable.table[lextable_pos]);
				}
			}
			lextable_pos++;
		}
		while (!stack.empty())
		{
			lextable2.table[lextable2.size++] = stack.top();
			stack.pop();
		}
		return true;
		delete[]str;
	}
	bool PolishStart(LT::LexTable& lextable, IT::IdTable& idtable)
	{
		bool res = true;

		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema�[0] == LEX_GRAB)
			{
				lextable2.table[lextable2.size++] = lextable.table[i];
				res = PolishNotation(++i, lextable, idtable);

			}
			lextable2.table[lextable2.size++] = lextable.table[i];
		}
		lextable.table = lextable2.table;
		lextable.size = lextable2.size;
		return res;
	}
}