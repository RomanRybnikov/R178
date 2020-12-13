#include "Strategy.h"

ClientStrategy::ClientStrategy(Strategy* strategy) : strategy_(strategy) {}

ClientStrategy::~ClientStrategy() {
    delete this->strategy_;
}

void ClientStrategy::set_strategy(Strategy* strategy)
{
    delete this->strategy_;
    this->strategy_ = strategy;
}

void ClientStrategy::choice_strategy(ItemType item)
{
    if (item == ItemType::COIN) {
        set_strategy(new CoinStrategy);
    }
    if (item == ItemType::TRAP) {
        set_strategy(new TrapStrategy);
    }
    if (item == ItemType::LIFE_BUFFER) {
        set_strategy(new LifeBufferStrategy);
    }
    if (item == ItemType::NONE) {
        set_strategy(new VoidStrategy);
    }
}

void ClientStrategy::DoSomeLogic() const
{
    this->strategy_->DoAlgorithm();
}

void CoinStrategy::DoAlgorithm() const{
    AbstractFactory* factory = new CoinFactory();
    auto item = factory->CreateItem();
    item->FunctionAI();
}

void TrapStrategy::DoAlgorithm() const {
    AbstractFactory* factory = new TrapFactory();
    auto item = factory->CreateItem();
    item->FunctionAI();
}

void LifeBufferStrategy::DoAlgorithm() const {
    AbstractFactory* factory = new LifeBufferFactory();
    auto item = factory->CreateItem();
    item->FunctionAI();
}

void VoidStrategy::DoAlgorithm() const {
    
}