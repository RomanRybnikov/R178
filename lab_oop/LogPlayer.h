#ifndef PlayerLog_h
#define PlayerLog_h
#include <iostream>
#include "Loger.h"
#include "Player.h"
#include <time.h>

namespace Game {
    // следит за игроком, через его итератор (является наблюдателем за итератором) и выводит его в лог, если игрок сместился
    class LogPlayer: public Maps::Iterator::Listener {
        Player* m_Player;

    public:
        LogPlayer(Player* player);
        virtual ~LogPlayer();

        void OnMove(Maps::Iterator* iterator); // унаследовано от наблюдателя за итератором
    };
}
#endif /* PlayerLog_h */
