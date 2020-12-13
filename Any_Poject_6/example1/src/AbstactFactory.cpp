#include "AbstractFactory.h"

void Coin::FunctionAI() const {
    Person::Instance()->addCoin(); 
};

void Trap::FunctionAI() const {
    Person::Instance()->takeLive();
    if (Person::Instance()->getLives() <= 0) {
        Person::Instance()->killPersone();
    }
};

void LifeBuffer::FunctionAI() const { 
    Person::Instance()->addLive();
    Person::Instance()->addLive();
    Person::Instance()->addLive();
};


AbstractItem* CoinFactory::CreateItem() const {
    return new Coin();
}

AbstractItem* TrapFactory::CreateItem() const {
    return new Trap();
}

AbstractItem* LifeBufferFactory::CreateItem() const {
    return new LifeBuffer();
}
