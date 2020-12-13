#ifndef TAKEITEMCOMMAND
#define TAKEITEMCOMMAND

#include "Command.h"

class TakeItemCommand:public Command
{
public:
	using Command::Command;
	void execute();
};

#endif

