#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Loader
{
	std::ifstream* m_FStream;

public:
	Loader(std::string fileName);
	~Loader();

	std::ifstream& Stream() { return *m_FStream; }
};

