#pragma once
#include "IPlayerLogicFactory.h"

class CirclePlayerLogicFactory :public IPlayerLogicFactory
{
public:
	virtual IPlayerLogic* MakePlayerLogic(int i, int j, Field* field); // фабричный метод
};

