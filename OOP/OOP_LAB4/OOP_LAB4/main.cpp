//#define MAC_OS
//#define CYCLE // если нужно сделать управление через цикл
#include <iostream>
#include <string>
#include <time.h>
#include "GameController.h"
#ifndef MAC_OS
#include <conio.h>
#endif

using namespace std;
using namespace Game;

#ifdef CYCLE
void Cycle(GameController* game) {
    char cmd;
    while (game->Update()) {
        // ввод команды
#ifndef MAC_OS
        cmd = _getch(); // под винду
#else
        cin >> cmd;     // под MacOS
#endif       
        // обработка команды
        switch (cmd) {
        case 'w':
        case 'W':
            game->Up();
            break;
        case 's':
        case 'S':
            game->Down();
            break;
        case 'a':
        case 'A':
            game->Left();
            break;
        case 'd':
        case 'D':
            game->Right();
            break;
        case '-':
            game->EndGame();
            break;
        case '=':
            game->StartNewGame();
            break;
        default: cout << "ERROR CMD" << endl;
        }
    }
}
#endif

int main() {
    srand(time(0));
    
    int str, col;
    cout << "Enter str: " << endl;
    cin >> str;
    while (str <= 0) {
        std::cout << "Invalid str" << endl;
        std::cin >> str;
    }
    cout << "Enter col: " << endl;
    cin >> col;
    while (col <= 0) {
        cout << "Invalid col" << endl;
        cin >> col;
    }

    cout << endl;
#ifndef CYCLE
    GameController game(str, col);
    game.StartGameCycle();
#else
    GameController *game =new GameController(str, col);
    Cycle(game);
    delete game;
#endif
    cout << "GAME OVER!" << endl;
    _getch();
    return 0;
}
