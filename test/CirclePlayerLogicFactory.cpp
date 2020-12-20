#include "CirclePlayerLogicFactory.h"
#include "TeleportPlayerLogic.h"
#include "AddScoresPlayerLogic.h"
#include "DeathLogic.h"
#include "Field.h"

IPlayerLogic* CirclePlayerLogicFactory::MakePlayerLogic(int i, int j, Field* field)
{
	// получаем центр
	int ci = field->GetRow() / 2;
	int cj = field->GetCol() / 2;

	// определяем расстояние до центра
	int len = sqrt((ci - i) * (ci - i) + (cj - j) * (cj - j));

	switch (len)
	{
	case 0: return new DeathLogic();
	case 1: return new AddScoresPlayerLogic(rand() % 100);
	}

	if (len % 3 == 0) {
		if (rand() % 2) return new DeathLogic();
		else return new AddScoresPlayerLogic(rand() % 100);
	}
	return 0;
}