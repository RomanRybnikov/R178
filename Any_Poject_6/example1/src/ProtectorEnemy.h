#pragma once
#include "AreaHandler.h"
#include "Strategy.h"

class ProtectEnemy
{
public:
    ProtectEnemy(int _x, int _y) : x(_x), y(_y) {}

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
        if (AreaHandler::getCellItem(x - 1, y) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(0, -1);
        }
        else if (AreaHandler::getCellItem(x - 1, y + 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(-1, 0);
        }
        else if (AreaHandler::getCellItem(x, y + 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(-1, 0);
        }
        else if (AreaHandler::getCellItem(x + 1, y + 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(0, 1);
        }
        else if (AreaHandler::getCellItem(x + 1, y) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(0, 1);
        }
        else if (AreaHandler::getCellItem(x + 1, y - 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(1, 0);
        }
        else if (AreaHandler::getCellItem(x, y - 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(1, 0);
        }
        else if (AreaHandler::getCellItem(x - 1, y - 1) == ItemType::COIN) {
            AreaHandler::clearCell(x, y);
            move(0, -1);
        }
        if (AreaHandler::getCellItem(this->x, this->y) == ItemType::PERSON) {
            strategy = new TrapStrategy();
            AreaHandler::clearCell(x, y);
            return;
        }
        else {
            strategy = new VoidStrategy();
        }
    }

private:
    int x;
    int y;
    Strategy* strategy = new VoidStrategy();
};