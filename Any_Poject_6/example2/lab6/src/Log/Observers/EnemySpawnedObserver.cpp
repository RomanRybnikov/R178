#include "EnemySpawnedObserver.h"

void EnemySpawnedObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The enemy spawned by coordinates: " + log + ".");
	std::cout << "The enemy spawned by coordinates: " + log + ".\n";
	delete logger;
}