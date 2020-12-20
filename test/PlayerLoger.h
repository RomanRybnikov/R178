#ifndef _PLAYER_LOGER_
#define _PLAYER_LOGER_
#include "FieldIterator.h"
#include "Player.h"

class PlayerLoger: public FieldIterator::IObserver
{
	Player* m_Player;
public:
	PlayerLoger(Player* player);
	~PlayerLoger();

	virtual void OnMove(FieldIterator* iterator);
};

#endif

