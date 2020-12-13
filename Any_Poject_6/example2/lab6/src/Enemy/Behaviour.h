#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "../Hero/Hero.h"

class Behaviour
{
public: 
	virtual void Action(Hero& hero) = 0;
};

#endif