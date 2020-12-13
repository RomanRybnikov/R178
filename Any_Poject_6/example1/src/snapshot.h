#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Memento.h"
#include "GameHandler.h"

class Caretaker {
private:
    std::vector<Memento*> mementos_;
    GameHandler* game_;

public:
    Caretaker(GameHandler* game) : game_(game) {
        this->game_ = game;
    }

    void Backup() {
        this->mementos_.push_back(this->game_->Save());
    }
    bool Undo() {
        if (!this->mementos_.size()) {
            std::ifstream fin("save.txt");
            if (!fin.is_open())
            {
                std::cout << "Save in data and file save.txt not found";
                return false;
            }
            std::string total;
            std::string s;
            while (getline(fin, s)) {
                total.append(s);
            }
            fin.close();

            Memento* memento = new GameMemento(total);
            this->game_->Restore(memento);
            return true;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        try {
            this->game_->Restore(memento);
        }
        catch (...) {
            std::cout << "Restoring is failed" << std::endl;
            return false;
        }
    }
};