#pragma once
#include "AreaHandler.h"
#include "Strategy.h"
#include "StandEnemy.h"
#include "ProtectorEnemy.h"
#include "WalkEnemy.h"

template<typename T>
class TemplateEnemy {
public:
    TemplateEnemy(T* enemy): _self(enemy) {}
    void moveEnemy() {
        this->_self->moveEnemy();
    }

    void operator+ () {
        auto* client = new ClientStrategy();
        client->set_strategy(_self->getStrategy());
        client->DoSomeLogic();
        AreaHandler::addEnemy(_self->getX(), _self->getY());
        delete client;
    }

    int getX()
    {
        return _self->getX();
    }

    int getY()
    {
        return _self->getY();
    }

    void setX(int x)
    {
        this->_self->setX(x);
    }

    void setY(int y)
    {
        this->_self->setY(y);
    }

private:
    T* _self;
};