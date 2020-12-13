#pragma once
#include "Launcher.h"
#include "Command.h"
#include "State.h"
#include "snapshot.h"

class GameClient {
public:
    void startGame() {
        auto* game = new GameHandler();
        auto* launcher = new GameLauncher();
        auto* context = new Context(game);
        bool checker = false;
        launcher->setCompletedCommand(new IsCompleteCommand(game));
        launcher->setMoveCommand(new MoveCommand(game));
        launcher->setSnapGameCommand(new snapGameCommand(game));
        while (!checker) 
        {
            launcher->setGameCommand(new StartCommand(game));
            launcher->doGameCommand();
            while (!launcher->isGameCompleted())
            {
                game->printCurrInfo();
                context->TransitionTo(new PlayerStand());
                launcher->doSaveCommand();
            }
            launcher->setGameCommand(new EndCommand(game));
            launcher->doGameCommand();
            launcher->setGameCommand(new restartCommand(game));
            checker = launcher->doGameCommand();
        }
        delete launcher;
        delete game;
    }

};

