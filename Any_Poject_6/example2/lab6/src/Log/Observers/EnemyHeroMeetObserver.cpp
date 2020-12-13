#include "EnemyHeroMeetObserver.h"

void EnemyHeroMeetObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The Hero met the Enemy" + log + ".");
	std::cout << "The Hero met the Enemy" + log + ".\n";
	delete logger;
}