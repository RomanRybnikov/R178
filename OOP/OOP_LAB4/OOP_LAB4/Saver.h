#pragma once
#include <iostream>
#include <fstream>
#include <string>

// сохраняет в файл по идиоме RAII
class Saver
{
	std::ofstream* m_FStream;

public:
	Saver(std::string fileName);
	~Saver();

	std::ofstream& Stream() { return *m_FStream; }
};

