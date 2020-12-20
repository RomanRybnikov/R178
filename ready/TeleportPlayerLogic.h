#pragma once
#include "IPlayerLogic.h"
#include <iostream>

class TeleportPlayerLogic : public IPlayerLogic
{
public:
	virtual Player& Invoke(Player& player);
	virtual std::ostream& Print(std::ostream& os);
	virtual void Save(std::ostream& os) { os << IPlayerLogic::TELEPORT_LOGIC_ID << ' '; }
};

