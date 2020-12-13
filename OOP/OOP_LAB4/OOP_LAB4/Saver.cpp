#include "Saver.h"

Saver::Saver(std::string fileName) {
	m_FStream = new std::ofstream(fileName, std::ios::out);
}
Saver::~Saver() {
	m_FStream->close();
	delete m_FStream;
}