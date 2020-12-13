//#define MAC_OS
#include "GameController.h"
#include <iostream>
#include "Saver.h"
#include "Loader.h"
#ifndef MAC_OS
#include <conio.h>
#endif

#define SAVE_FILE_NAME "save.txt"

using namespace std;
using namespace Game;
using namespace Maps;

GameController::GameController(int str, int col) {
    m_Str = str;
    m_Col = col;
    StartNewGame();
}

GameController::~GameController() {}

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

    // вывод ситуации
    Print(std::cout);

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
        case 'k':
            Save();
            break;
        case 'l':
            Load();
            break;
        default: cout << "ERROR CMD" << endl;
        }
    }
}
#endif

std::ostream& GameController::Print(std::ostream& os) {
    // вывод текущих данных
    os << "HEALTH:\t" << m_Player->GetHealth() << std::endl;
    os << "COINS:\t" << m_Player->GetCoins() << std::endl;
    // вывод поля
    for (int i = 0; i < m_Map->GetWidth(); i++) {
        for (int j = 0; j < m_Map->GetHeight(); j++) {
            // вывод игрока
            auto playerPos = m_Iterator->GetMapPos();
            if (i == playerPos.GetRow() && j == playerPos.GetCol()) {
                os << ITERATOR_CHAR;
                os << " ";
                continue;
            }
            // вывод врагов
            bool cont = false;
            for (auto iter = m_Enemies.begin(); iter != m_Enemies.end(); ++iter) {
                auto pos = (*iter)->GetPosition();              
                if (i == pos.GetRow() && j == pos.GetCol()) {
                    (*iter)->Print(os);
                    os << " ";
                    cont = true;
                    continue;
                }
            }    
            if (cont) continue;
            // вывод ячейки
            os << m_Map->GetCell(i, j);            
            os << " ";
        }
        os << std::endl;
    }

    return os;
}
    
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

void GameController::Save() {
    Saver saver(SAVE_FILE_NAME);
    auto& stream = saver.Stream();
    // пишем сигнатуру
    stream << 123 << std::endl;
    // сохраняем игру
    stream << m_InGame << std::endl;
    // сохраняем игрока
    m_Player->Save(stream);
    // размер карты
    stream << m_Str << ' ' << m_Col << std::endl;
    // карта
    for (int i = 0; i < m_Map->GetHeight(); ++i) {
        for (int j = 0; j < m_Map->GetWidth(); ++j) {
            auto cell = m_Map->GetCell(i, j);
            stream << cell.GetType() << ' ';
            Cell::SaveLogic(cell, stream);
        }
        stream << std::endl;
    }
    // сохраняем врагов
    stream << m_Enemies.size() << std::endl;
    for (auto i = m_Enemies.begin(); i != m_Enemies.end(); ++i) 
        (*i)->Save(stream);    
}

void GameController::Load()
{
    Loader loader(SAVE_FILE_NAME);
    loader.Stream() >> m_InGame;
}

