#include "ERROR.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,"Недопустимый код ошибки"),
		ERROR_ENTRY(1,"Системный сбой"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110,"Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111,"Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112,"Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY(113, "Ошибка при создании выходного файла (-out)"),ERROR_ENTRY(114, "Превышен размер исходного файла"), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116),ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160),ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Превышен максимальный размер таблицы идентификаторов"),
		ERROR_ENTRY(201, "Превышено максимальное количество идентификаторов"),
		ERROR_ENTRY(202, "Идентификатор не определен"),
		ERROR_ENTRY(203, "Превышен максимальный размер таблицы лексем"),
		ERROR_ENTRY(204, "Превышено максимальное количество лексем"),
		ERROR_ENTRY(205, "Лексема не определена"),
		ERROR_ENTRY(206, "Нераспознанная лексема"), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220),
		ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), 
		ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Неверная структура программы(возможно была утеряна фигурная скобка)"),
		ERROR_ENTRY(301, "Неверная конструкция параметров функции"),
		ERROR_ENTRY(302, "Неверная структура списка параметров функции"),
		ERROR_ENTRY(303, "Неверная структура тела функции"),
		ERROR_ENTRY(304, "Ожидался идентификатор или литерал"),
		ERROR_ENTRY(305, "Неверная структура тела функции"),
		ERROR_ENTRY(306, "Неверная структура арифметического выражения"),
		ERROR_ENTRY(307, "Неверно заданы арифметические операторы"),
		ERROR_ENTRY(308, "Ошибка в передаваемых аргументах"),
		ERROR_ENTRY(309, "Ошибка в списке аргументов, передаваемых в функцию"),
		ERROR_ENTRY(310, "Неверная структура процедуры"),
		ERROR_ENTRY(311, "Неверная построено условное выражение"),
		ERROR_ENTRY(312, "Неверно заданы операторы сравнения"),
		ERROR_ENTRY(313, "Неверная структура тела условной конструкции"),
		ERROR_ENTRY(314, "Неверная структура в теле условной конструкции"),
		ERROR_ENTRY(315, "Неверная структура в теле иначе"), ERROR_ENTRY_NODEF(316), ERROR_ENTRY_NODEF(317),
		ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319), ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),
		ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360), ERROR_ENTRY_NODEF10(370),
		ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "В логических операциях сравнения могут учавствовать только целочисленные типы"),
		ERROR_ENTRY(601, "В присвоении не могут учавствовать операнды разных типов"),
		ERROR_ENTRY(602, "Недопустимое выражения для типа, не являющимcя unsint32"),
		ERROR_ENTRY(603, "Тип возвращаемого значения и тип функции не совпадают"),
		ERROR_ENTRY(604, "Процедура не может иметь тип"),
		ERROR_ENTRY(605, "Процедура не может иметь возвращаемого значения"),
		ERROR_ENTRY(606, "Типы параметров не совпадают"),
		ERROR_ENTRY(607, "Количество параметров не совпадают"),
		ERROR_ENTRY(608, "Пропущен операнд в операции сравнения"),
		ERROR_ENTRY(609, "Не найдено возвращаемого значения функции"),
		ERROR_ENTRY(610, "Переопределение идентификатора"),
		ERROR_ENTRY(611, "Функции с одинаковыми именами не поддерживаются"),
		ERROR_ENTRY(612, "Превышен размер строкового литерала"),
		ERROR_ENTRY(613, "В программе может быть только одна точка входа(MAIN)"),
		ERROR_ENTRY(614, "Неправильная запись идентификатора"),
		ERROR_ENTRY(615, "Не найдено определения идентификатора"),
		ERROR_ENTRY(616, "Данные не могут располагаться вне блока функции MAIN"), //211
		ERROR_ENTRY(617, "Не найдено определения типа данных функции"),
		ERROR_ENTRY(618, "Процедура не может иметь возвращаемого значения"),
		ERROR_ENTRY(619, "Данные не могут располагаться вне блока функции"),
		ERROR_ENTRY(620, "Не найдено точки входа в программу(MAIN)"),
		ERROR_ENTRY(621, "Тип данныз symbol должен состоять из одного символа(возмонжо вы забыли закрывающий символ \')"),
		ERROR_ENTRY(622, "Отрицательные значения литералов не поддерживаются"),
		ERROR_ENTRY(623, "Имя функции не может совпадать с именем стандартной функции"),
		ERROR_ENTRY(624, "В выражении под условием могут подразумеваться только переменные типа bool либо выражение"),
		ERROR_ENTRY(625, "В выражении не может быть деления на 0!"),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),ERROR_ENTRY_NODEF100(900),
	};
	ERROR geterror(int id) { // id - код ошибки
		ERROR mistake; // переменная mistake структуры ERROR
		if (id < 0 || id > ERROR_MAX_ENTRY) { // 0 < id < ERROR_MAX_ENTRY
			mistake = errors[0];
		}
		else {
			mistake = errors[id];
		}
		return mistake;
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		ERROR mistake;
		if (id < 0 || id > ERROR_MAX_ENTRY) { // 0 < id < ERROR_MAX_ENTRY
			mistake = errors[0];
		}
		else
		{
			mistake = errors[id];
			mistake.inext.line = line;
			mistake.inext.col = col;
		}
		return mistake;
	}

};
