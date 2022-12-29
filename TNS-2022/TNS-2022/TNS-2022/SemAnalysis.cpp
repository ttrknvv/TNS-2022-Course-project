#include "stdafx.h"
#include "SemAnalysis.h"
namespace SEM
{
	bool error = false;
	void SemanticAnalysis(LEX::TableLaI tableLaI, Log::LOG log)
	{
		for (int i = 0; i < tableLaI.lextable.size; i++)
		{
			switch (tableLaI.lextable.table[i].lexema�[0])
			{
				case LEX_MORE: // ���������� ��������
				case LEX_LESS:
				case LEX_EQUALS:
								if (i < 1 || tableLaI.lextable.table[i - 1].idxTI == TI_NULLIDX) // ���� �������� �������
								{
									Log::WriteError(log, Error::geterrorin(608, tableLaI.lextable.table[i].sn, -1));
									error = true;
								}
								if (i >= 1 && (tableLaI.lextable.table[i - 1].idxTI != TI_NULLIDX)) // ���� ������ ������� �� unsint32
								{
									if (tableLaI.idtable.table[tableLaI.lextable.table[i - 1].idxTI].iddatatype != IT::IDDATATYPE::UNSINT32)
									{
										Log::WriteError(log, Error::geterrorin(600, tableLaI.lextable.table[i].sn, -1));
										error = true;
									}
								}
								if (tableLaI.lextable.table[i + 1].idxTI != TI_NULLIDX) // ���� ������ ������� �� unsint32
								{
									if (tableLaI.idtable.table[tableLaI.lextable.table[i + 1].idxTI].iddatatype != IT::IDDATATYPE::UNSINT32)
									{
										Log::WriteError(log, Error::geterrorin(600, tableLaI.lextable.table[i].sn, -1));
										error = true;
									}
									break;
								}
								break;
				case LEX_GRAB: // ����������
								if(tableLaI.lextable.table[i - 1].idxTI != TI_NULLIDX) // �������� ������ �������
								{
									bool ignore = true;
									IT::IDDATATYPE leftOp = tableLaI.idtable.table[tableLaI.lextable.table[i - 1].idxTI].iddatatype;
									for (int k = i + 1; tableLaI.lextable.table[k].lexema�[0] != LEX_SEMICOLON; k++)
									{
										if (tableLaI.lextable.table[k].idxTI != TI_NULLIDX && ignore) // ������� ��������� ������������� ��� �������
										{
											IT::IDDATATYPE nextOp = tableLaI.idtable.table[tableLaI.lextable.table[k].idxTI].iddatatype;
											if (leftOp != nextOp) // �� ��������� ����
											{
												Log::WriteError(log, Error::geterrorin(601, tableLaI.lextable.table[k].sn, -1));
												error = true;
											}
										}
										if (leftOp != IT::IDDATATYPE::UNSINT32) // �������� ���������� ������ ��� unsint32 
										{
											char op = tableLaI.lextable.table[k].lexema�[0];
											if (op == LEX_DIRSLASH || op == LEX_PLUS || op == LEX_MINUS || op == LEX_STAR ||
												op == LEX_SHIFTLEFT || op == LEX_SHIFTRIGHT)
											{
												Log::WriteError(log, Error::geterrorin(602, tableLaI.lextable.table[k].sn, -1));
												error = true;
											}
										}
										if (tableLaI.lextable.table[k + 1].lexema�[0] == LEX_LEFTTHESIS)
										{
											ignore = false;
										}
										if (tableLaI.lextable.table[k + 1].lexema�[0] == LEX_RIGHTTHESIS)
										{
											ignore = true;
										}
										if (tableLaI.lextable.table[k].lexema�[0] == LEX_DIRSLASH)
										{
											if (tableLaI.lextable.table[k + 1].idxTI != TI_NULLIDX && tableLaI.idtable.table[tableLaI.lextable.table[k + 1].idxTI].idtype == IT::IDTYPE::L &&
												tableLaI.idtable.table[tableLaI.lextable.table[k + 1].idxTI].value.vunsint32 == 0)
											{
												Log::WriteError(log, Error::geterrorin(625, tableLaI.lextable.table[k].sn, -1));
												error = true;
											}
										}
									}
								}
								break;
				case LEX_FUNCTION: 
								   {IT::IDDATATYPE typeFunc = tableLaI.idtable.table[tableLaI.lextable.table[i + 2].idxTI].iddatatype;
								   for (int k = i + 1; ; k++) // �������� ������������� ��������
								   {
									   if (tableLaI.lextable.table[k].lexema�[0] == LEX_RETURN)
									   {
										   if (tableLaI.lextable.table[k + 1].idxTI == LI_TI_NULLIDX)
										   {
											   Log::WriteError(log, Error::geterrorin(609, tableLaI.lextable.table[k].sn, -1));
											   error = true;
											   break;
										   }
										   if (tableLaI.idtable.table[tableLaI.lextable.table[k + 1].idxTI].iddatatype != typeFunc)
										   {
											   Log::WriteError(log, Error::geterrorin(603, tableLaI.lextable.table[k].sn, -1));
											   error = true;
										   }
										   break;
									   }
								   }
								   break;
								   }
				case LEX_PROCEDURE: // ��������� �� ����� ����� ���� ��� ������������� ��������
									if(tableLaI.lextable.table[i + 1].lexema�[0] == LEX_SYMBOL)
									{
										Log::WriteError(log, Error::geterrorin(604, tableLaI.lextable.table[i].sn, -1));
										error = true;
									}
									for (int k = i + 1; ; k++)
									{
										if (tableLaI.lextable.table[k].lexema�[0] == LEX_RETURN)
										{
											if (tableLaI.lextable.table[k + 1].lexema�[0] != LEX_SEMICOLON)
											{
												Log::WriteError(log, Error::geterrorin(605, tableLaI.lextable.table[k].sn, -1));
												error = true;
											}
											break;
										}
									}
									break;
				case LEX_ID: {
					LT::Entry entry = tableLaI.lextable.table[i]; // �������� ������ �������
					if (tableLaI.lextable.table[i + 1].lexema�[0] == LEX_LEFTTHESIS &&
						(tableLaI.lextable.table[i - 2].lexema�[0] != LEX_FUNCTION &&
							tableLaI.lextable.table[i - 1].lexema�[0] != LEX_PROCEDURE))
					{
						if (tableLaI.idtable.table[entry.idxTI].idtype == IT::IDTYPE::F ||
							tableLaI.idtable.table[entry.idxTI].idtype == IT::IDTYPE::PR)
						{
							int paramsCount = 0;
							for (int k = i + 1; ; k++)
							{
								if ((tableLaI.lextable.table[k].lexema�[0] == LEX_ID ||
									tableLaI.lextable.table[k].lexema�[0] == LEX_LITERAL))
								{
									paramsCount++;
									if (tableLaI.idtable.table[entry.idxTI + paramsCount].idtype == IT::IDTYPE::P)
									{
										if (tableLaI.idtable.table[tableLaI.lextable.table[k].idxTI].iddatatype
											!= tableLaI.idtable.table[entry.idxTI + paramsCount].iddatatype)
										{
											Log::WriteError(log, Error::geterrorin(606, tableLaI.lextable.table[k].sn, -1));
											error = true;
										}

									}
									else
									{
										Log::WriteError(log, Error::geterrorin(607, tableLaI.lextable.table[k].sn, -1));
										error = true;
									}
								}
								else if (tableLaI.lextable.table[k].lexema�[0] == LEX_RIGHTTHESIS)
								{
									paramsCount++;
									if (tableLaI.idtable.table[entry.idxTI + paramsCount].idtype == IT::IDTYPE::P)
									{
										Log::WriteError(log, Error::geterrorin(607, tableLaI.lextable.table[k].sn, -1));
										error = true;
									}
									break;
								}
							}
						}
						else if (tableLaI.idtable.table[entry.idxTI].idtype == IT::IDTYPE::BF)
						{
							if (tableLaI.lextable.table[i + 2].lexema�[0] != LEX_RIGHTTHESIS)
							{
								Log::WriteError(log, Error::geterrorin(607, tableLaI.lextable.table[i].sn, -1));
								error = true;
							}
							break;
						}
					}
					break;
				}
				case LEX_IF: // �������� ��������� ���������
				{
					if (tableLaI.idtable.table[tableLaI.lextable.table[i + 2].idxTI].iddatatype != IT::IDDATATYPE::BOOLEAN)
					{
						if (tableLaI.lextable.table[i + 4].idxTI == TI_NULLIDX)
						{
							Log::WriteError(log, Error::geterrorin(624, tableLaI.lextable.table[i].sn, -1));
							error = true;
						}
					}
					break;
				}
			}
		}
		if (!error) // ���� �� �� ����� �� ������ ������ �� ����, �� ��
		{
			*log.stream << "������������� ������ �������� ��� ������.";
		}
	}
	bool GetError()
	{
		return error;
	}
}