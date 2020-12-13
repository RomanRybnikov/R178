#ifndef CELL_H
#define CELL_H



#include "../Items/Item.h"
#include "../Items/Key/ItemKey.h"
#include "../Items/Chest/ItemChest.h"
#include "../Items/Heart/ItemHeart.h"
#include "../Items/Key/ItemKeyFactory.h"
#include "../Items/Chest/ItemChestFactory.h"
#include "../Items/Heart/ItemHeartFactory.h"
#include "../Enemy/BeatBehaviour.h"
#include "../Enemy/TPBehaviour.h"
#include "../Enemy/RobBehaviour.h"


template<class T>class Enemy;

enum class CellType
{
	BEGIN = 0,
	END = 1,
	WALL = 2,
	TRAIL = 3,
	DIGGEDTRAIL = 4
};

class Cell
{

private:

	//Координаты относительно массива клеток
	int x, y;

	//Поля класса, хранящие информацию о клетке и том, что на ней находится
	CellType cellType;
	Item* itemOnCell = nullptr;
	Enemy<RobBehaviour>* enemyRobOnCell = nullptr;
	Enemy<TPBehaviour>* enemyTPOnCell = nullptr;
	Enemy<BeatBehaviour>* enemyBeatOnCell = nullptr;



	
public:
	
	bool isHeroOnCell = false;

	Cell() : cellType(CellType::TRAIL){}
	~Cell();

	void PlaceItem(Item* tempItem);
	void PlaceEnemy(Enemy<RobBehaviour>* enemy);
	void PlaceEnemy(Enemy<TPBehaviour>* enemy);
	void PlaceEnemy(Enemy<BeatBehaviour>* enemy);

	void DeleteEnemy();
	Enemy<RobBehaviour>* GetRobEnemy() { return enemyRobOnCell; }
	Enemy<TPBehaviour>* GetTPEnemy() { return enemyTPOnCell; }
	Enemy<BeatBehaviour>* GetBeatEnemy() { return enemyBeatOnCell; }

	void SetPosition(int x, int y);

	//Функция установки информации о клетке
	void SetType(CellType cellType);

	void DeleteItem();

	//Функции получения информации о клетке
	Item* GetItem();
	CellType GetType();
};

#endif 