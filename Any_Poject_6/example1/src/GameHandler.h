#pragma once
#include <cstring>
#include <vector>
#include "Display.h"
#include "Person.h"
#include "Publisher.h"
#include "FileLogOut.h"
#include "TemplateEnemy.h"
#include "Memento.h"

class GameHandler {
public:
    void gameInfo();
    ~GameHandler();
    bool movePerson(char);
    bool isCompleteGame();
    bool isWannaRestart();
    void prepareGame();
    void printCurrInfo();
    void printCompleteGame();
    void moveEnemy(int type);
    Memento* Save();
    void Restore(Memento* momento);

private:
    void log();
    void publishPerson();
    bool iswin = false;
    IPublisher* publisher;
    ILogOut* logOut;
    Display* display;
    Person* person;
    char move_but;
    TemplateEnemy<StandEnemy>* enemy1;
    TemplateEnemy<ProtectEnemy>* enemy2;
    TemplateEnemy<WalkEnemy>* enemy3;
    std::string state_;
};