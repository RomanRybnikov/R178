#pragma once
#include "IPlayerLogic.h"

class AddScoresPlayerLogic : public IPlayerLogic // добавляет очки игроку
{
	int m_Scores;

public:
	AddScoresPlayerLogic(int scores);
	AddScoresPlayerLogic(std::istream& is) {
		is >> m_Scores;
	}
	virtual Player& Invoke(Player& player);
	virtual std::ostream& Print(std::ostream& os) { return os << '$'; }
	virtual void Save(std::ostream& os) {
		os << IPlayerLogic::ADD_SCORES_LOGIC_ID << ' ' << m_Scores << ' ';
	}
};

