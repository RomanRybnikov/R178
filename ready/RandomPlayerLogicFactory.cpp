#include "RandomPlayerLogicFactory.h"
#include "TeleportPlayerLogic.h"
#include "AddScoresPlayerLogic.h"
#include "DeathLogic.h"

IPlayerLogic* RandomPlayerLogicFactory::MakePlayerLogic(int i, int j, Field* field)
{
	switch (rand() % 10) {
	case 0: return new TeleportPlayerLogic();
	case 1: return new AddScoresPlayerLogic(rand() % 100);
	case 2: return new DeathLogic();
	}

	return 0;
}