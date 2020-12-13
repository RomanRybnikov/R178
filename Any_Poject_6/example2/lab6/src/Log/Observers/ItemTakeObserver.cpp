#include "ItemTakeObserver.h"

void ItemTakeObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("Element matched by coordinates: "+log + ".");
	std::cout << "Element matched by coordinates: " + log + ".\n";
	delete logger;
}