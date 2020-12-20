#pragma once
#include <string>

// команда
class ICommand {
public:
	virtual ~ICommand() {}
	virtual void Execute() = 0; // выполняет команду
	virtual std::string ToString() = 0; // преобразование к строке
};
