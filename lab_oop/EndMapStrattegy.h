#pragma once

namespace Game {
	class Player;
	class EndMapStrattegy {	// страттегия нажатия на ячейку конца
	public:
		virtual void TellAboutEndCell(Player* player) = 0;	// сказать игроку, что он стоит вконце поля
	};
}