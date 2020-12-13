#include "LogFile.h"

int LogFile::logCounter = 0;
LogFile::LogFile()
{
	file = new std::ofstream;
	
	if (logCounter == 0)
	{
		file->open("C:/Users/nikei/source/repos/OOPLab/OOPLab/src/Log/logger.txt");
		logCounter++;
	}
	else
	{
		file->open("C:/Users/nikei/source/repos/OOPLab/OOPLab/src/Log/logger.txt", std::ios::app);
	}
	
	
}


LogFile::~LogFile()
{
	file->close();
	if (file)
		delete file;
}

void LogFile::PrintLog(std::string log)
{
	time_t rawtime = time(0);
	tm timeinfo;
	errno_t result = localtime_s(&timeinfo, &rawtime);
	std::string hours = std::to_string(timeinfo.tm_hour);
	std::string minutes = std::to_string(timeinfo.tm_min);
	std::string seconds = std::to_string(timeinfo.tm_sec);
	if (hours.length() == 1) hours = "0" + hours;
	if(minutes.length() == 1) minutes = "0" + minutes;
	if (seconds.length() == 1) seconds = "0" + seconds;

	*file << "[" << hours << ":" << minutes << ":" << seconds << "] " << log << '\n';
}

