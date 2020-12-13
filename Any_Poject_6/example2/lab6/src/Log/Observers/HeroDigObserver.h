#ifndef HERODIGOBSERVER_H
#define HERODIGOBSERVER_H

#include "Observer.h"

class HeroDigObserver:public Observer
{
	void Update(std::string log);
};

#endif

