#pragma once
#include <string>
#include <fstream>

// поток сохранения игры
class SaveStream
{
	std::string m_FileName;
	std::ofstream* m_OFStream;
	std::ifstream* m_IFStream;
public:
	SaveStream(std::string fileName, bool isSave);
	~SaveStream();

	std::string& GetFileName() {
		return m_FileName;
	}
	std::ofstream& GetOStream() {
		return *m_OFStream;
	}
	std::ifstream& GetIStream() {
		return *m_IFStream;
	}
};

