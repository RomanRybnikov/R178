#include "MoveDownCommand.h"

void MoveDownCommand::execute()
{
	gameManager->getState()->Move(0, 1);
}