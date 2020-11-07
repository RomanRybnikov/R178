#include "KillCellLogic.h"
#include "Player.h"

using namespace Maps;

void KillCellLogic::ApplyPlayer(Game::Player* player) // применить логику к игроку
{
	player->SetHealth(0);
}
std::ostream& KillCellLogic::Output(std::ostream& os) // выводит логику в поток
{
	return os << (char)KILL_CHAR;
}