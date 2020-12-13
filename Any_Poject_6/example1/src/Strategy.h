#pragma once
#include "AbstractFactory.h"

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void DoAlgorithm() const = 0;
};

class ClientStrategy
{

private:
    Strategy* strategy_;

public:
    ClientStrategy(Strategy* strategy = nullptr);
    ~ClientStrategy();
    void choice_strategy(ItemType item);
    void set_strategy(Strategy* strategy);
    void DoSomeLogic() const;
};

class CoinStrategy : public Strategy
{
public:
    void DoAlgorithm() const override;
};

class TrapStrategy : public Strategy
{
public:
    void DoAlgorithm() const override;
};

class LifeBufferStrategy : public Strategy
{
public:
    void DoAlgorithm() const override;
};

class VoidStrategy : public Strategy
{
public:
    void DoAlgorithm() const override;
};