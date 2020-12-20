#pragma once
#include "FieldIterator.h"
#include <iostream>

class Player
{
	Field* m_Field;
	FieldIterator m_Iterator;	// позиция игрока
	int m_Scores;				// очки игрока
	float m_HP;

public:

	Player(Field* field);

	FieldIterator& GetIterator();
	int GetScores();				// возвращает очки
	int SetScores(int scores);		// задает очки
	float GetHP();
	float SetHP(float value);		// задает хп

	void Update();					// обновляет игрока
	void Save(std::ostream &os);
	void Load(std::istream& is);

	friend std::ostream& operator<<(std::ostream& os, Player& player);
};

