#pragma once
#include "Cell.h"

namespace Maps {
	class AddCoinsCellLogic: public Cell::ILogic
	{
		int m_CointToAdd;
	public:

		AddCoinsCellLogic(int coins);
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
	};
}

