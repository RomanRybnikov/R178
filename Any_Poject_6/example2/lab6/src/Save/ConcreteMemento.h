#ifndef CONCRETEMEMENTO_H 
#define CONCRETEMEMENTO_H

#include "Memento.h"

class ConcreteMemento:public Memento
{
private: 
	GameInfo state;
public:
	ConcreteMemento(GameInfo state);
	GameInfo& State();
	void ChangeState(GameInfo state);
};

#endif
