#ifndef MOVEDOWNCOMMAND
#define MOVEDOWNCOMMAND

#include "Command.h"

class MoveDownCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif