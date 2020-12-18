#pragma once
#include "Cell.h"

namespace Maps {
#define HP_SYMBOL '6'
	class HpCellLogic: public Cell::ILogic
	{
		double m_Health;
	public:
		HpCellLogic(std::istream& is) { is >> m_Health; }
		HpCellLogic(double health);
		virtual void ApplyPlayer(Game::Player* player); // применить логику к игроку
		virtual std::ostream& Output(std::ostream& os); // выводит логику в поток
		void Save(std::ostream& os) { os << HP_CELL_LOGIC_ID << ' ' << m_Health << ' '; }
	};
}

