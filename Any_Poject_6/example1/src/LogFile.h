#pragma once
#include <fstream>

class LogFile {
public:
	LogFile() : logfile("log.txt", std::ios::out) {
		if (!logfile) {
			throw std::runtime_error("file is not open");
		}
	}
	~LogFile() {
		logfile.close();
	}
	std::ofstream& getLogFile() {
		return logfile;
	};

private:
	std::ofstream logfile;
};