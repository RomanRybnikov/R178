#include "HeroMovingObserver.h"

void HeroMovingObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The hero moved to the cell with coordinates: " + log + ".");
	std::cout << "The hero moved to the cell with coordinates: " + log + ".\n";
	delete logger;
}