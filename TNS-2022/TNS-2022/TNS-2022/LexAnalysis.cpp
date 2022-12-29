#include "LexAnalysis.h"

namespace LEX
{
	bool typeIteration(char type[])
	{
		FST::FST typeIteration(type, 10,
			FST::NODE(1, FST::RELATION('i', 1)),
			FST::NODE(1, FST::RELATION('t', 2)),
			FST::NODE(1, FST::RELATION('e', 3)),
			FST::NODE(1, FST::RELATION('r', 4)),
			FST::NODE(1, FST::RELATION('a', 5)),
			FST::NODE(1, FST::RELATION('t', 6)),
			FST::NODE(1, FST::RELATION('i', 7)),
			FST::NODE(1, FST::RELATION('o', 8)),
			FST::NODE(1, FST::RELATION('n', 9)),
			FST::NODE()
		);
		return FST::execute(typeIteration);
	}
	bool typeBaseFunc(char type[])
	{
		FST::FST typeBase(type, 8,
			FST::NODE(1, FST::RELATION('g', 1)),
			FST::NODE(1, FST::RELATION('e', 2)),
			FST::NODE(1, FST::RELATION('t', 3)),
			FST::NODE(1, FST::RELATION('d', 4)),
			FST::NODE(1, FST::RELATION('a', 5)),
			FST::NODE(1, FST::RELATION('t', 6)),
			FST::NODE(1, FST::RELATION('a', 7)),
			FST::NODE()
		);
		return FST::execute(typeBase);
	}
	bool typeBaseFunc2(char type[])
	{
		FST::FST typeBase(type, 8,
			FST::NODE(1, FST::RELATION('g', 1)),
			FST::NODE(1, FST::RELATION('e', 2)),
			FST::NODE(1, FST::RELATION('t', 3)),
			FST::NODE(1, FST::RELATION('t', 4)),
			FST::NODE(1, FST::RELATION('i', 5)),
			FST::NODE(1, FST::RELATION('m', 6)),
			FST::NODE(1, FST::RELATION('e', 7)),
			FST::NODE()
		);
		return FST::execute(typeBase);
	}
	bool typeUnsInt32(char type[])
	{
		FST::FST typeUnsInt32(type, 9,
			FST::NODE(1, FST::RELATION('u', 1)),
			FST::NODE(1, FST::RELATION('n', 2)),
			FST::NODE(1, FST::RELATION('s', 3)),
			FST::NODE(1, FST::RELATION('i', 4)),
			FST::NODE(1, FST::RELATION('n', 5)),
			FST::NODE(1, FST::RELATION('t', 6)),
			FST::NODE(1, FST::RELATION('3', 7)),
			FST::NODE(1, FST::RELATION('2', 8)),
			FST::NODE()
		);
		return FST::execute(typeUnsInt32);
	}
	bool typeSymbol(char type[])
	{
		FST::FST typeSymbol(type, 7,
			FST::NODE(1, FST::RELATION('s', 1)),
			FST::NODE(1, FST::RELATION('y', 2)),
			FST::NODE(1, FST::RELATION('m', 3)),
			FST::NODE(1, FST::RELATION('b', 4)),
			FST::NODE(1, FST::RELATION('o', 5)),
			FST::NODE(1, FST::RELATION('l', 6)),
			FST::NODE()
		);
		return FST::execute(typeSymbol);
	}
	bool typeLine(char type[])
	{
		FST::FST typeLine(type, 5,
			FST::NODE(1, FST::RELATION('l', 1)),
			FST::NODE(1, FST::RELATION('i', 2)),
			FST::NODE(1, FST::RELATION('n', 3)),
			FST::NODE(1, FST::RELATION('e', 4)),
			FST::NODE()
		);
		return FST::execute(typeLine);
	}
	bool typeBoolean(char type[])
	{
		FST::FST typeBoolean(type, 8,
			FST::NODE(1, FST::RELATION('l', 1)),
			FST::NODE(1, FST::RELATION('o', 2)),
			FST::NODE(1, FST::RELATION('g', 3)),
			FST::NODE(1, FST::RELATION('i', 4)),
			FST::NODE(1, FST::RELATION('c', 5)),
			FST::NODE(1, FST::RELATION('a', 6)),
			FST::NODE(1, FST::RELATION('l', 7)),
			FST::NODE()
		);
		return FST::execute(typeBoolean);
	}
	bool typeID(char type[])
	{
		FST::FST typeID(type, 2,
			FST::NODE(125, FST::RELATION('a', 0), FST::RELATION('a', 1), FST::RELATION('b', 0), FST::RELATION('b', 1),
				FST::RELATION('c', 0), FST::RELATION('c', 1), FST::RELATION('d', 0), FST::RELATION('d', 1),
				FST::RELATION('e', 0), FST::RELATION('e', 1), FST::RELATION('f', 0), FST::RELATION('f', 1),
				FST::RELATION('g', 0), FST::RELATION('g', 1), FST::RELATION('h', 0), FST::RELATION('h', 1),
				FST::RELATION('i', 0), FST::RELATION('i', 1), FST::RELATION('j', 0), FST::RELATION('j', 1),
				FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
				FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1),
				FST::RELATION('o', 0), FST::RELATION('o', 1), FST::RELATION('p', 0), FST::RELATION('p', 1),
				FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
				FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1),
				FST::RELATION('u', 0), FST::RELATION('u', 1), FST::RELATION('v', 0), FST::RELATION('v', 1),
				FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
				FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1),
				FST::RELATION('2', 0), FST::RELATION('3', 1), FST::RELATION('3', 0), FST::RELATION('4', 1),
				FST::RELATION('4', 0), FST::RELATION('5', 1), FST::RELATION('5', 0), FST::RELATION('6', 1),
				FST::RELATION('6', 0), FST::RELATION('7', 1), FST::RELATION('7', 0), FST::RELATION('8', 1),
				FST::RELATION('8', 0), FST::RELATION('9', 1), FST::RELATION('9', 0), FST::RELATION('_', 1),
				FST::RELATION('_', 0), FST::RELATION('0', 1), FST::RELATION('0', 0), FST::RELATION('1', 1), 
				FST::RELATION('1', 0), FST::RELATION('2', 1), FST::RELATION('A', 0), FST::RELATION('A', 1), 
				FST::RELATION('B', 0), FST::RELATION('B', 1),
				FST::RELATION('C', 0), FST::RELATION('C', 1), FST::RELATION('D', 0), FST::RELATION('D', 1),
				FST::RELATION('E', 0), FST::RELATION('E', 1), FST::RELATION('F', 0), FST::RELATION('F', 1),
				FST::RELATION('G', 0), FST::RELATION('G', 1), FST::RELATION('H', 0), FST::RELATION('H', 1),
				FST::RELATION('I', 0), FST::RELATION('I', 1), FST::RELATION('J', 0), FST::RELATION('J', 1),
				FST::RELATION('K', 0), FST::RELATION('K', 1), FST::RELATION('L', 0), FST::RELATION('L', 1),
				FST::RELATION('M', 0), FST::RELATION('M', 1), FST::RELATION('N', 0), FST::RELATION('N', 1),
				FST::RELATION('O', 0), FST::RELATION('O', 1), FST::RELATION('P', 0), FST::RELATION('P', 1),
				FST::RELATION('Q', 0), FST::RELATION('Q', 1), FST::RELATION('R', 0), FST::RELATION('R', 1),
				FST::RELATION('S', 0), FST::RELATION('S', 1), FST::RELATION('T', 0), FST::RELATION('T', 1),
				FST::RELATION('U', 0), FST::RELATION('U', 1), FST::RELATION('V', 0), FST::RELATION('V', 1),
				FST::RELATION('W', 0), FST::RELATION('W', 1), FST::RELATION('X', 0), FST::RELATION('X', 1),
				FST::RELATION('Y', 0), FST::RELATION('Y', 1), FST::RELATION('Z', 0)),
			FST::NODE()
		);
		return FST::execute(typeID);
	}
	bool typeLitInt(char type[])
	{
		FST::FST typeLitInt(type, 2,
			FST::NODE(20, FST::RELATION('1', 0), FST::RELATION('1', 1), FST::RELATION('2', 0), FST::RELATION('2', 1),
				FST::RELATION('3', 0), FST::RELATION('3', 1), FST::RELATION('4', 0), FST::RELATION('4', 1),
				FST::RELATION('5', 0), FST::RELATION('5', 1), FST::RELATION('6', 0), FST::RELATION('6', 1),
				FST::RELATION('7', 0), FST::RELATION('7', 1), FST::RELATION('8', 0), FST::RELATION('8', 1),
				FST::RELATION('9', 0), FST::RELATION('9', 1), FST::RELATION('0', 0), FST::RELATION('0', 1)),
			FST::NODE()
		);
		return FST::execute(typeLitInt);
	}
	bool typeLitIntMinus(char type[])
	{
		FST::FST typeLitInt(type, 3,
			FST::NODE(1, FST::RELATION('-', 1)),
			FST::NODE(20, FST::RELATION('1', 1), FST::RELATION('1', 2), FST::RELATION('2', 1), FST::RELATION('2', 2),
				FST::RELATION('3', 1), FST::RELATION('3', 2), FST::RELATION('4', 1), FST::RELATION('4', 2),
				FST::RELATION('5', 1), FST::RELATION('5', 2), FST::RELATION('6', 1), FST::RELATION('6', 2),
				FST::RELATION('7', 1), FST::RELATION('7', 2), FST::RELATION('8', 1), FST::RELATION('8', 2),
				FST::RELATION('9', 1), FST::RELATION('9', 2), FST::RELATION('0', 1), FST::RELATION('0', 2)),
			FST::NODE()
		);
		return FST::execute(typeLitInt);
	}
	bool typeLitStr(char type[])
	{
		//setlocale(LC_ALL, "rus");
		FST::FST typeLitStr(type, 4,
			FST::NODE(1, FST::RELATION('\"', 1)),
			FST::NODE(290, FST::RELATION(' ', 1), FST::RELATION(' ', 2), FST::RELATION('1', 1), FST::RELATION('1', 2), FST::RELATION('2', 1), FST::RELATION('2', 2), // 6
				FST::RELATION('3', 1), FST::RELATION('3', 2), FST::RELATION('4', 1), FST::RELATION('4', 2),
				FST::RELATION('5', 1), FST::RELATION('5', 2), FST::RELATION('6', 1), FST::RELATION('6', 2),
				FST::RELATION('7', 1), FST::RELATION('7', 2), FST::RELATION('8', 1), FST::RELATION('8', 2),
				FST::RELATION('9', 1), FST::RELATION('9', 2), FST::RELATION('0', 1), FST::RELATION('0', 2),
				FST::RELATION('a', 1), FST::RELATION('a', 2), FST::RELATION('b', 1), FST::RELATION('b', 2),
				FST::RELATION('c', 1), FST::RELATION('c', 2), FST::RELATION('d', 1), FST::RELATION('d', 2),
				FST::RELATION('e', 1), FST::RELATION('e', 2), FST::RELATION('f', 1), FST::RELATION('f', 2),
				FST::RELATION('g', 1), FST::RELATION('g', 2), FST::RELATION('h', 1), FST::RELATION('h', 2),
				FST::RELATION('i', 1), FST::RELATION('i', 2), FST::RELATION('j', 1), FST::RELATION('j', 2),
				FST::RELATION('k', 1), FST::RELATION('k', 2), FST::RELATION('l', 1), FST::RELATION('l', 2),
				FST::RELATION('m', 1), FST::RELATION('m', 2), FST::RELATION('n', 1), FST::RELATION('n', 2),
				FST::RELATION('o', 1), FST::RELATION('o', 2), FST::RELATION('p', 1), FST::RELATION('p', 2),
				FST::RELATION('q', 1), FST::RELATION('q', 2), FST::RELATION('r', 1), FST::RELATION('r', 2),
				FST::RELATION('s', 1), FST::RELATION('s', 2), FST::RELATION('t', 1), FST::RELATION('t', 2),
				FST::RELATION('u', 1), FST::RELATION('u', 2), FST::RELATION('v', 1), FST::RELATION('v', 2),
				FST::RELATION('w', 1), FST::RELATION('w', 2), FST::RELATION('x', 1), FST::RELATION('x', 2),
				FST::RELATION('y', 1), FST::RELATION('y', 2), FST::RELATION('z', 1), FST::RELATION('z', 2),
				FST::RELATION('+', 1), FST::RELATION('+', 2), FST::RELATION('-', 1), FST::RELATION('-', 2),
				FST::RELATION(')', 1), FST::RELATION(')', 2), FST::RELATION('(', 1), FST::RELATION('(', 2),
				FST::RELATION('*', 1), FST::RELATION('*', 2), FST::RELATION('&', 1), FST::RELATION('&', 2),
				FST::RELATION('^', 1), FST::RELATION('^', 2), FST::RELATION('%', 1), FST::RELATION('%', 2),
				FST::RELATION('$', 1), FST::RELATION('$', 2), FST::RELATION('#', 1), FST::RELATION('#', 2),
				FST::RELATION('@', 1), FST::RELATION('@', 2), FST::RELATION('!', 1), FST::RELATION('!', 2),
				FST::RELATION('№', 1), FST::RELATION('№', 2), FST::RELATION(';', 1), FST::RELATION(';', 2),
				FST::RELATION('?', 1), FST::RELATION('?', 2), FST::RELATION('A', 1), FST::RELATION('A', 2),
				FST::RELATION('B', 1), FST::RELATION('B', 2), FST::RELATION('C', 1), FST::RELATION('C', 2), // 26 * 4
				FST::RELATION('D', 1), FST::RELATION('D', 2), // 2
				FST::RELATION('E', 1), FST::RELATION('E', 2), FST::RELATION('F', 1), FST::RELATION('F', 2),
				FST::RELATION('G', 1), FST::RELATION('G', 2), FST::RELATION('H', 1), FST::RELATION('H', 2),
				FST::RELATION('I', 1), FST::RELATION('I', 2), FST::RELATION('J', 1), FST::RELATION('J', 2),
				FST::RELATION('K', 1), FST::RELATION('K', 2), FST::RELATION('L', 1), FST::RELATION('L', 2),
				FST::RELATION('M', 1), FST::RELATION('M', 2), FST::RELATION('N', 1), FST::RELATION('N', 2),
				FST::RELATION('O', 1), FST::RELATION('O', 2), FST::RELATION('P', 1), FST::RELATION('P', 2),
				FST::RELATION('Q', 1), FST::RELATION('Q', 2), FST::RELATION('R', 1), FST::RELATION('R', 2),
				FST::RELATION('S', 1), FST::RELATION('S', 2), FST::RELATION('T', 1), FST::RELATION('T', 2),
				FST::RELATION('U', 1), FST::RELATION('U', 2), FST::RELATION('V', 1), FST::RELATION('V', 2),
				FST::RELATION('W', 1), FST::RELATION('W', 2), FST::RELATION('X', 1), FST::RELATION('X', 2),
				FST::RELATION('Y', 1), FST::RELATION('Y', 2), FST::RELATION('Z', 1), FST::RELATION('Z', 2),
				FST::RELATION('а', 1), FST::RELATION('а', 2), FST::RELATION('б', 1), FST::RELATION('б', 2),
				FST::RELATION('в', 1), FST::RELATION('в', 2), FST::RELATION('г', 1), FST::RELATION('г', 2),
				FST::RELATION('д', 1), FST::RELATION('д', 2), FST::RELATION('е', 1), FST::RELATION('е', 2),
				FST::RELATION('ё', 1), FST::RELATION('ё', 2), FST::RELATION('ж', 1), FST::RELATION('ж', 2),
				FST::RELATION('з', 1), FST::RELATION('з', 2), FST::RELATION('и', 1), FST::RELATION('и', 2),
				FST::RELATION('й', 1), FST::RELATION('й', 2), FST::RELATION('к', 1), FST::RELATION('к', 2),
				FST::RELATION('л', 1), FST::RELATION('л', 2), FST::RELATION('м', 1), FST::RELATION('м', 2),
				FST::RELATION('н', 1), FST::RELATION('н', 2), FST::RELATION('о', 1), FST::RELATION('о', 2),
				FST::RELATION('п', 1), FST::RELATION('п', 2), FST::RELATION('р', 1), FST::RELATION('р', 2),
				FST::RELATION('с', 1), FST::RELATION('с', 2), FST::RELATION('т', 1), FST::RELATION('т', 2),
				FST::RELATION('у', 1), FST::RELATION('у', 2), FST::RELATION('ф', 1), FST::RELATION('ф', 2),
				FST::RELATION('х', 1), FST::RELATION('х', 2), FST::RELATION('ц', 1), FST::RELATION('ц', 2),
				FST::RELATION('ч', 1), FST::RELATION('ч', 2), FST::RELATION('ш', 1), FST::RELATION('ш', 2),
				FST::RELATION('щ', 1), FST::RELATION('щ', 2), FST::RELATION('ъ', 1), FST::RELATION('ъ', 2),
				FST::RELATION('ы', 1), FST::RELATION('ы', 2), FST::RELATION('ь', 1), FST::RELATION('ь', 2),
				FST::RELATION('э', 1), FST::RELATION('э', 2), FST::RELATION('ю', 1), FST::RELATION('ю', 2), // 27 * 4
				FST::RELATION('я', 1), FST::RELATION('я', 2), FST::RELATION(':', 1), FST::RELATION(':', 2),
				FST::RELATION('А', 1), FST::RELATION('А', 2), FST::RELATION('Б', 1), FST::RELATION('Б', 2),
				FST::RELATION('В', 1), FST::RELATION('В', 2), FST::RELATION('Г', 1), FST::RELATION('Г', 2),
				FST::RELATION('Д', 1), FST::RELATION('Д', 2), FST::RELATION('Е', 1), FST::RELATION('Е', 2),
				FST::RELATION('Ё', 1), FST::RELATION('Ё', 2), FST::RELATION('Ж', 1), FST::RELATION('Ж', 2),
				FST::RELATION('З', 1), FST::RELATION('З', 2), FST::RELATION('И', 1), FST::RELATION('И', 2),
				FST::RELATION('Й', 1), FST::RELATION('Й', 2), FST::RELATION('К', 1), FST::RELATION('К', 2),
				FST::RELATION('Л', 1), FST::RELATION('Л', 2), FST::RELATION('М', 1), FST::RELATION('М', 2),
				FST::RELATION('Н', 1), FST::RELATION('Н', 2), FST::RELATION('О', 1), FST::RELATION('О', 2),
				FST::RELATION('П', 1), FST::RELATION('П', 2), FST::RELATION('Р', 1), FST::RELATION('Р', 2),
				FST::RELATION('С', 1), FST::RELATION('С', 2), FST::RELATION('Т', 1), FST::RELATION('Т', 2),
				FST::RELATION('У', 1), FST::RELATION('У', 2), FST::RELATION('Ф', 1), FST::RELATION('Ф', 2),
				FST::RELATION('Х', 1), FST::RELATION('Х', 2), FST::RELATION('Ц', 1), FST::RELATION('Ц', 2),
				FST::RELATION('Ч', 1), FST::RELATION('Ч', 2), FST::RELATION('Ш', 1), FST::RELATION('Ш', 2),
				FST::RELATION('Щ', 1), FST::RELATION('Щ', 2), FST::RELATION('Ъ', 1), FST::RELATION('Ъ', 2),
				FST::RELATION('Ы', 1), FST::RELATION('Ы', 2), FST::RELATION('Ь', 1), FST::RELATION('Ь', 2),
				FST::RELATION('Э', 1), FST::RELATION('Э', 2), FST::RELATION('Ю', 1), FST::RELATION('Ю', 2),
				FST::RELATION('Я', 1), FST::RELATION('Я', 2)),
			FST::NODE(1, FST::RELATION('\"', 3)),
			FST::NODE()
		);
		return FST::execute(typeLitStr);
	}
	bool typeLitTrue(char type[])
	{
		FST::FST typeTrue(type, 5,
			FST::NODE(1, FST::RELATION('t', 1)),
			FST::NODE(1, FST::RELATION('r', 2)),
			FST::NODE(1, FST::RELATION('u', 3)),
			FST::NODE(1, FST::RELATION('e', 4)),
			FST::NODE()
		);
		return FST::execute(typeTrue);
	}
	bool typeLitFalse(char type[])
	{
		FST::FST typeFalse(type, 6,
			FST::NODE(1, FST::RELATION('f', 1)),
			FST::NODE(1, FST::RELATION('a', 2)),
			FST::NODE(1, FST::RELATION('l', 3)),
			FST::NODE(1, FST::RELATION('s', 4)),
			FST::NODE(1, FST::RELATION('e', 5)),
			FST::NODE()
		);
		return FST::execute(typeFalse);
	}
	bool typeLitSymbol(char type[])
	{
		FST::FST typeLitStr(type, 4,
			FST::NODE(1, FST::RELATION('\'', 1)),
			FST::NODE(144, FST::RELATION(' ', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
				FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2),
				FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2),
				FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2),
				FST::RELATION('e', 2), FST::RELATION('f', 2), FST::RELATION('g', 2), FST::RELATION('h', 2),
				FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),
				FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2),
				FST::RELATION('q', 2), FST::RELATION('r', 2), FST::RELATION('s', 2), FST::RELATION('t', 2),
				FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),
				FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('+', 2), FST::RELATION('-', 2),
				FST::RELATION(')', 2), FST::RELATION('(', 2), FST::RELATION('*', 2), FST::RELATION('&', 2),
				FST::RELATION('^', 2), FST::RELATION('%', 2), FST::RELATION('$', 2), FST::RELATION('#', 2),
				FST::RELATION('@', 2), FST::RELATION('!', 2), FST::RELATION('№', 2), FST::RELATION(';', 2),
				FST::RELATION('?', 2), FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2),
				FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2), FST::RELATION('G', 2),
				FST::RELATION('H', 2), FST::RELATION('я', 2), FST::RELATION('I', 2), FST::RELATION('J', 2),
				FST::RELATION('K', 2), FST::RELATION('L', 2), FST::RELATION('M', 2), FST::RELATION('N', 2),
				FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2),
				FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), FST::RELATION('V', 2),
				FST::RELATION('W', 2), FST::RELATION('X', 2), FST::RELATION('Y', 2), FST::RELATION('Z', 2),
				FST::RELATION('а', 2), FST::RELATION('б', 2), FST::RELATION('в', 2), FST::RELATION('г', 2),
				FST::RELATION('д', 2), FST::RELATION('е', 2), FST::RELATION('ё', 2), FST::RELATION('ж', 2),
				FST::RELATION('з', 2), FST::RELATION('и', 2), FST::RELATION('й', 2), FST::RELATION('к', 2),
				FST::RELATION('л', 2), FST::RELATION('м', 2), FST::RELATION('н', 2), FST::RELATION('о', 2),
				FST::RELATION('п', 2), FST::RELATION('р', 2), FST::RELATION('с', 2), FST::RELATION('т', 2),
				FST::RELATION('у', 2), FST::RELATION('ф', 2), FST::RELATION('х', 2), FST::RELATION('ц', 2),
				FST::RELATION('ч', 2), FST::RELATION('ш', 2), FST::RELATION('щ', 2), FST::RELATION('ъ', 2),
				FST::RELATION('ы', 2), FST::RELATION('ь', 2), FST::RELATION('э', 2), FST::RELATION('ю', 2),
				FST::RELATION('А', 2), FST::RELATION('Б', 2), FST::RELATION('В', 2), FST::RELATION('Г', 2),
				FST::RELATION('Д', 2), FST::RELATION('Е', 2), FST::RELATION('Ё', 2), FST::RELATION('Ж', 2),
				FST::RELATION('З', 2), FST::RELATION('И', 2), FST::RELATION('Й', 2), FST::RELATION('К', 2),
				FST::RELATION('Л', 2), FST::RELATION('М', 2), FST::RELATION('Н', 2), FST::RELATION('О', 2),
				FST::RELATION('П', 2), FST::RELATION('Р', 2), FST::RELATION('С', 2), FST::RELATION('Т', 2),
				FST::RELATION('У', 2), FST::RELATION('Ф', 2), FST::RELATION('Х', 2), FST::RELATION('Ц', 2),
				FST::RELATION('Ч', 2), FST::RELATION('Ш', 2), FST::RELATION('Щ', 2), FST::RELATION('Ъ', 2),
				FST::RELATION('Ы', 2), FST::RELATION('Ь', 2), FST::RELATION('Э', 2), FST::RELATION('Ю', 2),
				FST::RELATION('Я', 2)),
			FST::NODE(1, FST::RELATION('\'', 3)),
			FST::NODE()
		);
		return FST::execute(typeLitStr);
	}
	bool typeWhen(char type[])
	{
		FST::FST typeWhen(type, 5,
			FST::NODE(1, FST::RELATION('w', 1)),
			FST::NODE(1, FST::RELATION('h', 2)),
			FST::NODE(1, FST::RELATION('e', 3)),
			FST::NODE(1, FST::RELATION('n', 4)),
			FST::NODE()
		);
		return FST::execute(typeWhen);
	}
	bool typeOtherwise(char type[])
	{
		FST::FST typeOtherwise(type, 10,
			FST::NODE(20, FST::RELATION('o', 1)),
			FST::NODE(20, FST::RELATION('t', 2)),
			FST::NODE(20, FST::RELATION('h', 3)),
			FST::NODE(20, FST::RELATION('e', 4)),
			FST::NODE(20, FST::RELATION('r', 5)),
			FST::NODE(20, FST::RELATION('w', 6)),
			FST::NODE(20, FST::RELATION('i', 7)),
			FST::NODE(20, FST::RELATION('s', 8)),
			FST::NODE(20, FST::RELATION('e', 9)),
			FST::NODE()
		);
		return FST::execute(typeOtherwise);
	}
	bool typeFunc(char type[])
	{
		FST::FST typeFunc(type, 9,
			FST::NODE(1, FST::RELATION('f', 1)),
			FST::NODE(1, FST::RELATION('u', 2)),
			FST::NODE(1, FST::RELATION('n', 3)),
			FST::NODE(1, FST::RELATION('c', 4)),
			FST::NODE(1, FST::RELATION('t', 5)),
			FST::NODE(1, FST::RELATION('i', 6)),
			FST::NODE(1, FST::RELATION('o', 7)),
			FST::NODE(1, FST::RELATION('n', 8)),
			FST::NODE()
		);
		return FST::execute(typeFunc);
	}
	bool typeProc(char type[])
	{
		FST::FST typeProc(type, 10,
			FST::NODE(1, FST::RELATION('p', 1)),
			FST::NODE(1, FST::RELATION('r', 2)),
			FST::NODE(1, FST::RELATION('o', 3)),
			FST::NODE(1, FST::RELATION('c', 4)),
			FST::NODE(1, FST::RELATION('e', 5)),
			FST::NODE(1, FST::RELATION('d', 6)),
			FST::NODE(1, FST::RELATION('u', 7)),
			FST::NODE(1, FST::RELATION('r', 8)),
			FST::NODE(1, FST::RELATION('e', 9)),
			FST::NODE()
		);
		return FST::execute(typeProc);
	}
	bool typeRet(char type[])
	{
		FST::FST typeRet(type, 7,
			FST::NODE(1, FST::RELATION('r', 1)),
			FST::NODE(1, FST::RELATION('e', 2)),
			FST::NODE(1, FST::RELATION('t', 3)),
			FST::NODE(1, FST::RELATION('u', 4)),
			FST::NODE(1, FST::RELATION('r', 5)),
			FST::NODE(1, FST::RELATION('n', 6)),
			FST::NODE()
		);
		return FST::execute(typeRet);
	}
	bool typeMain(char type[])
	{
		FST::FST typeMain(type, 5,
			FST::NODE(1, FST::RELATION('M', 1)),
			FST::NODE(1, FST::RELATION('A', 2)),
			FST::NODE(1, FST::RELATION('I', 3)),
			FST::NODE(1, FST::RELATION('N', 4)),
			FST::NODE()
		);
		return FST::execute(typeMain);
	}
	bool typeLeftFigure(char type[])
	{
		FST::FST typeLeftFigure(type, 2,
			FST::NODE(1, FST::RELATION('{', 1)),
			FST::NODE()
		);
		return FST::execute(typeLeftFigure);
	}
	bool typeRightFigure(char type[])
	{
		FST::FST typeRightFigure(type, 2,
			FST::NODE(1, FST::RELATION('}', 1)),
			FST::NODE()
		);
		return FST::execute(typeRightFigure);
	}
	bool typeWriteln(char type[])
	{
		FST::FST typeWriteln(type, 8,
			FST::NODE(1, FST::RELATION('w', 1)),
			FST::NODE(1, FST::RELATION('r', 2)),
			FST::NODE(1, FST::RELATION('i', 3)),
			FST::NODE(1, FST::RELATION('t', 4)),
			FST::NODE(1, FST::RELATION('e', 5)),
			FST::NODE(1, FST::RELATION('l', 6)),
			FST::NODE(1, FST::RELATION('n', 7)),
			FST::NODE()
		);
		return FST::execute(typeWriteln);
	}
	bool typeWrite(char type[])
	{
		FST::FST typeWrite(type, 6,
			FST::NODE(1, FST::RELATION('w', 1)),
			FST::NODE(1, FST::RELATION('r', 2)),
			FST::NODE(1, FST::RELATION('i', 3)),
			FST::NODE(1, FST::RELATION('t', 4)),
			FST::NODE(1, FST::RELATION('e', 5)),
			FST::NODE()
		);
		return FST::execute(typeWrite);
	}
	bool typeLeftCircle(char type[])
	{
		FST::FST typeLeftCircle(type, 2,
			FST::NODE(1, FST::RELATION('(', 1)),
			FST::NODE()
		);
		return FST::execute(typeLeftCircle);
	}
	bool typeRightCircle(char type[])
	{
		FST::FST typeRightCircle(type, 2,
			FST::NODE(1, FST::RELATION(')', 1)),
			FST::NODE()
		);
		return FST::execute(typeRightCircle);
	}
	bool typeSquareBrL(char type[])
	{
		FST::FST typeSquareBrL(type, 2,
			FST::NODE(1, FST::RELATION('[', 1)),
			FST::NODE()
		);
		return FST::execute(typeSquareBrL);
	}
	bool typeSquareBrR(char type[])
	{
		FST::FST typeSquareBrR(type, 2,
			FST::NODE(1, FST::RELATION(']', 1)),
			FST::NODE()
		);
		return FST::execute(typeSquareBrR);
	}
	bool typeSemicolon(char type[])
	{
		FST::FST typeSemicolon(type, 2,
			FST::NODE(1, FST::RELATION(';', 1)),
			FST::NODE()
		);
		return FST::execute(typeSemicolon);
	}
	bool typeComma(char type[])
	{
		FST::FST typeComma(type, 2,
			FST::NODE(1, FST::RELATION(',', 1)),
			FST::NODE()
		);
		return FST::execute(typeComma);
	}
	bool typePlus(char type[])
	{
		FST::FST typePlus(type, 2,
			FST::NODE(1, FST::RELATION('+', 1)),
			FST::NODE()
		);
		return FST::execute(typePlus);
	}
	bool typeMinus(char type[])
	{
		FST::FST typeMinus(type, 2,
			FST::NODE(1, FST::RELATION('-', 1)),
			FST::NODE()
		);
		return FST::execute(typeMinus);
	}
	bool typeStar(char type[])
	{
		FST::FST typeStar(type, 2,
			FST::NODE(1, FST::RELATION('*', 1)),
			FST::NODE()
		);
		return FST::execute(typeStar);
	}
	bool typeDirSlash(char type[])
	{
		FST::FST typeDirSlash(type, 2,
			FST::NODE(1, FST::RELATION('/', 1)),
			FST::NODE()
		);
		return FST::execute(typeDirSlash);
	}
	bool typeGrab(char type[])
	{
		FST::FST typeGrab(type, 2,
			FST::NODE(1, FST::RELATION('=', 1)),
			FST::NODE()
		);
		return FST::execute(typeGrab);
	}
	bool typeEquals(char type[])
	{
		FST::FST typeEquals(type, 3,
			FST::NODE(1, FST::RELATION('=', 1)),
			FST::NODE(1, FST::RELATION('=', 2)),
			FST::NODE()
		);
		return FST::execute(typeEquals);
	}
	bool typeLexMore(char type[])
	{
		FST::FST typeLitMore(type, 2,
			FST::NODE(20, FST::RELATION('>', 1)),
			FST::NODE()
		);
		return FST::execute(typeLitMore);
	}
	bool typeLexLess(char type[])
	{
		FST::FST typeLitLess(type, 2,
			FST::NODE(20, FST::RELATION('<', 1)),
			FST::NODE()
		);
		return FST::execute(typeLitLess);
	}
	bool typeShiftLeft(char type[])
	{
		FST::FST typeLitLess(type, 4,
			FST::NODE(20, FST::RELATION(':', 1)),
			FST::NODE(20, FST::RELATION('<', 2)),
			FST::NODE(20, FST::RELATION('<', 3)),
			FST::NODE()
		);
		return FST::execute(typeLitLess);
	}
	bool typeShiftRight(char type[])
	{
		FST::FST typeLitLess(type, 4,
			FST::NODE(20, FST::RELATION(':', 1)),
			FST::NODE(20, FST::RELATION('>', 2)),
			FST::NODE(20, FST::RELATION('>', 3)),
			FST::NODE()
		);
		return FST::execute(typeLitLess);
	}

	LT::LexTable lextable = LT::Create(LT_MAXSIZE - 1);
	IT::IdTable idtable = IT::Create(TI_MAXSIZE - 1);
	UsingType flags;
	TableLaI LexicalAnalysis(In::IN input, Out::OUT out, Log::LOG log)
	{
		setlocale(LC_ALL, "Russian");
		short errorCount = 0;
		char* nameFunc = new char[ID_MAXSIZE]{};
		int line = 0;
		int col = 0;
		int countLit = 0;
		input.words = EditTextInWords(input, log);
		for (int i = 0; i < input.sizeWord; i++)
		{
			if (typeUnsInt32(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_UNSINT32);
				flags.UseUnsInt32 = true;
			}
			else if (typeBaseFunc2(input.words[i].word))
			{
				if (lextable.table[lextable.size - 1].lexemaх[0] == 'f')
				{
					Log::WriteError(log, Error::geterrorin(623, input.words[i].line, input.words[i].col));
					errorCount++;
					flags.Error = true;
				}
				else
				{
					inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::LINE, IT::IDTYPE::BF, nameFunc);
				}
			}
			else if (typeBaseFunc(input.words[i].word))
			{
				if (lextable.table[lextable.size - 1].lexemaх[0] == 'f')
				{
					Log::WriteError(log, Error::geterrorin(623, input.words[i].line, input.words[i].col));
					errorCount++;
					flags.Error = true;
				}
				else
				{
					inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::LINE, IT::IDTYPE::BF, nameFunc);
				}
			}
			else if (typeLitIntMinus(input.words[i].word))
			{
				Log::WriteError(log, Error::geterrorin(622, input.words[i].line, input.words[i].col));
				errorCount++;
				flags.Error = true;
			}
			else if (typeIteration(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_ITERATION);
				flags.UseCycle = true;
			}
			else if (typeSymbol(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SYMBOL);
				flags.UseSymbol = true;
			}
			else if (typeLine(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_LINE);
				flags.UseLine = true;
			}
			else if (typeWrite(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_WRITE);
			}
			else if (typeWriteln(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_WRITELN);
			}
			else if (typeBoolean(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_BOOLEAN);
				flags.UseBoolean = true;
			}
			else if (typeWhen(input.words[i].word))
			{
				flags.UseIf = true;
				inputLexema(input.words[i].line, LEX_IF);
			}
			else if (typeOtherwise(input.words[i].word))
			{
				flags.UseIf = true;
				inputLexema(input.words[i].line, LEX_OTHERWISE);
			}
			else if (typeFunc(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_FUNCTION);
				flags.UseFunc = true;
			}
			else if (typeProc(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_PROCEDURE);
				flags.UseProc = true;
			}
			else if (typeRet(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_RETURN);
			}
			else if (typeMain(input.words[i].word))
			{
				if (flags.UseMain)
				{
					Log::WriteError(log, Error::geterrorin(613, input.words[i].line, input.words[i].col));
					flags.Error = true;
				}
				inputLexema(input.words[i].line, LEX_MAIN);
				strcpy_s(nameFunc, strlen(nameFunc) - 1, input.words[i].word);
				flags.UseMain = true;
			}
			else if (typeLeftFigure(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_LEFTBRACE);
				if (!flags.UseIf && !flags.UseCycle) flags.DataInFunc = true;
				flags.UseLeftFigure = true;
				flags.UseFunc = false;
				flags.UseProc = false;
				flags.UseRightFigure = false;
			}
			else if (typeRightFigure(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_BRACELET);
				if (!flags.UseIf && !flags.UseCycle)
				{
					flags.DataInFunc = false;
					memset(nameFunc, '\0', strlen(nameFunc));
					flags.UseLeftFigure = false;
					flags.UseRightFigure = true;
				}
				flags.UseFunc = false;
				flags.UseProc = false;
				flags.UseIf = false;
				flags.UseCycle = false;
			}
			else if (typeSquareBrL(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SQUAREBRL);
			}
			else if (typeSquareBrR(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SQUAREBRR);
			}
			else if (typeLeftCircle(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_LEFTTHESIS);
				flags.UseLeftCircle = true;
			}
			else if (typeRightCircle(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_RIGHTTHESIS);
				flags.UseLeftCircle = false;
			}
			else if (typeSemicolon(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SEMICOLON);
			}
			else if (typeComma(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_COMMA);
			}
			else if (typePlus(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_PLUS);
			}
			else if (typeMinus(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_MINUS);
			}
			else if (typeStar(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_STAR);
			}
			else if (typeDirSlash(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_DIRSLASH);
			}
			else if (typeGrab(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_GRAB);
			}
			else if (typeEquals(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_EQUALS);
			}
			else if (typeLexMore(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_MORE);
			}
			else if (typeLexLess(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_LESS);
			}
			else if (typeShiftLeft(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SHIFTLEFT);
			}
			else if (typeShiftRight(input.words[i].word))
			{
				inputLexema(input.words[i].line, LEX_SHIFTRIGHT);
			}
			else if (typeLitInt(input.words[i].word))
			{
				inputLexForLit(LEX_LITERAL, input.words[i], IT::IDDATATYPE::UNSINT32, countLit);
			}
			else if (typeLitTrue(input.words[i].word))
			{
				inputLexForLit(LEX_LITERAL, input.words[i], IT::IDDATATYPE::BOOLEAN, countLit);
			}
			else if (typeLitFalse(input.words[i].word))
			{
				inputLexForLit(LEX_LITERAL, input.words[i], IT::IDDATATYPE::BOOLEAN, countLit);
			}
			else if (typeLitSymbol(input.words[i].word))
			{
				inputLexForLit(LEX_LITERAL, input.words[i], IT::IDDATATYPE::SYMBOL, countLit);
			}
			else if (typeLitStr(input.words[i].word))
			{
				inputLexForLit(LEX_LITERAL, input.words[i], IT::IDDATATYPE::LINE, countLit);
			}
			else if (typeID(input.words[i].word))
			{
				if(strlen(input.words[i].word) >= 9)
				{
					memset(&input.words[i].word[9], '\0', strlen(input.words[i].word) - 9);
				}
				
				if(input.words[i].word[0] >= '0' && input.words[i].word[0] <= '9')
				{
					Log::WriteError(log, Error::geterrorin(614, input.words[i].line, input.words[i].col));
					errorCount++;
					flags.Error = true;
				}
				if (!flags.UseFunc && !flags.UseProc && flags.UseLeftFigure && !flags.UseRightFigure)
				{
					if (flags.UseBoolean)
					{
						strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(610, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::BOOLEAN, IT::IDTYPE::V, nameFunc);
						}
							flags.UseBoolean = false;
					}
					else if (flags.UseLine)
					{
						strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(610, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::LINE, IT::IDTYPE::V, nameFunc);
						}
						flags.UseLine = false;
					}
					else if (flags.UseSymbol)
					{
						strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(610, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::SYMBOL, IT::IDTYPE::V, nameFunc);
						}
						flags.UseSymbol = false;
					}
					else if (flags.UseUnsInt32)
					{
						strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(610, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::UNSINT32, IT::IDTYPE::V, nameFunc);
						}
						flags.UseUnsInt32 = false;
					}
					else if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
					{
						inputLexId(LEX_ID, input.words[i], IsId(idtable, input.words[i].word, nameFunc));
					}
					else 
					{
						strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							inputLexId(LEX_ID, input.words[i], IsId(idtable, input.words[i].word, nameFunc));
						}
						else
						{
							Log::WriteError(log, Error::geterrorin(615, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
						}	
					}
				}
				else if ((flags.UseFunc || flags.UseProc) && flags.UseLeftCircle && !flags.UseRightCircle && !flags.UseLeftFigure)
				{
					strcat_s(input.words[i].word, sizeof(input.words[i].word), nameFunc);
					if (flags.UseMain)
					{
						Log::WriteError(log, Error::geterrorin(616, input.words[i].line, input.words[i].col));
						errorCount++;
						flags.Error = true;
					}
					if (flags.UseBoolean)
					{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::BOOLEAN, IT::IDTYPE::P, nameFunc);
						flags.UseBoolean = false;
					}
					else if (flags.UseSymbol)
					{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::SYMBOL, IT::IDTYPE::P, nameFunc);
						flags.UseSymbol = false;
					}
					else if (flags.UseLine)
					{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::LINE, IT::IDTYPE::P, nameFunc);
						flags.UseLine = false;
					}
					else if (flags.UseUnsInt32)
					{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::UNSINT32, IT::IDTYPE::P, nameFunc);
						flags.UseUnsInt32 = false;
					}
				}
				else if(flags.UseFunc && !flags.UseLeftFigure && !flags.UseLeftCircle)
				{
					if(flags.UseMain)
					{
						Log::WriteError(log, Error::geterrorin(616, input.words[i].line, input.words[i].col));
						errorCount++;
						flags.Error = true;
					}
					if (flags.UseBoolean)
					{
						strcpy_s(nameFunc, ID_MAXSIZE, input.words[i].word);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(611, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
							memset(nameFunc, '\0', strlen(nameFunc));
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::BOOLEAN, IT::IDTYPE::F, nameFunc);
						}
						
						flags.UseBoolean = false;
					}
					else if (flags.UseSymbol)
					{
							strcpy_s(nameFunc, ID_MAXSIZE, input.words[i].word);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(611, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
							memset(nameFunc, '\0', strlen(nameFunc));
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::SYMBOL, IT::IDTYPE::F, nameFunc);
						}
						flags.UseSymbol = false;
					}
					else if (flags.UseLine)
					{
						strcpy_s(nameFunc, ID_MAXSIZE, input.words[i].word);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(611, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
							memset(nameFunc, '\0', strlen(nameFunc));
						}
						else
						{
							inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::LINE, IT::IDTYPE::F, nameFunc);
						}
						flags.UseLine = false;
					}
					else if (flags.UseUnsInt32)
					{
						strcpy_s(nameFunc, ID_MAXSIZE, input.words[i].word);
						if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(611, input.words[i].line, input.words[i].col));
							errorCount++;
							flags.Error = true;
							memset(nameFunc, '\0', strlen(nameFunc));
						}
						else
						{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::UNSINT32, IT::IDTYPE::F, nameFunc);
						}
						flags.UseUnsInt32 = false;
					}
					else
					{
						Log::WriteError(log, Error::geterrorin(617, input.words[i].line, input.words[i].col));
						errorCount++;
						flags.Error = true;
					}
				}
				else if (flags.UseProc && !flags.UseLeftFigure && !flags.UseLeftCircle)
				{
					if (flags.UseMain)
					{
						Log::WriteError(log, Error::geterrorin(616, input.words[i].line, input.words[i].col));
						errorCount++;
						flags.Error = true;
					}
					if (flags.UseBoolean || flags.UseSymbol || flags.UseUnsInt32 || flags.UseLine)
					{
						Log::WriteError(log, Error::geterrorin(618, input.words[i].line, input.words[i].col));
						flags.Error = true;
					}
					strcpy_s(nameFunc, ID_MAXSIZE, input.words[i].word);
					if (IT::IsId(idtable, input.words[i].word, nameFunc) != TI_NULLIDX)
					{
						Log::WriteError(log, Error::geterrorin(611, input.words[i].line, input.words[i].col));
						errorCount++;
						flags.Error = true;
					}
					else
					{
						inputLexId(LEX_ID, input.words[i], IT::IDDATATYPE::NO, IT::IDTYPE::PR, nameFunc);
					}
				}

				else if (!flags.DataInFunc)
				{
					Log::WriteError(log, Error::geterrorin(619, input.words[i].line, input.words[i].col));
					errorCount++;
					flags.Error = true;
				}
				else
				{
					Log::WriteError(log, Error::geterrorin(206, input.words[i].line, input.words[i].col));
					errorCount++;
					flags.Error = true;
				}
			}
			else if (input.words[i].word[0] == '\'')
			{
				Log::WriteError(log, Error::geterrorin(621, input.words[i].line, input.words[i].col));
				errorCount++;
				flags.Error = true;
			}
			else
			{
				Log::WriteError(log, Error::geterrorin(206, input.words[i].line, input.words[i].col));
				errorCount++;
				flags.Error = true;
			}
		}
		if (!flags.UseMain)
		{
			Log::WriteError(log, Error::geterror(620));
			errorCount++;
			flags.Error = true;
		}
		if (!flags.Error)
		{
			Log::WriteLine(log, (char*)"\n\nЛексический анализ закончился без ошибок.", "");
		}
		else
		{
			//char a[4]{};
			//_itoa_s(errorCount, a, 10);
			//Log::WriteLine(log, (char*)"\nЛексический анализ закончился с количествои ошибок: ",(char*)a, "");
		}
		TableLaI laiTable;
		laiTable.idtable = idtable;
		laiTable.lextable = lextable;
		return laiTable;
		delete[]nameFunc;
 }
	In::Word* EditTextInWords(In::IN &data,Log::LOG log)
	{
		//setlocale(LC_ALL, "Russian");
		data.words = new In::Word[LT_MAXSIZE];
		char* word = new char[TI_STR_MAXSIZE]{};
		short localsize = 0;
		short localline = 0;
		short size = 0;
		for (int i = 0; i < data.size; i++, localsize++)
		{
			switch (data.code[data.text[i]])
			{
				case data.G: inputWord(data, word, localsize - size, localline);
							 size = 0;
						     break;
				case data.O: {char* word2 = new char[TI_STR_MAXSIZE]{};
							 strcpy_s(word2, TI_STR_MAXSIZE, word);
							 inputWord(data, word, localsize - size, localline);
							 size = 0;
							 word[size++] = data.text[i];
							 if (data.text[i] == '(' || data.text[i] == ')' || data.text[i] == '{' || data.text[i] == ';'
								 || data.text[i] == '}' || data.text[i] == ']' || data.text[i] == '[')
							 {
								 inputWord(data, word, localsize - size + 1, localline);
							 }
							 else if (data.text[i] == ':' || data.text[i] == '>' || data.text[i] == '<')
							 {
								 while (data.code[data.text[i + 1]] == data.O)
								 {
									 if (data.text[i + 1] == '=' || data.text[i + 1] == '>' || data.text[i + 1] == '<'
										 || data.text[i + 1] == ':')
									 {
										 word[size++] = data.text[++i];
										 ++localsize;
									 }
								 }
								 inputWord(data, word, localsize - size, localline);
							 }
							 else if (data.text[i] == '=')
							 {
								 if (data.text[i + 1] == '=')
								 {
									 word[size++] = data.text[++i];
								 }
								 inputWord(data, word, localsize - size, localline);
							 }
							 else if (data.text[i] == '-' || data.text[i] == '+' || data.text[i] == '*' || data.text[i] == '/')
							 {
								 if (data.code[data.words[data.sizeWord - 1].word[0]] != data.O)
								 {
									 inputWord(data, word, localsize - size, localline);
								 }
								 else if (word2[0] != '\0' || data.text[i - 1] == '(' || data.text[i - 1] == ')' ||
									 data.text[i - 1] == '\'' || data.text[i - 1] == '\"')
								 {
									 inputWord(data, word, localsize - size, localline);
								 }
								 else
								 {
									 continue;
								 }
							 }
							 else
							 {
								 inputWord(data, word, localsize - size, localline);
							 }
							 size = 0; 
							 delete[]word2;
							 break;}
				case data.M: inputWord(data, word, localsize - size, localline);
							 size = 0;
							 word[size++] = data.text[i];
							 while (data.code[data.text[i + 1]] != data.M && i < data.size - 1)
							 {
								 if (size > 3)
								 {
									 throw Error::geterrorin(621, localline, localsize - size + 1);
								 }
								 word[size++] = data.text[++i]; ++localsize;
								 if (data.code[data.text[i + 1]] == data.M)
								 {
									 word[size++] = data.text[i + 1];
								 }
							 }
							 i++; localsize++;
							 inputWord(data, word, localsize - size + 1, localline);
							 size = 0;
							 break;
				case data.H: inputWord(data, word, localsize - size, localline);
							 size = 0;
							 word[size++] = data.text[i];
							 while (data.code[data.text[i + 1]] != data.H)
							 {
								 if (size >= WORD_MAXSIZE - 2)
								 {
									 throw Error::geterrorin(612, localline, localsize - size + 1);
								 }
								 char x;
								 x = data.text[++i];
								 word[size++] = x;
								 //char t = word[size - 1];
								 if (data.code[data.text[i + 1]] == data.H)
								 {
									 word[size++] = data.text[i + 1];
								 }
								 localsize++;
							 }
							 i++; localsize++;
							 inputWord(data, word, localsize - size + 1, localline);
							 size = 0;
							 break;
				case data.S: inputWord(data, word, localsize - size + 1, localline);
							 localline++;
							 localsize = -1;
							 size = 0;
						     break;
				case data.T: if (size < 10)
							{
								word[size++] = data.text[i];
							}
							break;	
			}
		}
		delete[]word;
		return data.words;
	}
	
	void inputWord(In::IN &data, char* word, short col, short line)
	{
		if (word[0] == '\0')
		{
			return;
		}
		strcpy_s(data.words[data.sizeWord].word,strlen(word) + 1, word);
		data.words[data.sizeWord].col = col;
		data.words[data.sizeWord++].line = line;
		memset(word, '\0', TI_STR_MAXSIZE);
	}
	void inputLexema(int line, char lex)
	{
		LT::Entry lexema;
		memset(lexema.lexemaх, '\0', 2);
		lexema.lexemaх[0] = lex;
		lexema.sn = line;
		LT::Add(lextable, lexema);
	}
	void inputLexForLit(char lex, In::Word word, IT::IDDATATYPE a, int& countL)
	{
		if (lex == LEX_LITERAL)
		{
			LT::Entry lexE;
			lexE.sn = word.line;
			memset(lexE.lexemaх, '\0', 2);
			lexE.lexemaх[0] = lex;
			char CLit[ID_MAXSIZE] = "L";
			char count[ID_MAXSIZE - 1] = "";
			_itoa_s(countL, count, strlen(count) - 1, 10);
			strcat_s(CLit, count);
			if (a == IT::IDDATATYPE::UNSINT32)
			{
				int idV = IT::findLiteral(idtable, IT::IDDATATYPE::UNSINT32, word.word);
				if (idV == TI_NULLIDX)
				{
					countL++;
					IT::Entry id;
					strcpy_s(id.id, CLit);
					id.iddatatype = IT::IDDATATYPE::UNSINT32;
					id.idtype = IT::IDTYPE::L;
					id.idxfirstLE = lextable.size;
					if(strlen(word.word) >= strlen("4294967295"))
					{
						char maxInt[] = "4294967295";
						bool flag1 = false;
						for (int jk = 0; jk < strlen(word.word); jk++)
						{
							if (word.word[jk] > maxInt[jk])
							{
								flag1 = true;
							}
							else if (word.word[jk] < maxInt[jk])
							{
								break;
							}
						}
						if (flag1)
						{
							id.value.vunsint32 = 0;
						}
						else
						{
							id.value.vunsint32 = INT32_MAX;
						}
					}
					else
					{
						id.value.vunsint32 = atoi(word.word);
					}
					
					lexE.idxTI = idtable.size;
					LT::Add(lextable, lexE);
					IT::Add(idtable, id);
				}
				else
				{
					lexE.idxTI = idV;
					LT::Add(lextable, lexE);
				}
			}
			if (a == IT::IDDATATYPE::LINE)
			{
				char wordW[TI_STR_MAXSIZE];
				strcpy_s(wordW, &word.word[1]);
				wordW[strlen(wordW) - 1] = '\0';
				int idV = IT::findLiteral(idtable, IT::IDDATATYPE::LINE, wordW);
				if (idV == TI_NULLIDX)
				{
					countL++;
					IT::Entry id;
					strcpy_s(id.id, CLit);
					id.iddatatype = IT::IDDATATYPE::LINE;
					id.idtype = IT::IDTYPE::L;
					id.idxfirstLE = lextable.size;
					strcpy_s(id.value.vline->str, wordW);
					id.value.vline->len = strlen(wordW);
					lexE.idxTI = idtable.size;
					LT::Add(lextable, lexE);
					IT::Add(idtable, id);
				}
				else
				{
					lexE.idxTI = idV;
					LT::Add(lextable, lexE);
				}
			}
			if (a == IT::IDDATATYPE::BOOLEAN)
			{
				int idV = IT::findLiteral(idtable, IT::IDDATATYPE::BOOLEAN, word.word);
				if (idV == TI_NULLIDX)
				{
					countL++;
					IT::Entry id;
					strcpy_s(id.id, CLit);
					id.iddatatype = IT::IDDATATYPE::BOOLEAN;
					id.idtype = IT::IDTYPE::L;
					id.idxfirstLE = lextable.size;
					strcmp(word.word, "false") == 0 ? id.value.vboolean = false : id.value.vboolean = true;
					lexE.idxTI = idtable.size;
					LT::Add(lextable, lexE);
					IT::Add(idtable, id);
				}
				else
				{
					lexE.idxTI = idV;
					LT::Add(lextable, lexE);
				}
			}
			if (a == IT::IDDATATYPE::SYMBOL)
			{
				char wordW[4];
				strcpy_s(wordW, &word.word[1]);
				wordW[strlen(wordW) - 1] = '\0';
				int idV = IT::findLiteral(idtable, IT::IDDATATYPE::SYMBOL, wordW);
				if (idV == TI_NULLIDX)
				{
					countL++;
					IT::Entry id;
					strcpy_s(id.id, CLit);
					id.iddatatype = IT::IDDATATYPE::SYMBOL;
					id.idtype = IT::IDTYPE::L;
					id.idxfirstLE = lextable.size;
					id.value.vsymbol = wordW[0];
					lexE.idxTI = idtable.size;
					LT::Add(lextable, lexE);
					IT::Add(idtable, id);
				}
				else
				{
					lexE.idxTI = idV;
					LT::Add(lextable, lexE);
				}
			}
		}
	}
	void inputLexId(char lex, In::Word word, IT::IDDATATYPE a,IT::IDTYPE type, char* nameFunc)
	{
		int idV;
		LT::Entry lexema;
		IT::Entry id;
		lexema.sn = word.line;
		memset(lexema.lexemaх, '\0', 2);
		memset(&word.word[ID_MAXSIZE - 1], '\0', strlen(word.word));
		lexema.lexemaх[0] = lex;
		idV = IT::IsId(idtable, word.word, a, type, nameFunc);
		if (idV == TI_NULLIDX)
		{
			id.iddatatype = a;
			id.idtype = type;
			int a = strlen(nameFunc) - 1;
			strcpy_s(id.nameFunc, ID_MAXSIZE - 1, nameFunc);
			strcpy_s(id.id, ID_MAXSIZE, word.word);
			id.idxfirstLE = lextable.size;
			lexema.idxTI = idtable.size;
			IT::Add(idtable, id);
			LT::Add(lextable, lexema);
		}
		else
		{
			lexema.idxTI = idV;
			LT::Add(lextable, lexema);
		}
	}
	void inputLexId(char lex, In::Word word, int id)
	{
		LT::Entry lexE;
		lexE.idxTI = id;
		lexE.sn = word.line;
		memset(lexE.lexemaх, '\0', 2);
		lexE.lexemaх[0] = lex;
		LT::Add(lextable, lexE);
	}
	void WriteLexTeable(LT::LexTable lextable, Log::LOG log)
	{
		*log.stream << "\n" << "Таблица лексем:\n\n" << "     " << std::setw(15) << std::left << "Имя лексемы" << std::setw(9) << std::left << "Строка"
			<< std::setw(8) << std::left << "Индекс в таблице идентификаторов" << std::endl;
		for (int i = 0; i < lextable.size; i++)
		{
			*log.stream << std::setw(4) << std::left << i << "      " << std::setw(11) << std::left 
				<< lextable.table[i].lexemaх << "   " << std::setw(20) << std::left << lextable.table[i].sn
				<< std::setw(20) << std::left << lextable.table[i].idxTI << std::endl;
		}
	}
	void WriteIdTable(IT::IdTable idtable, Log::LOG log)
	{
		*log.stream << "\n\nТаблица идентификаторов:\n\n" << std::setw(26) << std::left << "    Имя идентификатора" 
			<< std::setw(15) << std::left << "Значение" << std::setw(30) << std::left
			<< "Индекс в таблице лексем" << std::setw(14) << std::left << "Функция" << std::setw(16) << std::left
			<< "Тип данных" << std::setw(21) << std::left << "Тип идентификатора" << std::endl;
		for (int i = 0; i < idtable.size; i++)
		{
			char iddatatype[ID_MAXSIZE]{};
			char idtype[ID_MAXSIZE]{};
			switch (idtable.table[i].idtype)
			{
				case IT::IDTYPE::F: strcpy_s(idtype, ID_MAXSIZE, "FUNCTION");
									break;
				case IT::IDTYPE::P: strcpy_s(idtype, ID_MAXSIZE, "PARAMETR");
									break;
				case IT::IDTYPE::PR: strcpy_s(idtype, ID_MAXSIZE, "PROCEDURE");
									 break;
				case IT::IDTYPE::V: strcpy_s(idtype, ID_MAXSIZE, "VARIABLE");
									break;
				case IT::IDTYPE::L: strcpy_s(idtype, ID_MAXSIZE, "LITERAL");
									break;	
			}
			switch (idtable.table[i].iddatatype)
			{
				case IT::IDDATATYPE::BOOLEAN: strcpy_s(iddatatype, ID_MAXSIZE, "BOOLEAN");
											  if(strcmp(idtype, "LITERAL") == 0)
											  {
												  if (idtable.table[i].value.vboolean)
												  {
													  *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << "true" << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
												  }
												  else
												  {
													  *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << "false" << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
												  }
											  }
											  else
											  {
												  *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
													  std::setw(18) << std::left << "false" << std::setw(4) << " "
													  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
													  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
													  std::setw(10) << " " << idtype << std::endl;
											  }
											  break;
				case IT::IDDATATYPE::UNSINT32: strcpy_s(iddatatype, ID_MAXSIZE, "UNSINT32");
											   *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << idtable.table[i].value.vunsint32 << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
											   break;
				case IT::IDDATATYPE::LINE: strcpy_s(iddatatype, ID_MAXSIZE, "LINE");
											if(strcmp(idtype, "LITERAL") == 0)
											{
												*log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
													std::setw(18) << std::left << idtable.table[i].value.vline->str << std::setw(4) << " "
													<< std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
													<< std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
													std::setw(10) << " " << idtype << std::endl;
											}
											else
											{
												*log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << "NULL" << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
											}
										   
										   break;
				case IT::IDDATATYPE::SYMBOL: strcpy_s(iddatatype, ID_MAXSIZE, "SYMBOL");
											 if(strcmp(idtype, "LITERAL") == 0)
											 {
												 *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << idtable.table[i].value.vsymbol << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
											 }
											 else
											 {
												 *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << std::left << "\\0" << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
											 }
											 break;
				case IT::IDDATATYPE::NO: strcpy_s(iddatatype, ID_MAXSIZE, "NOTYPE");
										 *log.stream << std::setw(4) << std::left << i << std::setw(8) << " " << std::setw(16) << std::left << idtable.table[i].id <<
														  std::setw(18) << "NoValue" << std::setw(4) << " "
														  << std::setw(17) << std::left << idtable.table[i].idxfirstLE << std::setw(4) << " " << std::setw(16) << std::left << idtable.table[i].nameFunc
														  << std::setw(10) << std::left << iddatatype << std::setw(10) << std::left <<
														  std::setw(10) << " " << idtype << std::endl;
										 break;
			}
		}
	}
	bool GetError()
	{
		return flags.Error;
	}
}

