#include "GenASM.h"

namespace GEN
{
	int ifCount = 0; // счетчик условных операторов
	int negCount = 0; // счетчик результатов выражений(нужен для избежания отрицательных чисел)
	int cycleCount = 0; // счетчик циклов
	int divideZero = 0; // счетчик деления на 0
	std::string cyclecode;
	void GenerationASM(LEX::TableLaI& table, Parm::PARM& parm, Log::LOG& log)
	{
		std::vector<std::string> codeASM = GetBeginFile(table); // получаем динамический массив начала генерации
		std::ofstream fileASM("D:\\2k1s\\KPO\\CurseProject\\ASMCourse\\ASMCourse\\code.asm"); // открытие потока для записи в файл ассемблера
		std::string fName;
		std::string ifCode;
		int paramCount = 0;
		bool lexIf = false, lexOther = false, lexCycle = false;
		std::string line;
		for (int i = 0; i < table.lextable.size; i++)
		{
			switch (table.lextable.table[i].lexemaх[0])
			{
			case LEX_MAIN: {line = line + "\n" + "main PROC"; break; } //. генератор точки входа в программу
			case LEX_PROCEDURE: // генератор объявления процедуры
			{
				fName = table.idtable.table[table.lextable.table[i + 1].idxTI].id;
				line = GetFunctionCode(table, i, fName);
				break;
			}
			case LEX_FUNCTION: // генератор объявления функции
			{
				fName = table.idtable.table[table.lextable.table[i + 2].idxTI].id;
				line = GetFunctionCode(table, i, fName);
				break;
			}
			case LEX_RETURN: {line = GetReturn(table, i, fName); break; } // генератор возвращаемого значения
			case LEX_ID: if(table.lextable.table[i+1].lexemaх[0] == LEX_LEFTTHESIS && table.lextable.table[i - 2].lexemaх[0] != LEX_FUNCTION // если просто вызов функции
							&& table.lextable.table[i - 1].lexemaх[0] != LEX_PROCEDURE)
						{
							line =	GetCallFunc(table, log, i);
						}
					    break;
			case LEX_ITERATION: // генерация цикла
			{
				line = line + GetCycle(table, i);
				line = line + "\ncycle" + std::to_string(cycleCount) + ":\n";
				lexCycle = true;
				break;
			}
			case LEX_IF:  // генерация условного оператора
			{
				line = GetIf(table, i);
				line = line + "\nright" + std::to_string(ifCount) + ":";
				lexIf = true;
				break;
			}
			case LEX_OTHERWISE: // блок кода, если в условном операторе false
			{
				line = line + "wrong" + std::to_string(ifCount) + ":";
				break;
			}
			case LEX_BRACELET: // закрытие блока кода, определяет какой блок закрыт для проставления метки
			{
				if (lexIf && table.lextable.table[i + 1].lexemaх[0] == LEX_OTHERWISE)
				{
					lexIf = false;
					line = line + "jmp next" + std::to_string(ifCount);
					lexOther = true;
				}
				else if (lexIf)
				{
					line = line + "next" + std::to_string(ifCount) + ":";
					lexIf = false;
				}
				else if (lexOther)
				{
					line = line + "next" + std::to_string(ifCount) + ":";
					lexOther = false;
				}
				else if (lexCycle)
				{
					lexCycle = false;
					line = cyclecode + "\ncyclenext" + std::to_string(cycleCount) + ":";
				}
				break;
			}
			case LEX_GRAB: 
			{
				line = GetExtantion(table, log, i);
				while (table.lextable.table[++i].lexemaх[0] != LEX_SEMICOLON);
				break;
			}
			case LEX_WRITE: // вывод без перевода строки
			{
				IT::Entry id = table.idtable.table[table.lextable.table[i + 1].idxTI];
				switch (id.iddatatype)
				{
					case IT::IDDATATYPE::BOOLEAN:
					case IT::IDDATATYPE::UNSINT32: 
					{
						line = line + "\npush " + id.id + "\ncall writenum\n";
						break;
					}
					case IT::IDDATATYPE::SYMBOL:
					case IT::IDDATATYPE::LINE: 
					{
						if (id.idtype == IT::IDTYPE::L)
						{
							line = line + "\npush offset " + id.id + "\ncall writestr\n";
						}
						else
						{
							line = line + "\npush " + id.id + "\ncall writestr\n";
						}
						break;
					}
					break;
				}
				break;
			}
			case LEX_WRITELN:  // вывод с переводом строки
			{
				IT::Entry id = table.idtable.table[table.lextable.table[i + 1].idxTI];
				switch (id.iddatatype)
				{
				case IT::IDDATATYPE::BOOLEAN:
				case IT::IDDATATYPE::UNSINT32:
				{
					line = line + "\npush " + id.id + "\ncall writelnnum\n";
					break;
				}
				case IT::IDDATATYPE::SYMBOL:
				case IT::IDDATATYPE::LINE:
				{
					if (id.idtype == IT::IDTYPE::L)
					{
						line = line + "\npush offset " + id.id + "\ncall writelnstr\n";
					}
					else
					{
						line = line + "\npush " + id.id + "\ncall writelnstr\n";
					}
					break;
				}
				break;
				}
				break;
			}
			}
			if (!line.empty())
			{
				codeASM.push_back(line);
			}
			line.clear();
		}
		codeASM.push_back(CLOSE);
		for (auto x : codeASM)
		{
			fileASM << x << std::endl;
		}
		fileASM.close();
	}
	std::string GetCycle(LEX::TableLaI table, int i) // генератор цикла
	{
		cycleCount++;
		std::string line;
		IT::Entry left = table.idtable.table[table.lextable.table[i + 2].idxTI];
		if (left.iddatatype == IT::IDDATATYPE::BOOLEAN)
		{
			line = line + "mov edx, " + left.id + "\ncmp edx, 1";
			line = line + "\n" + "jz" + " cycle" + std::to_string(cycleCount);
			cyclecode = line;
			line = line + "\n" + "jnz" + " cyclenext" + std::to_string(cycleCount);
			return line;
		}
		IT::Entry right = table.idtable.table[table.lextable.table[i + 4].idxTI];
		std::string tstr, fstr;
		line = line + "mov edx, " + left.id + "\ncmp edx, " + right.id + "\n";
		switch (table.lextable.table[i + 3].lexemaх[0])
		{
		case LEX_MORE: tstr = "jg"; fstr = "jl"; break;
		case LEX_LESS: fstr = "jg"; tstr = "jl"; break;
		case LEX_EQUALS: tstr = "jz"; fstr = "jnz"; break;
		}
		line = line + "\n" + tstr + " cycle" + std::to_string(cycleCount);
		cyclecode = line;
		line = line + "\n" + "jmp cyclenext" + std::to_string(cycleCount);
		return line;
	}
	std::vector<std::string> GetBeginFile(LEX::TableLaI& table) // сгенерировать начало файла: константы, данные и прочее
	{
		std::vector<std::string> begin;
		begin.push_back(START);
		begin.push_back(STANDART);
		std::vector<std::string> literals;
		literals.push_back(CONST);
		std::vector<std::string>ident;
		ident.push_back(DATA);
		for (int i = 0; i < table.idtable.size; i++)
		{
			IT::Entry il = table.idtable.table[i];
			std::string line = "\t\t" + std::string(il.id);
			switch (il.idtype)
			{
				case IT::IDTYPE::L: switch(il.iddatatype)
									{
										case IT::IDDATATYPE::BOOLEAN: line = line + " dword " + std::to_string((int)il.value.vboolean);  break;
										case IT::IDDATATYPE::LINE: line = line + " byte \'" + std::string(il.value.vline->str) + "\', 0";  break;
										case IT::IDDATATYPE::SYMBOL: line = line + " byte \'" + il.value.vsymbol + "\', 0";  break;
										case IT::IDDATATYPE::UNSINT32: line = line + " sdword " + std::to_string(il.value.vunsint32);  break;
									}
								    literals.push_back(line); break;
				case IT::IDTYPE::V: switch(il.iddatatype)
									{
										case IT::IDDATATYPE::BOOLEAN: line = line + " dword 0"; break;
										case IT::IDDATATYPE::LINE: line = line + " dword ?"; break;
										case IT::IDDATATYPE::SYMBOL: line = line + " dword ?"; break;
										case IT::IDDATATYPE::UNSINT32: line = line + " sdword 0"; break;
									}
								  ident.push_back(line); break;
			}
		}
		begin.insert(begin.end(), literals.begin(), literals.end());
		begin.insert(begin.end(), ident.begin(), ident.end());
		begin.push_back(CODE);
		return begin;
	}
	std::string GetFunctionCode(LEX::TableLaI& table, int i, std::string fName) // сгенерировать код функции/ процедуры
	{
		std::string line;
		IT::Entry func;
		if (table.lextable.table[i].lexemaх[0] == LEX_PROCEDURE)
		{
			func = table.idtable.table[table.lextable.table[i + 1].idxTI];
		}
		else
		{
			func = table.idtable.table[table.lextable.table[i + 2].idxTI];
		}
		
		line = "\n" + std::string(func.id) + std::string(" PROC, \n\t");
		int st = i + 3;
		while (table.lextable.table[st].lexemaх[0] != LEX_RIGHTTHESIS)
		{
			if (table.lextable.table[st].lexemaх[0] == LEX_ID)
			{
				line = line + std::string(table.idtable.table[table.lextable.table[st].idxTI].id) +
						(table.idtable.table[table.lextable.table[st].idxTI].iddatatype == IT::IDDATATYPE::UNSINT32 ?
							" : sdword, " : " : dword, ");
			}
			st++;
		}
		int f = line.rfind(',');
		if (f > 0)
		{
			line[f] = IN_CODE_ENDL;
		}
		line += "\npush ebx\npush edx\n";
		return line;
	}
	std::string GetReturn(LEX::TableLaI& table, int i, std::string fName) // сгенерировать возвращаемое значение функции
	{
		std::string line = "\npop edx\npop ebx\n";
		if (table.lextable.table[i + 1].lexemaх[0] != LEX_SEMICOLON)
		{
			if (table.idtable.table[table.lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::LINE ||
				table.idtable.table[table.lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::SYMBOL)
			{
				line = line + "mov eax, offset " + std::string(table.idtable.table[table.lextable.table[i + 1].idxTI].id) + "\n";
			}
			else
			{
				line = line + "mov eax, " + std::string(table.idtable.table[table.lextable.table[i + 1].idxTI].id) + "\n";
			}
		}
		line += "ret\n";
		line += fName + " ENDP\n";
		return line;
	}
	std::string GetCallFunc(LEX::TableLaI& table, Log::LOG log, int i) // генератор вызова функции/ процедуры
	{
		std::string line;
		IT::Entry func = table.idtable.table[table.lextable.table[i].idxTI];
		std::stack <IT::Entry> temp;

		for (int j = i + 1; table.lextable.table[j].lexemaх[0] != LEX_RIGHTTHESIS; j++)
		{
			if (table.lextable.table[j].lexemaх[0] == LEX_ID || table.lextable.table[j].lexemaх[0] == LEX_LITERAL)
			{
				temp.push(table.idtable.table[table.lextable.table[j].idxTI]);
			}
		}
		line += '\n';
		while (!temp.empty())
		{
			if (temp.top().idtype == IT::IDTYPE::L && (temp.top().iddatatype == IT::IDDATATYPE::LINE || temp.top().iddatatype == IT::IDDATATYPE::SYMBOL))
			{
				line = line + " push offset " + temp.top().id + "\n";
			}
			else
			{
				line = line + " push " + temp.top().id + "\n";
			}
			temp.pop();
		}
		if (table.idtable.table[table.lextable.table[i].idxTI].iddatatype == IT::IDDATATYPE::LINE || table.idtable.table[table.lextable.table[i].idxTI].iddatatype == IT::IDDATATYPE::SYMBOL)
		{
			//line += "push offset buffer\n";
		}
		line = line + " call " + std::string(func.id) + IN_CODE_ENDL;
		return line;
	}
	std::string GetIf(LEX::TableLaI table, int i) // генератор условного оператора
	{
		bool t = true, f = false;
		int j = i + 1;
		for (; table.lextable.table[j].lexemaх[0] != LEX_BRACELET; j++);
		if (table.lextable.table[j + 1].lexemaх[0] == LEX_OTHERWISE)
		{
			f = true;
		}
		std::string line;
		ifCount++;
		IT::Entry left = table.idtable.table[table.lextable.table[i + 2].idxTI];
		if (left.iddatatype == IT::IDDATATYPE::BOOLEAN)
		{
			line = line + "mov edx, " + left.id + "\ncmp edx, 1";
			if (t && f)
			{
				line = line + "\n" + "jz" + " right" + std::to_string(ifCount);
				line = line + "\n" + "jnz" + " wrong" + std::to_string(ifCount);
			}
			else
			{
				line = line + "\n" + "jz" + " right" + std::to_string(ifCount);
				line = line + "\njmp" + " next" + std::to_string(ifCount);
			}
			return line;
		}
		IT::Entry right = table.idtable.table[table.lextable.table[i + 4].idxTI];
		
		std::string tstr, fstr;
		line = line + "mov edx, " + left.id + "\ncmp edx, " + right.id + "\n";
		switch (table.lextable.table[i + 3].lexemaх[0])
		{
			case LEX_MORE: tstr = "jg"; fstr = "jl"; break;
			case LEX_LESS: fstr = "jg"; tstr = "jl"; break;
			case LEX_EQUALS: tstr = "jz";  fstr = "jnz";  break;
		}
		if (t && f)
		{
			line = line + "\n" + tstr + " right" + std::to_string(ifCount);
			line = line + "\n" + fstr + " wrong" + std::to_string(ifCount);
		}
		else
		{
			line = line + "\n" + tstr + " right" + std::to_string(ifCount);
			line = line + "\n" + "jmp next" + std::to_string(ifCount);
		}
		return line;
	}
	std::string GetExtantion(LEX::TableLaI table, Log::LOG log, int i) // генератор выражения польской записи
	{
		std::string line;
		IT::Entry left = table.idtable.table[table.lextable.table[i - 1].idxTI];
		switch (left.iddatatype)
		{
			case IT::IDDATATYPE::UNSINT32:
			{
				bool first = true;
				for (int j = i + 1; table.lextable.table[j].lexemaх[0] != LEX_SEMICOLON; j++)
				{
					switch (table.lextable.table[j].lexemaх[0])
					{
						case LEX_LITERAL:
						case LEX_ID:
						{
							if (table.idtable.table[table.lextable.table[j].idxTI].idtype == IT::IDTYPE::F)
							{
								line = line + GetCallFunc(table, log, j);
								while (table.lextable.table[j].lexemaх[0] != LEX_RIGHTTHESIS) j++;
								line = line + "push eax\n";
								break;
							}
							else
							{
								line = line + "push " + table.idtable.table[table.lextable.table[j].idxTI].id + "\n";
								break;
							}
						}
						case LEX_PLUS: line = line + "pop ebx\npop eax\nadd eax, ebx\npush eax\n"; break;
						case LEX_MINUS: line = line + "pop ebx\npop eax\nsub eax, ebx\npush eax\n"; break;
						case LEX_STAR: line = line + "pop ebx\npop eax\nimul eax, ebx\npush eax\n"; break;
						case LEX_DIRSLASH: line = line + "pop ebx\npop eax\n"; 
										   line = line + "cmp ebx, 0\n"+ "\njnz nozero" + std::to_string(divideZero);
										   line = line + "\ncall getError\njmp finish\nnozero" + std::to_string(divideZero) + ":"; 
										   line = line + "\ncdq\nidiv ebx\npush eax\n"; divideZero++; break;
						case LEX_SHIFTLEFT: line = line + "pop ebx \npop eax \nmov cl, bl \nshl eax, cl\npush eax\n"; break;
						case LEX_SHIFTRIGHT: line = line + "pop ebx \npop eax \nmov cl, bl \nshr eax, cl\npush eax\n"; break;
					}
				}
				line = line + "\npop ebx\n";
				line = line + "cmp ebx, 0\njnl minus" + std::to_string(negCount) + "\nneg ebx\nminus" + std::to_string(negCount) + ":\n";
				line = line + "mov " + left.id + ", ebx\n"; negCount++;
				break;
			}
			case IT::IDDATATYPE::BOOLEAN:
			{
				if (table.lextable.table[i + 1].idxTI != TI_NULLIDX &&
					table.idtable.table[table.lextable.table[i + 1].idxTI].iddatatype == IT::IDDATATYPE::BOOLEAN &&
					table.lextable.table[i + 2].lexemaх[0] == LEX_SEMICOLON)
				{
					line = line + "\npush " + table.idtable.table[table.lextable.table[i + 1].idxTI].id;
					line = line + "\npop ebx";
					line = line + "\nmov " + left.id + ", ebx\n"; break;
				}
				else
				{
					line = line + "\nmov " + left.id + ", 1\n"; break;
				}
			}
			case IT::IDDATATYPE::SYMBOL:
			case IT::IDDATATYPE::LINE: 
			{
				char lex = table.lextable.table[i + 1].lexemaх[0];
				IT::Entry right = table.idtable.table[table.lextable.table[i + 1].idxTI];
				if (lex == LEX_ID && (right.idtype == IT::IDTYPE::F || right.idtype == IT::IDTYPE::BF))
				{
					line += GetCallFunc(table, log, i + 1);
					line = line + "mov " + left.id + ", eax";
					line = line + "\nxor eax, eax";
				}
				else if (lex == LEX_LITERAL)
				{
					line = line + "mov " + left.id + ", offset " + right.id;
				}
				else
				{
					line = line + "mov ecx, " + right.id + "\nmov " + left.id + ", ecx";
				}
				break;
			}
		}
		return line;
	}
}