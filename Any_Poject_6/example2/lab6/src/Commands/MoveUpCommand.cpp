#include "MoveUpCommand.h"

void MoveUpCommand::execute()
{
	gameManager->getState()->Move(0, -1);
}