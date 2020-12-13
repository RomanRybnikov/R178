#ifndef MOVELEFTCOMMAND
#define MOVELEFTCOMMAND

#include "Command.h"

class MoveLeftCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif