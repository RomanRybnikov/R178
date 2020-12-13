#pragma once
#include <string>
#include <ctime>

class Memento {
public:
    virtual std::string state() const = 0;
};

class GameMemento : public Memento {
private:
    std::string state_;

public:
    GameMemento(std::string state) : state_(state) {
        this->state_ = state;
    }

    std::string state() const override {
        return this->state_;
    }
};