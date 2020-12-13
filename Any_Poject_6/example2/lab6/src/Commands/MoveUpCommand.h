#ifndef MOVEUPCOMMAND
#define MOVEUPCOMMAND

#include "Command.h"

class MoveUpCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif

