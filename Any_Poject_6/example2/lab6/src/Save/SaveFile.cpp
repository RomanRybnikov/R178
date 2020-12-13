#include "SaveFile.h"

SaveFile::SaveFile()
{
	fileName = "C:/Users/nikei/source/repos/OOPLab/OOPLab/src/Save/saver.txt";
	try
	{
		file = new std::ofstream;
		file->open(fileName, std::ios::in);
		if (!file->is_open())
			throw SaveException();
	}
	catch (std::bad_alloc e)
	{
		std::cerr << "Out of memory!\n";
		ClearMemory();
		exit(0);
	}
	catch (SaveException)
	{
		std::cerr << "Can't open file.\n";
		ClearMemory();
		exit(0);
	}
	
}

SaveFile::~SaveFile()
{
	ClearMemory();
}

void SaveFile::ChangeMode(Mode mode)
{
	this->mode = mode;
	try
	{
		if (this->mode == Mode::SAVE)
		{
			file->close();
			file->open(fileName, std::ios::out);
		}
		else if (this->mode == Mode::LOAD)
		{
			file->close();
			file->open(fileName, std::ios::in);
		}
		if (!file->is_open())
			throw SaveException();
	}	
	catch (SaveException)
	{
		std::cerr << "Can't open file.\n";
		ClearMemory();
		exit(0);
	}
	
}

std::stringstream SaveFile::LoadGame()
{
	std::stringstream sstr;
	sstr << file->rdbuf();
	return sstr;
}

void SaveFile::SaveGame(std::string saveMessage)
{
	*file << saveMessage;
}

void SaveFile::LoadingEnded()
{
	try
	{
		file->close();
		file->open(fileName, std::ios::out || std::ios::trunc);
		if (!file->is_open())
			throw SaveException();
	}
	catch (SaveException)
	{
		std::cerr << "Can't open file.\n";
		ClearMemory();
		exit(0);
	}
}

void SaveFile::ClearMemory()
{
	if (file->is_open())
		file->close();
	if (file)
		delete file;
}

