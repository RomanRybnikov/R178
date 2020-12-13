#ifndef ENEMYSPAWNEDOBSERVER
#define ENEMYSPAWNEDOBSERVER

#include "Observer.h"

class EnemySpawnedObserver:public Observer
{
	void Update(std::string log);
};

#endif