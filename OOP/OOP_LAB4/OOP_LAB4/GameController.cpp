//#define MAC_OS
#include "GameController.h"
#include <iostream>
#include "Saver.h"
#include "Loader.h"
#ifndef MAC_OS
#include <conio.h>
#endif

#define SAVE_FILE_NAME "save.txt"
#define FILE_SIGNATURE 123

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
        (*i)->Initialize(m_Map, m_Player, m_Iterator, true); // инициализируем врага
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
            try {
                Load();
            }
            catch (const char* msg) {
                std::cout << "ERROR: " << msg << std::endl;
#ifndef MAC_OS
                cmd = _getch(); // под винду
#else
                cin >> cmd;     // под MacOS
#endif  
            }
            catch (...) {
                std::cout << "UNKNOWN ERROR" << std::endl;
#ifndef MAC_OS
                cmd = _getch(); // под винду
#else
                cin >> cmd;     // под MacOS
#endif  
            }
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
    enemy->Initialize(m_Map, m_Player, m_Iterator, true);
    m_Enemies.push_back(enemy);
}

void GameController::Save() {
    Saver saver(SAVE_FILE_NAME);
    auto& stream = saver.Stream();
    // пишем сигнатуру
    stream << FILE_SIGNATURE << std::endl;
    // сохраняем игру
    stream << m_InGame << std::endl;
    // сохраняем игрока
    m_Player->Save(stream);
    // размер карты в настройках игры
    stream << m_Str << ' ' << m_Col << std::endl;
    // карта
    m_Map->Save(stream);
    // сохраняем врагов
    stream << m_Enemies.size() << std::endl;
    for (auto i = m_Enemies.begin(); i != m_Enemies.end(); ++i) 
        (*i)->Save(stream);    
}

void GameController::Load()
{
    Loader loader(SAVE_FILE_NAME);
    // сигнатура
    auto& stream = loader.Stream();
    int signature;
    stream >> signature;
    if (signature != FILE_SIGNATURE) throw "bad signature - file format is incorrect";
    // игра
    stream >> m_InGame;
    // игрок
    m_Player->Load(stream);
    // настройки размера
    stream >> m_Str >> m_Col;
    // карта
    m_Map->Load(stream);
    // враги
    for (auto i = m_Enemies.begin(); i != m_Enemies.end(); ++i)
        delete* i;
    m_Enemies.clear();
    int enemyCount;
    stream >> enemyCount;
    for (int i = 0; i < enemyCount; ++i) {
        auto enemy = Game::IEnemy::Load(stream);
        enemy->Initialize(m_Map, m_Player, m_Iterator, false);
        m_Enemies.push_back(enemy);
    }
}

