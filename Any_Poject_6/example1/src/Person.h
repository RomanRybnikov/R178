#pragma once
#include "AreaHandler.h"
#include "Strategy.h"

class Person {
public:
    int getCounterCoin();
    int getX();
    int getY();
    static Person* Instance();
    void addCoin();
    void killPersone();
    void operator+ ();
    int getLives();
    void addLive();
    void takeLive();
    void move(int, int);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setX(int x);
    void setY(int y);
    void setCoin(int coin);
    void setLives(int lives);
    friend std::ostream& operator<<(std::ostream& out, const Person person);
    void restart();

private:
    int lives = 5;
    int counterCoin = 0;
    int x = 4;
    int y = 0;
    static Person* _self;
};