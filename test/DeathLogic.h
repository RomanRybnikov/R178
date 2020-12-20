#pragma once
#include "IPlayerLogic.h"

class DeathLogic: public IPlayerLogic
{
public:
	virtual Player& Invoke(Player& player);
	virtual std::ostream& Print(std::ostream& os) { return os << 'D'; }
	virtual void Save(std::ostream& os) {
		os << IPlayerLogic::DEATH_LOGIC_ID << ' ';
	}
};

