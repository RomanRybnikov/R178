#ifndef MOVERIGHTCOMMAND
#define MOVERIGHTCOMMAND

#include "Command.h"

class MoveRightCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif
