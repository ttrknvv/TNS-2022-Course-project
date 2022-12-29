#include "LOG.h"	

#pragma warning(disable:4996)
using namespace std;

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log;
		log.stream = new ofstream;
		log.stream->open(logfile);
		if (log.stream->fail())
			throw ERROR_THROW(112);
		wcscpy_s(log.logfile, logfile);//�������� ���� � log
		return log;
	}
	void WriteLine(LOG log, const char* c, ...)
	{
		const char** ptr = &c;//������ ��������� �� ������ ������
		int i = 0;
		while (ptr[i] != "")//������ ��������,� ������� ������� �� ""
			*log.stream << ptr[i++];
		*log.stream << endl;
	}
	void WriteLine(LOG log, const wchar_t* c, ...)
	{
		const wchar_t** ptr = &c;

		int i = 0;
		while (ptr[i] != L"") {
			char* ptr_ch = new char[wcslen(ptr[i]) + 1] {};
			wcstombs(ptr_ch, ptr[i], wcslen(ptr[i]));
			ptr_ch[wcslen(ptr[i])] = 0;
			*log.stream << ptr_ch;
			i++;
			delete[] ptr_ch;
		}
		*log.stream << endl;
	}
	void WriteLog(LOG log)
	{
		tm* timeinf;
		time_t timet;
		time(&timet);
		timeinf = localtime(&timet);
		char temp[100];
		strftime(temp, sizeof(temp), "---- �������� ----- %d.%m.%y %T ----- ", timeinf);
		*log.stream << temp;
	}
	void WriteIn(LOG log, In::IN in)//����� �������� ������
	{
		*log.stream << "\n---- �������� ������ ----"
			<< "\n���������� ��������: " << in.size
			<< "\n���������������: " << in.ignor
			<< "\n���������� �����: " << in.lines + 1;
	}
	void WriteParm(LOG log, Parm::PARM parm)//������� ��������� ���������� � log
	{
		char in_text[PARM_MAX_SIZE];
		char out_text[PARM_MAX_SIZE];
		char log_text[PARM_MAX_SIZE];
		wcstombs(in_text, parm.in, PARM_MAX_SIZE);//�������� ������ � ������ char
		wcstombs(out_text, parm.out, PARM_MAX_SIZE);
		wcstombs(log_text, parm.log, PARM_MAX_SIZE);
		*log.stream << "\n---- ��������� ---- \n-in: " << in_text
			<< "\n-out: " << out_text
			<< "\n-log: " << log_text;
	}
	void WriteError(LOG log, Error::ERROR error)//�������� � ����� ������
	{
		if (log.stream)
		{
			*log.stream << "\n������ " << error.id
				<< ": " << error.message
				<< ", c����� " << error.inext.line
				<< ", ������� " << error.inext.col << endl;
		}
		else
		{
			cout << "������ " << error.id
				<< ": " << error.message
				<< ", c����� " << error.inext.line
				<< ", ������� " << error.inext.col << endl;
		}
	}
	void Close(LOG log)//��������� �����
	{
		log.stream->close();
		delete log.stream;
	}

}