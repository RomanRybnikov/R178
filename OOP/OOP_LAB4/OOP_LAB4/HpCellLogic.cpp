#include "HpCellLogic.h"
#include "Player.h"
#include "KillCellLogic.h"

using namespace Maps;

HpCellLogic::HpCellLogic(double health)
{
	m_Health = health;
}
void HpCellLogic::ApplyPlayer(Game::Player* player) // применить логику к игроку
{
	player->SetHealth(player->GetHealth() + m_Health);
	player->GetIterator().Get().SetLogic(new KillCellLogic()); 
}
std::ostream& HpCellLogic::Output(std::ostream& os) // выводит логику в поток
{
	return os << (char)HP_SYMBOL;
}