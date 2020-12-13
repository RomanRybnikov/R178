#pragma once
#include "EndMapStrattegy.h"

namespace Game {
	class WinEndMapStrattegy :public EndMapStrattegy // скажет игроку что он выиграл
	{
	public:
		virtual int Id() {
			return WinEndMapStrattegy_ID;
		}
		virtual void TellAboutEndCell(Player* player);
	};
}