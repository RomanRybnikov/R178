#include "DeathLogic.h"
#include "Player.h"

Player& DeathLogic::Invoke(Player& player)
{
	player.SetHP(0);
	return player;
}