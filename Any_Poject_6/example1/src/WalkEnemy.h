#pragma once
#include "AreaHandler.h"
#include "Strategy.h"

class WalkEnemy
{
public:
	WalkEnemy(int _x, int _y) : x(_x), y(_y) {}

    Strategy* getStrategy() {
        return strategy;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    void move(int x, int y) {
        this->x += x;
        this->y += y;
    }

	void moveEnemy() {
        static bool isWalkRight = true;

        if (AreaHandler::getCellItem(x, y) == ItemType::PERSON)
        {
            strategy = new TrapStrategy();
            AreaHandler::clearCell(x, y);
        }
        else
        {
            if (isWalkRight)
            {
                if (AreaHandler::getCellType(x + 1, y) == CellType::VOID)
                {
                    AreaHandler::clearCell(x, y);
                    move(1, 0);
                    AreaHandler::addEnemy(this->x, this->y);
                }
                else { isWalkRight = false; }
            }
            else
            {
                if (AreaHandler::getCellType(x - 1, y) == CellType::VOID)
                {
                    AreaHandler::clearCell(x, y);
                    move(-1, 0);
                    AreaHandler::addEnemy(this->x, this->y);
                }
                else { isWalkRight = true; }
            }
            strategy = new VoidStrategy();
        }
	}

private:
	int x;
	int y;
	Strategy* strategy = new VoidStrategy();
};