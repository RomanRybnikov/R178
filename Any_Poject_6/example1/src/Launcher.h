#pragma once

#include "Command.h"


class GameLauncher {
public:

    ~GameLauncher() {
        delete gameCommand;
        delete moveCommand;
        delete isCompleted;
    }

    void setMoveCommand(ICommand* command) {
        this->moveCommand = command;
    }

    void setGameCommand(ICommand* command) {
        this->gameCommand = command;
    }

    void setCompletedCommand(ICommand* command) {
        this->isCompleted = command;
    }

    void setSnapGameCommand(ICommand* command) {
        this->snapCommand = command;
    }

    bool move(char move) {
        return this->moveCommand->execute(move);
    }

    bool doGameCommand() {
        return this->gameCommand->execute();
    }

    bool isGameCompleted() {
        return this->isCompleted->execute();
    }

    bool doSaveCommand() {
        return this->snapCommand->execute();
    }


private:
    ICommand* moveCommand;
    ICommand* gameCommand;
    ICommand* isCompleted;
    ICommand* snapCommand;
};
