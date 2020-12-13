#ifndef STARTGAMECOMMAND
#define STARTGAMECOMMAND

#include "Command.h"

class StartGameCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif

