#ifndef ENEMY_H
#define ENEMY_H

#include "../Hero/Hero.h"
#include "../GameField/Field.h"


template<class T>
class Enemy
{
private:
	T behaviour;
	int x = 0, y = 0;
public:
	bool goUp = false;
	Enemy(int y, int x) : x(x), y(y) {}
	int getX() { return x; }
	int getY() { return y; }

	void SetPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	void Move()
	{
		int dy;
		if (goUp) dy = -1;
		else dy = 1;
		Field* gameField = Field::GetInstance();
		if (y+dy < 0 || y+dy >= 11 || gameField->GetField()[y + dy][x].GetType() == CellType::WALL)
		{
			y -= dy;
			goUp = !goUp;
			return;
		}
		y += dy;
	}
	void operator-(Hero& hero)
	{
		behaviour.Action(hero);
	}

};
#endif

