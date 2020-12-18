#pragma once
#include "Cell.h"

namespace Maps {
#define KILL_CHAR '*'
	class KillCellLogic : public Cell::ILogic
	{
	public:
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
		virtual void Save(std::ostream& os) { os << KILL_CELL_LOGIC_ID << ' '; }
	};
}

