#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameManager;

class GameState
{
protected:
	GameManager* gameManager = nullptr;
public:
	GameState(GameManager* gameManager) : gameManager(gameManager){}
	virtual void Move(int moveX = 0, int moveY = 0) = 0;
	virtual void DigGrass() = 0;
	virtual void UseItem() = 0;
};

#endif
