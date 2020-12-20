#include "TeleportPlayerLogic.h"
#include "Player.h"

Player& TeleportPlayerLogic::Invoke(Player& player){
	while(player.GetIterator().Up());
	while (player.GetIterator().Left());
	return player;
}

std::ostream& TeleportPlayerLogic::Print(std::ostream& os)
{
	return os << 'T';
}
