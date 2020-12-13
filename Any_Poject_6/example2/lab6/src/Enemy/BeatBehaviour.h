#ifndef BEATBEHAVIOUR_H
#define BEATBEHAVIOUR_H

#include "Behaviour.h"

class BeatBehaviour:public Behaviour
{
public:
	void Action(Hero& hero);
};

#endif