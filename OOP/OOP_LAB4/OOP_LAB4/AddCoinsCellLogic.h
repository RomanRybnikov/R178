#pragma once
#include "Cell.h"

namespace Maps {
	class AddCoinsCellLogic: public Cell::ILogic
	{
		int m_CointToAdd;
	public:

		AddCoinsCellLogic(int coins);
		AddCoinsCellLogic(std::istream& is) {
			is >> m_CointToAdd;
		}
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
		virtual void Save(std::ostream& os) {
			os << ADD_COINS_CELL_LOGIC_ID << ' ' << m_CointToAdd << ' ';
		}
	};
}

