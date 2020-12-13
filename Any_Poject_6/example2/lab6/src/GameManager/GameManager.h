#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "../GameField/Field.h"
#include "../Display/Display.h"
#include "iostream"
#include "../Hero/Hero.h"
#include "../Items/ItemStrategy.h"
#include "../Log/LogFile.h"
#include "../Log/EventManager.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/BeatBehaviour.h"
#include "../Enemy/RobBehaviour.h"
#include "../Enemy/TPBehaviour.h"
#include "GameState.h"
#include "HeroState.h"
#include "../Save/ConcreteMemento.h"

#include <sstream>
#include <vector>

class GameManager
{
private: 
	friend class Controller;

	ItemStrategy itemStrategy;

	GameState* gameState = nullptr;

	EventManager eventManager;
	ItemUseObserver* itemUseObserver = nullptr;
	ItemTakeObserver* itemTakeObserver = nullptr;
	ItemSpawnObserver* itemSpawnObserver = nullptr;
	HeroDigObserver* heroDigObserver = nullptr;
	HeroGetItemObserver* heroGetItemObserver = nullptr;
	HeroMovingObserver* heroMovingObserver = nullptr;
	EnemyMovedObserver* enemyMovingObserver = nullptr;
	EnemySpawnedObserver* enemySpawnObserver = nullptr;
	EnemyHeroMeetObserver* enemyHeroMeetObserver = nullptr;
	SaveObserver* saveObserver = nullptr;
	LoadSaveObserver* loadSaveObserver = nullptr;

	Enemy<BeatBehaviour>* beatEnemy = nullptr;
	Enemy<RobBehaviour>* robEnemy = nullptr;
	Enemy<TPBehaviour>* TPEnemy = nullptr;
	Display* displayView = nullptr;

	Hero hero;

	Field* gameField = nullptr;
	bool closeGame = false;

	void LogHeroInfo();
	void PlaceItems();
	void PlaceEnemies();


public:
	GameManager() = default;
	void GameSaved();
	void SetState(GameState* newState);
	void HeroMoving(int moveX, int moveY);
	void EnemyMoving();
	void DigGrass();
	void UseItem();
	void StartGame();
	void EndGame();
	void EnemyTurn();
	bool CheckPath(int x, int y);
	bool CheckGrass();
	bool CheckItem();
	Memento* Save();
	void Restore(Memento* memento);
	GameState* getState();
	~GameManager();
};

#endif