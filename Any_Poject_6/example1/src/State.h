#pragma once
#include "GameHandler.h"

class Context;

class State {
protected:
    Context* context_;

public:
    void set_context(Context* context) {
        this->context_ = context;
    }

    virtual void move(GameHandler*) = 0;
};

class Context {
private:
    State* state_;
    GameHandler* game;

public:
    Context(GameHandler* game) {
        this->game = game;
    }
    ~Context() {
        delete state_;
    }

    void TransitionTo(State* state) {
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
        request();
    }

    void request() {
        this->state_->move(game);
    }

};

class EnemyStraight : public State {
public:
    void move(GameHandler* game) override;
};

class EnemyProtect : public State {
public:
    void move(GameHandler* game) override {
        game->moveEnemy(2);
        context_->TransitionTo(new EnemyStraight());
    }
};

class EnemyStand : public State {
public:
    void move(GameHandler* game) override {
        game->moveEnemy(1);
        context_->TransitionTo(new EnemyProtect());
    }
};


class PlayerStand : public State {
public:
    void move(GameHandler* game) override {
        char move;
        std::cin >> move;
        game->movePerson(move);
        context_->TransitionTo(new EnemyStand());
    }
};

void EnemyStraight::move(GameHandler* game) {
    game->moveEnemy(3);
}

