#include "WinEndMapStrattegy.h"
#include "Player.h"

using namespace Game;

void WinEndMapStrattegy::TellAboutEndCell(Player* player) {
	player->SetState(Game::States::WIN);
}