#pragma once
#include "IPlayerLogicFactory.h"

// генерирует рандомный лабиринт
class RandomPlayerLogicFactory:public IPlayerLogicFactory
{
public:
	virtual IPlayerLogic* MakePlayerLogic(int i, int j, Field* field); // фабричный метод
};

