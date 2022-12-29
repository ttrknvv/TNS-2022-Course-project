//#include "Functions.h"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <Windows.h>
#pragma hdrstop
#pragma argsused
#pragma warning(disable: 4996)
#pragma comment (lib, "ddraw.lib")
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "gdi32.lib")
#pragma comment(lib,"User32.lib")
extern "C"
{
	


	char* __stdcall gettime()					// вычисление длины строки
	{
		struct tm* u;
		char timelocal[9]{};
		const time_t timer = time(NULL);
		u = localtime(&timer);
		strftime(timelocal, 9, "%H:%M:%S", u);
		timelocal[8] = '\0';
		return timelocal;
	}
	char* __stdcall getdata()
	{
		struct tm* u;
		char datalocal[11]{};
		const time_t timer = time(NULL);
		u = localtime(&timer);
		strftime(datalocal, 11, "%d.%m.%Y", u);
		datalocal[10] = '\0';
		return datalocal;
	}



	int __stdcall writenum(int value)									// вывод в консоль целочисленного литерала
	{
		std::cout << value;
		return 0;
	}


	int __stdcall writestr(char* ptr)									// вывод в консоль строкового литерала
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr)
			std::cout << std::endl;
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		return 0;
	}

	int __stdcall writelnstr(char* ptr)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (ptr == nullptr)
			std::cout << std::endl;
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		std::cout << std::endl;
		return 0;
	}
	int __stdcall writelnnum(int value)									// вывод в консоль целочисленного литерала
	{
		std::cout << value << std::endl;
		return 0;
	}
	void __stdcall getError()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		MessageBox(GetActiveWindow(), "625, В выражении не может быть деления на 0!", "Ошибка 625", MB_ICONERROR);
	}
}