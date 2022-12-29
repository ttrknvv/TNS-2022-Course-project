#pragma once

#include "stdafx.h"
#include "IN.h"
#include "PARM.h"	
#include "ERROR.h"	

namespace Log// работа с протоколом
{
	struct LOG //протокол
	{
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream* stream;
	};

	static const LOG INITLOG = { L"", NULL };
	LOG getlog(wchar_t logfile[]);
	void WriteLine(LOG log, const char* c, ...);
	void WriteLine(LOG log, const wchar_t* c, ...);
	void WriteLog(LOG log);
	void WriteParm(LOG log, Parm::PARM parm);
	void WriteIn(LOG log, In::IN in);
	void WriteError(LOG log, Error::ERROR error);//Информация о ошибке
	void Close(LOG log);
};