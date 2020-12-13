#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "../Exceptions/SaveException.h"
#include "../Exceptions/LoadSaveException.h"

enum class Mode
{
	SAVE, 
	LOAD
};

class SaveFile
{
private:
	std::ofstream* file = nullptr;
	Mode mode = Mode::SAVE;
	std::string fileName;
public:
	SaveFile();
	~SaveFile();
	void ChangeMode(Mode mode);
	void SaveGame(std::string saveMessage);
	void LoadingEnded();
	std::stringstream LoadGame();
	void ClearMemory();
};

#endif