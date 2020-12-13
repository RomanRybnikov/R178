#ifndef ENEMYHEROMEETOBSERVER_H
#define ENEMYHEROMEETOBSERVER_H

#include "Observer.h"

class EnemyHeroMeetObserver:public Observer
{
	void Update(std::string log);
};

#endif