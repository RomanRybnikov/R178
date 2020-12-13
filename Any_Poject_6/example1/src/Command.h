#pragma once
#include "GameHandler.h"
#include "snapshot.h"

class ICommand {
public:
    virtual ~ICommand() {};
    virtual bool execute(char ch='\0') = 0;

};

class StartCommand : public ICommand {
public:
    explicit StartCommand(GameHandler* game) : game(game) {};
    bool execute(char) override
    {
        game->prepareGame();
        return true;
    }

private:
    GameHandler* game;
};

class EndCommand : public ICommand
{
public:
    explicit EndCommand(GameHandler* game) : game(game) {};
    bool execute(char) override
    {
        game->printCompleteGame();
        return true;
    }
private:
    GameHandler* game;
};

class MoveCommand : public ICommand {
public:
    explicit MoveCommand(GameHandler* game) : game(game) {};
    bool execute(char move) override 
    {
        return game->movePerson(move);
    }
private:
    GameHandler* game;
};

class snapGameCommand : public ICommand
{
public:
    explicit snapGameCommand(GameHandler* game) : game(game) 
    {
        this->caretaker = new Caretaker(game);
    };
    bool execute(char) override
    {
        std::cout << "Do you want save the game? y/n" << std::endl;
        char ch;
        std::cin >> ch;
        if (ch == 'y')
        {
            caretaker->Backup();
        }
        std::cout << "Do you want restore the game? y/n" << std::endl;
        std::cin >> ch;
        if (ch == 'y')
        {
            return caretaker->Undo();
        }
        return true;
    }

private:
    Caretaker* caretaker;
    GameHandler* game;
};

class IsCompleteCommand : public ICommand 
{
public:
    explicit IsCompleteCommand(GameHandler* game) : game(game) {};
    bool execute(char) override 
    {
        return game->isCompleteGame();
    }
private:
    GameHandler* game;
};

class restartCommand : public ICommand 
{
public:
    explicit restartCommand(GameHandler* game) : game(game) {};
    bool execute(char) override 
    {
        return !game->isWannaRestart();
    }
private:
    GameHandler* game;
};

