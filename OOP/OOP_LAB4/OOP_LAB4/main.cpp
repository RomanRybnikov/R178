//#define MAC_OS
//#define CYCLE // если нужно сделать управление через цикл
#include <iostream>
#include <string>
#include <time.h>
#include "GameController.h"
#include "EnemyBehaviours.h"

#ifndef MAC_OS
#include <conio.h>
#endif

using namespace std;
using namespace Game;

void MakeEnemies(GameController& game) {
    game.AddEnemy(new Enemy<RandomWolker, PlayerKiller>());
    game.AddEnemy(new Enemy<RandomWolker, CoinsTheaf>());
    game.AddEnemy(new Enemy<MoveToPlayer, PlayerKiller>());
    game.AddEnemy(new Enemy<MoveToPlayer, CoinsTheaf>());
}

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

    GameController game(str, col);
    MakeEnemies(game);
    game.StartGameCycle();

    cout << "GAME OVER!" << endl;
    _getch();
    return 0;
}
