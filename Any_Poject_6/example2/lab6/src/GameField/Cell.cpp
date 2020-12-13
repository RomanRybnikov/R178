#include "Cell.h"
#include <iostream>
#include "../Enemy/Enemy.h"

Item* Cell::GetItem()
{
	return itemOnCell;
}

void Cell::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Cell::SetType(CellType cellType)
{
	this->cellType = cellType;
}

void Cell::DeleteItem()
{
	delete itemOnCell;
	itemOnCell = nullptr;
}

void Cell::DeleteEnemy()
{
	if(enemyRobOnCell)
		enemyRobOnCell = nullptr;
	if(enemyTPOnCell)
		enemyTPOnCell = nullptr;
	if(enemyBeatOnCell)
		enemyBeatOnCell = nullptr;
}

CellType Cell::GetType()
{
	return cellType;
}


Cell::~Cell()
{
	if(itemOnCell)
		delete itemOnCell;
	if (enemyRobOnCell)
		delete enemyRobOnCell;
	if (enemyTPOnCell)
		delete enemyTPOnCell;
	if (enemyBeatOnCell)
		delete enemyBeatOnCell;
}

void Cell::PlaceItem(Item* tempItem)
{
	this->itemOnCell = tempItem;
}

void Cell::PlaceEnemy(Enemy<BeatBehaviour>* enemy)
{
	this->enemyBeatOnCell = enemy;
}

void Cell::PlaceEnemy(Enemy<TPBehaviour>* enemy)
{
	this->enemyTPOnCell = enemy;
}

void Cell::PlaceEnemy(Enemy<RobBehaviour>* enemy)
{
	this->enemyRobOnCell = enemy;
}

