#include "PlayerLoger.h"
#include "Loger.h"

PlayerLoger::PlayerLoger(Player* player)
{
	m_Player = player;
	m_Player->GetIterator().AddListener(this);
}

PlayerLoger::~PlayerLoger() {
	m_Player->GetIterator().RemoveListener(this);
}

void PlayerLoger::OnMove(FieldIterator* iterator) {
	Loger loger(true, true);
	loger << *m_Player;
}