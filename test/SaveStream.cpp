#include "SaveStream.h"

SaveStream::SaveStream(std::string fileName, bool isSave) {
	m_FileName = fileName;
	m_OFStream = 0;
	m_IFStream = 0;
	if (isSave) m_OFStream = new std::ofstream(fileName, std::ios::out);
	else m_IFStream = new std::ifstream(fileName, std::ios::in);
}
SaveStream::~SaveStream() {
	if (m_OFStream) m_OFStream->close();
	if (m_IFStream) m_IFStream->close();
}