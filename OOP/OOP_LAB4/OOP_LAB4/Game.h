#pragma once
#include "Map.h"
#include "Iterator.h"
#include "Player.h"
#include "LogPlayer.h"

namespace Game {
    class Game{
        bool m_InGame; // true => игра запущена
        Maps::Map* m_Map;
        Maps::Iterator* m_Iterator;
        Player* m_Player;
        LogPlayer* m_LogPlayer;
    public:
        Game(int str, int col); // чтобы создать карту
        ~Game();
        void Update(); // обновление игры
        void Up();
        void Down();
        void Left();
        void Right();
        void StartNewGame();
        void EndGame();
    };
}

// переносим из всё из Cycle
