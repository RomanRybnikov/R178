#pragma once
#include "Map.h"
#include "Iterator.h"
#include "Player.h"
#include "LogPlayer.h"

namespace Game {
    class GameController{ // этот контроллер и есть фасад для игры (тк он объединяет в себе и дает упрощенный интерфейс работы с множеством подсистем игры)
        bool m_InGame; // true => игра запущена
        Maps::Map* m_Map;
        Maps::Iterator* m_Iterator;
        Player* m_Player;
        LogPlayer* m_LogPlayer;
        int m_Str;
        int m_Col;
    public:
        GameController(int str, int col); // чтобы создать карту
        ~GameController();
        bool Update(); // обновление игры
        void Up();
        void Down();
        void Left();
        void Right();
        void StartNewGame();
        void EndGame();
#ifndef CYCLE
        void StartGameCycle();
#endif
    };
}
