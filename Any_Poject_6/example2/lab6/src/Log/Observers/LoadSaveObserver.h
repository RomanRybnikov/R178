#ifndef LOADSAVEOBSERVER_H
#define LOADSAVEOBSERVER_H

#include "Observer.h"

class LoadSaveObserver:public Observer
{
public:
	void Update(std::string log);
};

#endif

