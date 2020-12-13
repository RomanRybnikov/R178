#ifndef HEROSTATE_H
#define HEROSTATE_H

#include "GameState.h"
#include "GameManager.h"
#include "EnemyState.h"

class HeroState: public GameState
{
	using GameState::GameState;
	void Move(int moveX = 0, int moveY = 0);
	void DigGrass();
	void UseItem();
};

#endif
