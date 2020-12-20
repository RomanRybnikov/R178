#include "Loger.h"
#include "Player.h"

bool Loger::m_Truncate = true; // изначально стереть весь лог

Loger::Loger(bool logFile, bool logColsole) {
	if (logFile) {
		if (m_Truncate) m_FileStream = new std::ofstream("Log.txt", std::ios_base::trunc); // открываем для перезаписи
		else m_FileStream = new std::ofstream("Log.txt", std::ios_base::app); // открываем для записи вконец
		m_Truncate = false; // далее лог дополняем
	}
	else m_FileStream = 0;
	if (logColsole) m_ConsoleStream = &std::cout;
	else m_ConsoleStream = 0;
}
Loger::~Loger() {
	m_FileStream->close(); // закрываем файл логов (идиома RAII)
}

Loger& operator<<(Loger& loger, Player& player) // оператор вывода игрока
{
	if (loger.m_FileStream) *loger.m_FileStream << player <<"========"<< std::endl;
	if (loger.m_ConsoleStream) *loger.m_ConsoleStream << player <<"========="<< std::endl;
	return loger;
}