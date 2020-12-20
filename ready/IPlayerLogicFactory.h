#pragma once
#include "IPlayerLogic.h"

class Field;

class IPlayerLogicFactory { // фабрика создания логики игрока
public:
	virtual IPlayerLogic* MakePlayerLogic(int i, int j, Field* field) = 0; // фабричный метод
};
