#include "ItemSpawnObserver.h"

void ItemSpawnObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("Element created by coordinates: " + log + ".");
	std::cout << "Element created by coordinates: " + log + ".\n";
	delete logger;
}