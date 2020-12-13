#ifndef DIGGRASSCOMMAND_H
#define DIGGRASSCOMMAND_H

#include "Command.h"

class DigGrassCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif