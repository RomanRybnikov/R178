#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


#include "LogAbstraction.h"
#include <map>


enum class Event
{
	ItemUse,
	ItemTake, 
	HeroMoving,
	HeroGetItem,
	HeroDig, 
	ItemSpawn,
	EnemySpawn,
	EnemyMove, 
	EnemyHeroMeet
};


class EventManager
{
private:
	std::map<Observer*, Event> observers;
public:
	EventManager();
	void Attach(Observer* observer, Event event);
	void Detach(Observer* observer, Event event);
	void Notify(Event event, std::string log);
	~EventManager();
	
};

#endif