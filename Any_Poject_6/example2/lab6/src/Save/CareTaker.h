#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include "../GameManager/GameManager.h"
#include "SaveFile.h"
#include "../Exceptions/LoadSaveException.h"
#include "../Exceptions/SaveException.h"

class CareTaker
{
private:
	Memento* memento = nullptr;
	GameManager* gameManager;
	SaveFile* saveFile;
public:
	CareTaker(GameManager* gameManager);
	void BackUp();
	void Load();
	void Parser(std::stringstream str);
	std::pair<int, int> ParseCoords(std::stringstream& str);
	int ParseValue(std::stringstream& str);
};

#endif
