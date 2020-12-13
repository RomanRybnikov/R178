#include "LogAbstraction.h"

void LogAbstraction::PrintLog(std::string log) const
{
	currentObserver->Update(log);
}
