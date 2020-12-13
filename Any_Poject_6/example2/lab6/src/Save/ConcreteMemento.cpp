#include "ConcreteMemento.h"

ConcreteMemento::ConcreteMemento(GameInfo state)
{
	this->state = state;
}

void ConcreteMemento::ChangeState(GameInfo state)
{
	this->state = state;
}

GameInfo& ConcreteMemento::State()
{
	return state;
}
