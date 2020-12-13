#include "MoveLeftCommand.h"

void MoveLeftCommand::execute()
{
	gameManager->getState()->Move(-1, 0);
}