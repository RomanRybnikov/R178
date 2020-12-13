#ifndef CLOSEGAMECOMMAND_H
#define CLOSEGAMECOMMAND_H

#include "Command.h"

class CloseGameCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif