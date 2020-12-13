#include "SaveObserver.h"

void SaveObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("Game Saved.");
	std::cout << "Game Saved.\n";
	delete logger;
}
