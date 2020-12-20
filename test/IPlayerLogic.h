#pragma once
#include <iostream>

class Player;


class IPlayerLogic { // интерфейс взаимодействия с игроком
public: 
	static const int DEATH_LOGIC_ID = 1;
	static const int ADD_SCORES_LOGIC_ID = 2;
	static const int TELEPORT_LOGIC_ID = 3;

	virtual Player& Invoke(Player& player) = 0;			// взаимодействие с игроком
	virtual std::ostream& Print(std::ostream& os) = 0;	// вывод логики в поток
	virtual void Save(std::ostream& os) = 0;
};
