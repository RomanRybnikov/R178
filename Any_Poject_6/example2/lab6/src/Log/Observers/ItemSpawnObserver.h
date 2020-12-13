#ifndef ITEMSPAWNOBSERVER_H
#define ITEMSPAWNOBSERVER_H

#include "Observer.h"

class ItemSpawnObserver:public Observer
{
	void Update(std::string log);
};

#endif