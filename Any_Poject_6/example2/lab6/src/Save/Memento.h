#ifndef MEMENTO_H
#define MEMENTO_H

#include "GameInfo.h"

class Memento
{
public:
	virtual GameInfo& State() = 0;
	virtual void ChangeState(GameInfo state) = 0;
};

#endif