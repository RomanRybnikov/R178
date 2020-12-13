#include "HeroGetItemObserver.h"

void HeroGetItemObserver::Update(std::string log)
{
	LogFile* logger = new LogFile();
	logger->PrintLog("The hero received the element " + log + ".");
	std::cout << "The hero received the element " + log + ".\n";
	delete logger;
}