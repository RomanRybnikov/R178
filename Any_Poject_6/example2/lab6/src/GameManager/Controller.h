#ifndef STARTGAME_H
#define STARTGAME_H

#include "GameManager.h"
#include "../Commands/CloseGameCommand.h"
#include "../Commands/DigGrassCommand.h"
#include "../Commands/MoveDownCommand.h"
#include "../Commands/MoveLeftCommand.h"
#include "../Commands/MoveRightCommand.h"
#include "../Commands/MoveUpCommand.h"
#include "../Commands/StartGameCommand.h"
#include "../Commands/TakeItemCommand.h"
#include "../Save/CareTaker.h"


class Controller
{
public: 
	Controller();
	~Controller();

private: 
	
	GameManager* gameManager = nullptr;
	CareTaker* careTaker = nullptr;
	bool isGameWin = false;
	bool isGameLost = false;
	bool isGameStarted = false;
	void IsGameEnd();

	CloseGameCommand* closeGameCommand = nullptr;
	DigGrassCommand* digGrassCommand = nullptr;
	MoveDownCommand* moveDownCommand = nullptr;
	MoveLeftCommand* moveLeftCommand = nullptr;
	MoveRightCommand* moveRightCommand = nullptr;
	MoveUpCommand* moveUpCommand = nullptr;
	StartGameCommand* startGameCommand = nullptr;
	TakeItemCommand* takeItemCommand = nullptr;
};


#endif 