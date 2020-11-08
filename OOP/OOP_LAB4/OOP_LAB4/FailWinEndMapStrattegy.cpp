#include "FailWinEndMapStrattegy.h"
#include <iostream>
#include "Player.h"
using namespace Game;

void FailWinEndMapStrattegy::TellAboutEndCell(Player* player) {
	std::cout << "CAN NOT END!" << std::endl;
	system("PAUSE");
}
