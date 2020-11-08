#pragma once
#include "EndMapStrattegy.h"

namespace Game {
	class FailWinEndMapStrattegy :public EndMapStrattegy // скажет игроку что нужно насобирать еще очков
	{
	public:
		virtual void TellAboutEndCell(Player* player);
	};
}