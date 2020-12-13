#ifndef OBSERVER_H
#define OBSERVER_H
#include "../LogFile.h"

class Observer
{
public:
	
	virtual	void Update(std::string log) = 0;
};

#endif