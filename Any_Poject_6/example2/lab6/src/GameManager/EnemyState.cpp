#include "EnemyState.h"
#include "HeroState.h"
	
void EnemyState::Move(int moveX, int moveY)
{
	gameManager->EnemyMoving();
	gameManager->SetState(new HeroState(gameManager));
}

void EnemyState::DigGrass()
{
	return;
}

void EnemyState::UseItem()
{
	return;
}
