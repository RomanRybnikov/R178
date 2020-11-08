#define MAC_OS
#include <iostream>
#include <string>
#ifndef MAC_OS
#include <conio.h>
#endif
#include "Map.h"
#include "Iterator.h"
#include "Player.h"
#include <time.h>
#include "Loger.h"
#include "LogPlayer.h"
#include "Game.h"

using namespace std;
using namespace Maps;
using namespace Game;

void Cycle(Map& map);

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
    Map map = *Map::GetInstance(str, col);
    Cycle(map);
    return 0;
}

void Cycle(Map& map) {
    Game game;
    while(!game.InGame()){
        game.Update();
        switch // ... game.Up()
    }
    char cmd;
    Iterator i(&map);   // итератор позиции игрока
    Player p(&i);       // игрок (игровая ситуация)
    LogPlayer playerLog(&p);
    while (true) {
#ifndef MAC_OS
        system("CLS"); // очистка экрана
#endif
        // вывод текущей ситуации
        cout << p << endl;

        // обработка текущей ситуации
        if (i.Get().GetType() == CellTypes::END)
            p.TellAboutEndCell();
        if (p.GetState() == Game::States::WIN) {
            cout << "WIN!" << endl;
            break;
        }
        else if (p.GetState() == Game::States::DEAD) {
            cout << "YOU DEAD!" << endl;
            break;
        }
#ifndef MAC_OS
        cmd = _getch(); // под винду
#else
        cin >> cmd;     // под MacOS
#endif
        

        switch (cmd) {
        case 'w':
        case 'W':
            i.Up();
            break;
        case 's':
        case 'S':
            i.Down();
            break;
        case 'a':
        case 'A':
            i.Left();
            break;
        case 'd':
        case 'D':
            i.Right();
            break;
        default: cout << "ERROR CMD" << endl;
        }
    }

    cout << "GAME OVER!" << endl;
}
