#include "CommandExecutor.h"

void CommandExecutor::Execute(ICommand* command) {
	if (command == 0) return;
	command->Execute();
	m_History.push_back(command);
}

std::ostream& operator<<(std::ostream& os, CommandExecutor& ce)
{
	if (ce.m_History.size() == 0) return os << "EMPTY!";
	for (auto i = ce.m_History.begin(); i != ce.m_History.end(); ++i)
		os << (*i)->ToString() << "; ";
	return os;
}
