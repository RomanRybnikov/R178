#ifndef LOGER_H_
#define LOGER_H_
#include <iostream>
#include <fstream>

class Player;
class Loger // логер
{
	static bool m_Truncate; // если истина, то файл логов откроется с удалением всех записей (только первый раз)
	std::ofstream* m_FileStream;
	std::ostream* m_ConsoleStream;
public:

	Loger(bool logFile, bool logColsole);
	~Loger();

	friend Loger& operator<<(Loger& loger, Player& player);
};
#endif
