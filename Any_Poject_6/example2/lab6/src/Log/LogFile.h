#ifndef LOGFILE_H
#define LOGFILE_H
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "time.h"
#include <chrono>

class LogFile
{
private:
	std::ofstream* file = nullptr;
	static int logCounter;
public:
	LogFile();
	~LogFile();
	void PrintLog(std::string log);
	
};

#endif