#pragma once
#include "Cell.h"

namespace Maps {
#define HP_SYMBOL '6'
	class HpCellLogic: public Cell::ILogic
	{
		double m_Health;
	public:
		HpCellLogic(double health);
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
	};
}

