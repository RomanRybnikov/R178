#pragma once
#include "ISubscriber.h"
#include "Person.h"

class CoinSub : public ISubscriber {
public:
    void printInfo(std::ostream& out) override {
        out << "Item: Coin" << std::endl;
        out << "Add coin in collection" << std::endl;

    }
};

class TrapSub : public ISubscriber {
public:
    void printInfo(std::ostream& out) override {
        out << "Item: Trap" << std::endl;
        out << "Take the life of the Person" << std::endl;

    }
};

class LifeBufferSub : public ISubscriber {
public:
    void printInfo(std::ostream& out) override {
        out << "Item: LifeBuffe" << std::endl;
        out << "Add life to the Person" << std::endl;

    }
};

class NoneSub : public ISubscriber {
public:
    void printInfo(std::ostream& out) override {
        out << "Item: NONE" << std::endl;
        out << "Person state in a free cell" << std::endl;
    }
};

class PersonSub : public ISubscriber {
public:
    void printInfo(std::ostream& out) override {
        out << "Person in coordinate: x = " << Person::Instance()->getX() << " y = " << Person::Instance()->getY() << std::endl;
        if (AreaHandler::getCellType(Person::Instance()->getX(), Person::Instance()->getY()) == CellType::OBJECT) {
            switch (AreaHandler::getCellItem(Person::Instance()->getX(), Person::Instance()->getY())) {
            case ItemType::COIN:
                out << "Person interacts with COIN" << std::endl;
                break;
            case ItemType::TRAP:
                out << "Person interacts with TRAP" << std::endl;
                break;
            case ItemType::LIFE_BUFFER:
                out << "Person interacts with LIFE_BUFFER" << std::endl;
                break;
            default:
                break;
            }
        }
        out << *Person::Instance();
        out << std::endl;
    }
};


