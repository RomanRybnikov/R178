#ifndef ENEMYMOVEDOBSERVER
#define ENEMYMOVEDOBSERVER

#include "Observer.h"

class EnemyMovedObserver:public Observer
{
	void Update(std::string log);
};

#endif
