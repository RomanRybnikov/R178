#include "AddCoinsCellLogic.h"
#include "Player.h"

using namespace Maps;

AddCoinsCellLogic::AddCoinsCellLogic(int coins) {
	m_CointToAdd = coins;
}

void AddCoinsCellLogic::ApplyPlayer(Game::Player* player) // применить логику к игроку
{
	player->SetCoins(player->GetCoins() + m_CointToAdd);
	player->GetIterator().Get().SetLogic(0); // убираем логику из ячейки, где стоит игрок
}
std::ostream& AddCoinsCellLogic::Output(std::ostream& os) // выводит логику в поток
{
	return os << 'C';
}
