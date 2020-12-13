#include "MoveRightCommand.h"

void MoveRightCommand::execute()
{
	gameManager->getState()->Move(1, 0);
}