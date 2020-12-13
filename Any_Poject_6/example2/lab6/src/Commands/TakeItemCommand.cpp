#include "TakeItemCommand.h"


void TakeItemCommand::execute()
{
	gameManager->getState()->UseItem();
}