#pragma once

namespace Game {
#define FailWinEndMapStrattegy_ID 1;
#define WinEndMapStrattegy_ID 2;
	class Player;
	class EndMapStrattegy {	// страттегия нажатия на ячейку конца
	public:
		virtual int Id() = 0;
		virtual void TellAboutEndCell(Player* player) = 0;	// сказать игроку, что он стоит вконце поля
	};
}