#include "GameController.h"
#include <iostream>

#ifndef MAC_OS
#include <conio.h>
#endif

using namespace std;
using namespace Game;
using namespace Maps;

GameController::GameController(int str, int col) {
    m_Str = str;
    m_Col = col;
    StartNewGame();
}

GameController::~GameController() {

}

void GameController::StartNewGame() {
    m_Map = Map::GetInstance(m_Str, m_Str);
    m_Iterator = new Iterator(m_Map);   // итератор позиции игрока
    m_Player = new Player(m_Iterator);       // игрок (игровая ситуация)
    m_LogPlayer = new LogPlayer(m_Player);
    m_InGame = true;
    // инициализируем всех врагов
    for (auto i = m_Enemies.begin(); i != m_Enemies.end(); ++i) // по всем врагам из списка
        (*i)->Initialize(m_Map, m_Player, m_Iterator); // инициализируем врага
}

void GameController::EndGame() {
    m_InGame = false;
}

bool GameController::Update() {
    if (!m_InGame) return false;

    // обработка врагов
    for (auto i = m_Enemies.begin(); i != m_Enemies.end(); ++i) 
        (*i)->Update();

    // вывод текущей ситуации
#ifndef MAC_OS
    system("CLS"); // очистка экрана
#endif
    cout << *m_Player << endl;

    // обработка текущей ситуации
    if (m_Iterator->Get().GetType() == Maps::CellTypes::END)
        m_Player->TellAboutEndCell();
    if (m_Player->GetState() == States::WIN) {
        cout << "WIN!" << endl;
        return false;
    }
    else if (m_Player->GetState() == States::DEAD) {
        cout << "YOU DEAD!" << endl;
        return false;
    }

    return true;
}

#ifndef CYCLE // на былор тк тут присутствует пользовательский интерфейс, что не желательно
void GameController::StartGameCycle() {
    char cmd;
    while (Update()) {
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
            Up();
            break;
        case 's':
        case 'S':
            Down();
            break;
        case 'a':
        case 'A':
            Left();
            break;
        case 'd':
        case 'D':
            Right();
            break;
        case '-':
            EndGame();
            break;
        case '=':
            StartNewGame();
            break;
        default: cout << "ERROR CMD" << endl;
        }
    }
}
#endif
    
void GameController::Up() {
    if (!m_InGame) return;
    m_Iterator->Up();
}
    
void GameController::Down() {
    if (!m_InGame) return;
    m_Iterator->Down();
}
    
void GameController::Left() {
    if (!m_InGame) return;
    m_Iterator->Left();
}
    
void GameController::Right() {
    if (!m_InGame) return;
    m_Iterator->Right();
}

void GameController::AddEnemy(IEnemy* enemy) {
    enemy->Initialize(m_Map, m_Player, m_Iterator);
    m_Enemies.push_back(enemy);
}

