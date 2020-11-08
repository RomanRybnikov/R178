#pragma once
#include "EndMapStrattegy.h"

namespace Game {
	class WinEndMapStrattegy :public EndMapStrattegy // скажет игроку что он выиграл
	{
	public:
		virtual void TellAboutEndCell(Player* player);
	};
}