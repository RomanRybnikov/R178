#pragma once
#include "AreaHandler.h"
#include "Strategy.h"

class StandEnemy
{
public:
    StandEnemy(int _x, int _y) : x(_x), y(_y) {}

    void moveEnemy() {
        strategy = new VoidStrategy();
    }

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

private:
    int x;
    int y;
    Strategy* strategy = new VoidStrategy();
};