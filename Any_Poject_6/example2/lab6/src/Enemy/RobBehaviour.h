#ifndef ROBBEHAVIOUR_H
#define ROBBEHAVIOUR_H
#include "Behaviour.h"

class RobBehaviour:public Behaviour
{
public:
	void Action(Hero& hero);
};

#endif