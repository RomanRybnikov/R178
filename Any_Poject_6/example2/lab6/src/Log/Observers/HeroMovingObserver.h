#ifndef HEROMOVINGOBSERVER_H
#define HEROMOVINGOBSERVER_H

#include "Observer.h"

class HeroMovingObserver:public Observer
{
	void Update(std::string log);
};

#endif
