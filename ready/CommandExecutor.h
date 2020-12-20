#pragma once
#include <list>
#include <iostream>
#include "ICommand.h"

// выполняет команды
class CommandExecutor
{
	std::list<ICommand*> m_History;
public:
	void Execute(ICommand* command); // выполняет команду

	friend std::ostream& operator<<(std::ostream& os, CommandExecutor& ce);
};

