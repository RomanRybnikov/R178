#pragma once
#include "Cell.h"

namespace Maps {
#define KILL_CHAR '*'
	class KillCellLogic : public Cell::ILogic
	{
	public:
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
	};
}

