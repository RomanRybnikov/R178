#include "LogPlayer.h"

using namespace Game;

LogPlayer::LogPlayer(Player* player) {
    this->m_Player = player;
    m_Player->GetIterator().AddListener(this);
}
LogPlayer::~LogPlayer()
{
    m_Player->GetIterator().RemoveListener(this);
}

void LogPlayer::OnMove(Maps::Iterator* iterator) {
    Loger loger;
    loger.Stream() << *m_Player << std::endl;
    loger.Stream() << "----------------------" << std::endl;
}
