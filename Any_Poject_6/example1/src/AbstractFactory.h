#pragma once
#include "Person.h"

class AbstractItem {
public:
    virtual ~AbstractItem() {};
    virtual void FunctionAI() const = 0;
};


class Coin : public AbstractItem {
public:
    void FunctionAI() const override;
};

class Trap : public AbstractItem {
public:
    void FunctionAI() const override;
};

class LifeBuffer : public AbstractItem {
public:
    void FunctionAI() const override;
};


class AbstractFactory {
public:
    virtual AbstractItem * CreateItem() const = 0;
};


class CoinFactory : public AbstractFactory {
public:
    AbstractItem* CreateItem() const override;
};

class TrapFactory : public AbstractFactory {
public:
    AbstractItem* CreateItem() const override;
};

class LifeBufferFactory : public AbstractFactory {
public:
    AbstractItem* CreateItem() const override;
};