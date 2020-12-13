#ifndef ENEMYSTATE_H
#define ENEMYSTATE_H

#include"GameState.h"
#include "GameManager.h"


class EnemyState:public GameState 
{
	using GameState::GameState;
	void Move(int moveX = 0, int moveY = 0);
	void DigGrass();
	void UseItem();
};

#endif