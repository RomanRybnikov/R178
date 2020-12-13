#include "HeroDigObserver.h"

void HeroDigObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The hero dug the ground by coordinates: " + log + ".");
	std::cout << "The hero dug the ground by coordinates: " + log + ".\n";
	delete logger;
}