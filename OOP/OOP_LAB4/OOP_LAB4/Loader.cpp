#include "Loader.h"

Loader::Loader(std::string fileName) {
	m_FStream = new std::ifstream(fileName);
}
Loader::~Loader()
{
	m_FStream->close();
	delete m_FStream;
}
