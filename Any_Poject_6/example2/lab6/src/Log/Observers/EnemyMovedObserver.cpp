#include "EnemyMovedObserver.h"

void EnemyMovedObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The enemy moved to the cell with coordinates: " + log + ".");
	std::cout << "The enemy moved to the cell with coordinates: " + log + ".\n";
	delete logger;
}