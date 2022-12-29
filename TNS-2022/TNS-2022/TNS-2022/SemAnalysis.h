#pragma once
#include "LexAnalysis.h"

namespace SEM
{
	void SemanticAnalysis(LEX::TableLaI tableLaI, Log::LOG log);
	bool GetError();
}