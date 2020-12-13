#include "ItemUseObserver.h"

void ItemUseObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("Element used " + log + ".");
	std::cout << "Element used " + log + ".\n";
	delete logger;
}