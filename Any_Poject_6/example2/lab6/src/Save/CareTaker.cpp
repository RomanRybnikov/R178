#include "CareTaker.h"

CareTaker::CareTaker(GameManager* gameManager)
{
	this->gameManager = gameManager;
	saveFile = new SaveFile();
}

void CareTaker::BackUp()
{
	std::string resStr = "";
	if (this->memento)
		delete this->memento;
	try 
	{
		this->memento = this->gameManager->Save();
		if (this->memento == nullptr)
			throw SaveException();
	}
	catch (SaveException e)
	{
		std::cerr << e.what();
		exit(0);
	}
	catch (std::bad_alloc e)
	{
		std::cerr << "Out of memory!\n";
		exit(0);
	}

	
	resStr += std::to_string(memento->State().beatEnemyPos.first) + " " + std::to_string(memento->State().beatEnemyPos.second) + "\n"
		+ std::to_string(memento->State().TPEnemyPos.first) + " " + std::to_string(memento->State().TPEnemyPos.second) + "\n"
		+ std::to_string(memento->State().robEnemyPos.first) + " " + std::to_string(memento->State().robEnemyPos.second) + "\n"
		+ std::to_string(memento->State().heroPos.first) + " " + std::to_string(memento->State().heroPos.second) + "\n"
		+ std::to_string(memento->State().heroHealth) + "\n"
		+ std::to_string(memento->State().heroKeys) + "\n"
		+ std::to_string(memento->State().heroOpenedChests) + "\n";
	resStr += std::to_string(memento->State().heartCount) + "\n";
	for (int i = 0; i < memento->State().heartsPos.size(); i++)
	{
		resStr += std::to_string(memento->State().heartsPos[i].first) + " " + std::to_string(memento->State().heartsPos[i].second) + "\n";
 	}
	resStr += std::to_string(memento->State().chestsCount) + "\n";
	for (int i = 0; i < memento->State().chestsPos.size(); i++)
	{
		resStr += std::to_string(memento->State().chestsPos[i].first) + " " + std::to_string(memento->State().chestsPos[i].second) + "\n";
	}
	resStr += std::to_string(memento->State().keysCount) + "\n";
	for (int i = 0; i < memento->State().keysPos.size(); i++)
	{
		resStr += std::to_string(memento->State().keysPos[i].first) + " " + std::to_string(memento->State().keysPos[i].second) + "\n";
	}
	
	resStr += std::to_string(memento->State().openedChestsCount) + "\n";
	for (int i = 0; i < memento->State().openedChestsPos.size(); i++)
	{
		resStr += std::to_string(memento->State().openedChestsPos[i].first) + " " + std::to_string(memento->State().openedChestsPos[i].second) + "\n";
	}
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			resStr += std::to_string(memento->State().field[i][j]) + " ";
		}
		resStr += "\n";
	}
	saveFile->ChangeMode(Mode::SAVE);
	saveFile->SaveGame(resStr);
	gameManager->GameSaved();
}

void CareTaker::Load()
{
	saveFile->ChangeMode(Mode::LOAD);
	Parser(saveFile->LoadGame());
	this->gameManager->Restore(this->memento);

}

void CareTaker::Parser(std::stringstream str)
{
	try
	{
		
		if (this->memento == nullptr)
		{
			GameInfo state;
			this->memento = new ConcreteMemento(state);
		}
			
		memento->State().beatEnemyPos = ParseCoords(str);
		memento->State().TPEnemyPos = ParseCoords(str);
		memento->State().robEnemyPos = ParseCoords(str);
		memento->State().heroPos = ParseCoords(str);
		memento->State().heroHealth = ParseValue(str);
		memento->State().keysCount = ParseValue(str);
		memento->State().openedChestsCount = ParseValue(str);
		memento->State().heartCount = ParseValue(str);
		memento->State().heartsPos.empty();
		for (int i = 0; i < memento->State().heartCount; i++)
			memento->State().heartsPos.push_back(ParseCoords(str));
		memento->State().chestsCount = ParseValue(str);
		memento->State().chestsPos.empty();
		for (int i = 0; i < memento->State().chestsCount; i++)
			memento->State().chestsPos.push_back(ParseCoords(str));
		memento->State().keysCount = ParseValue(str);
		memento->State().keysPos.empty();
		for (int i = 0; i < memento->State().keysCount; i++)
			memento->State().keysPos.push_back(ParseCoords(str));
		memento->State().openedChestsCount = ParseValue(str);
		memento->State().openedChestsPos.empty();
		for (int i = 0; i < memento->State().openedChestsCount; i++)
			memento->State().openedChestsPos.push_back(ParseCoords(str));

		std::string temp;
		std::string temp2;
		for (int i = 0; i < FIELD_HEIGHT; i++)	
		{
			temp2 = "";
			std::getline(str, temp);
			std::stringstream ss(temp);
			for (int j = 0; j < FIELD_WIDTH; j++)
			{
				ss >> memento->State().field[i][j];
				temp2 += std::to_string(memento->State().field[i][j]) + " ";
				if (memento->State().field[i][j] > 4 || memento->State().field[i][j] < 0)
				{
					throw LoadSaveException();
				}
			}
			if (temp != temp2)
			{
				throw LoadSaveException();
			}
		}
		std::getline(str, temp);
		if (!str.eof())
		{
			throw LoadSaveException();
		}
		//memento->State().print();
	}
	catch (LoadSaveException e)
	{
		std::cerr << e.what();
		exit(0);
	}
	
}

std::pair<int,int> CareTaker::ParseCoords(std::stringstream& str)
{
	std::string tempString;
	std::getline(str, tempString);
		
	std::pair<int, int> coords;
	std::stringstream ss(tempString);
	int coord;

	ss >> coord;
	coords.first = coord;

	ss >> coord;
	coords.second = coord;

	if (std::to_string(coords.first) + " " + std::to_string(coords.second) != tempString)
	{
		throw LoadSaveException();
	}

	if (coords.first < 0 || coords.first > 10 || coords.second < 0 || coords.second > 10)
	{
		throw LoadSaveException();
	}
		

	return coords;
	
}

int CareTaker::ParseValue(std::stringstream& str)
{
	std::string tempString;
	std::getline(str, tempString);
	int value = std::stoi(tempString);
	if (std::to_string(value) != tempString)
	{
		throw LoadSaveException();
	}
	return value;
}
