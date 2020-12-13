#include "EventManager.h"

EventManager::EventManager()
{
}

void EventManager::Attach(Observer* observer, Event event)
{
	observers.insert(std::make_pair(observer, event));
}

void EventManager::Detach(Observer* observer, Event event)
{
	observers.erase(observer);
}

void EventManager::Notify(Event event, std::string log)
{
	std::map<Observer*, Event>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
	{
		if (it->second == event)
		{
			LogAbstraction logAbstraction(it->first);
			logAbstraction.PrintLog(log);
		}
	}
}

EventManager::~EventManager()
{
	std::map<Observer*, Event>::iterator it;
	for (it = observers.begin(); it != observers.end(); it++)
	{
		if (it->first)
			delete it->first;
	}
}