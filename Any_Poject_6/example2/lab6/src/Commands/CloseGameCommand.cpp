#include "CloseGameCommand.h"

void CloseGameCommand::execute()
{
	gameManager->EndGame();
}