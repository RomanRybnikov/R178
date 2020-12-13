#ifndef TPBEHAVIOUR_H
#define TPBEHAVIOUR_H

#include "Behaviour.h"
class TPBehaviour:public Behaviour
{
public:
	void Action(Hero& hero);
};
#endif
