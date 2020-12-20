#ifndef CAGE_h
#define CAGE_h

#include <string>
#include "IPlayerLogic.h"
#include <iostream>

enum CageType {
	IN = 1,
	OUT = 2,
	REG = 0
};

class Cage
{
	bool m_Pass;				// проходимая клетка или нет
	//std::string m_Data;			// данные клетки
	CageType m_Type;			// тип клетки
	IPlayerLogic* m_PlayerLogic;// логика взаимодействия с игроком

public:

	Cage();
	~Cage();

	CageType GetType();

	void ReCage(CageType _type);

	void Print();

	IPlayerLogic& SetPlayerLogic(IPlayerLogic* logic);

	Cage& operator+(Player& player);	// взаимодействие ячейки с игроком

	friend std::ostream& operator<<(std::ostream& os, Cage& cage);
	Cage& operator = (const Cage& c); // оп-р копирования
	void Save(std::ostream& os);
	void Load(std::istream& is);
};

#endif
