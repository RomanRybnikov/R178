#include "HeroState.h"

void HeroState::Move(int moveX, int moveY)
{
	if (gameManager->CheckPath(moveX, moveY))
	{
		gameManager->HeroMoving(moveX, moveY);
	}
}

void HeroState::DigGrass()
{
	if (gameManager->CheckGrass())
	{
		gameManager->DigGrass();
	}
	
}

void HeroState::UseItem()
{
	if (gameManager->CheckItem())
	{
		gameManager->UseItem();
	}
}

