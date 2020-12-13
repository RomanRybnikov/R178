#include "DigGrassCommand.h"

void DigGrassCommand::execute()
{
	gameManager->getState()->DigGrass();
}