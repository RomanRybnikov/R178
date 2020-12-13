#include "Person.h"

int Person::getCounterCoin() {
    return this->counterCoin;
}

int Person::getX() {
    return this->x;
}

int Person::getY() {
    return this->y;
}

void Person::operator+() {
    ClientStrategy* client = new ClientStrategy();
    CellType type = AreaHandler::getCellType(this->x, this->y);
    if (type == CellType::OBJECT) {
        ItemType item = AreaHandler::getCellItem(this->x, this->y);
        client->choice_strategy(item);
        client->DoSomeLogic();
    }
}

void Person::restart()
{
    this->lives = 1;
    this->counterCoin = 0;
    this->x = 4;
    this->y = 0;
}

void Person::addCoin() {
    this->counterCoin++;
}

void Person::killPersone() {
    this->lives = 0;
}

Person* Person::Instance() {
    if (!_self) {
        _self = new Person();
    }
    return _self;
}

Person* Person::_self = nullptr;

int Person::getLives() {
    return this->lives;
}

void Person::addLive() {
    this->lives++;
}

void Person::takeLive() {
    this->lives--;
}

void Person::setX(int x) {
    this->x = x;
}

void Person::setY(int y) {
    this->y = y;
}

void Person::setCoin(int coin)
{
    this->counterCoin = coin;
}

void Person::setLives(int lives)
{
    this->lives = lives;
}

std::ostream& operator<<(std::ostream& out, Person person) {
    if (person.lives > 0) {
        out << "Person alive and have " << person.lives << " lives" << std::endl;
    }
    else{
        out << "Person dead" << std::endl;
    }
    return out;
}

void Person::move(int x, int y) {
    if (AreaHandler::getCellType(getX() + x, getY() + y) != CellType::ENTRY && AreaHandler::getCellType(getX() + x, getY() + y) != CellType::WALL) {
        if (AreaHandler::getCellType(getX() + x, getY() + y) == CellType::EXIT && getCounterCoin() < 3) {
            std::cout << "You don`t take 3 coins" << std::endl;
            return;
        }
        if (AreaHandler::getCellType(getX() + x, getY() + y) == CellType::EXIT && getCounterCoin() == 3) {
            setY(getY() + 1);
            return;
        }
        if (AreaHandler::getCellType(getX(), getY()) != CellType::ENTRY) {
            AreaHandler::clearCell(getX(), getY());
        }
        setX(getX() + x);
        setY(getY() + y);
        if (AreaHandler::getCellType(getX(), getY()) == CellType::OBJECT && AreaHandler::getCellItem(getX(), getY()) != ItemType::NONE) {
            +*_self;
            AreaHandler::clearCell(getX(), getY());
            AreaHandler::addPersone(getX(), getY());
        }
        AreaHandler::addPersone(getX(), getY());
    }
}


void Person::moveUp() {
    if (getY() != 0) {
        this->move(0, -1);
    }
}

void Person::moveDown() {
    if (getY() != AreaHandler::getHeight() - 1) {
        this->move(0, 1);
    }
}


void Person::moveLeft() {
    if (getX() != 0) {
        this->move(-1, 0);
    }
}


void Person::moveRight() {
    if (getX() < AreaHandler::getWidth() - 1) {
        this->move(1, 0);
    }
}