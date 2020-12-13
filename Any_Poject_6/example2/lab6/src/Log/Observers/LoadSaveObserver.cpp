#include "LoadSaveObserver.h"

void LoadSaveObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("Last Save Loaded.");
	std::cout << "Last Save Loaded.\n";
	delete logger;
}
