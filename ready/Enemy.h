#pragma once
#include <iostream>
#include "Field.h"
#include "Player.h"

// базовый класс врага
class IEnemy {
protected:
	int m_Row; // строка положения
	int m_Col; // столбец положения

public:
	static const int KILL_BEH_ID = 1;
	static const int SCORES_BEH_ID = 2;
	static const int TELEPORT_BEH_ID = 3;

	virtual void Initialize(Field* field, Player* player, bool randomizePosition) = 0; // инициализация врага
	virtual void Update() = 0; // обновление врага
	virtual std::ostream& Draw(std::ostream& os) = 0; // прорисовка врага
	virtual void Save(std::ostream& os) = 0;
	int GetRow() { return m_Row; } 
	int GetCol() { return m_Col; }

	static IEnemy* Load(std::istream& is);
};

// шаблон реализациии врага
template<typename T> // параметр - поведение при столкновении
class Enemy: public IEnemy
{
	T m_Behaviour; // поведение
	Field* m_Field; 
	Player* m_Player;

	void SetStartPosition() { // задает изначальное положение врага (рандомное)
		m_Row = rand() % m_Field->GetRow();
		m_Col = rand() % m_Field->GetCol();
	}
	void UpdatePosition() {// обновляет позицию врага
		// запоминаем текущее положение
		auto lastRow = m_Row;
		auto lastCol = m_Col;
		// перемещаемся
		switch (rand()%4) {
		case 0: --m_Row; break;
		case 1: ++m_Row; break;
		case 2: --m_Col; break;
		case 3: ++m_Col; break;
		}
		// ограничитель смещения (если вышли за границы, то все вернуть)
		if (m_Col < 0 || m_Row < 0 ||
			m_Col >= m_Field->GetCol() || m_Row >= m_Field->GetRow()) {
			m_Row = lastRow;
			m_Col = lastCol;
		}
	}
	void UpdateCollisions() { // если столкнулись с игроком, то производит взаимодействие
		// если столкнулись с игроком, то отработка столкновения с игроком
		if (m_Player->GetIterator().GetCol() == m_Col &&
			m_Player->GetIterator().GetRow() == m_Row)
			m_Behaviour + *m_Player;
	}
public:
	Enemy() {}
	Enemy(std::istream& is) {
		is >> m_Row >> m_Col;
	}
	void Initialize(Field* field, Player* player, bool randomizePosition) { // инициализация врага
		m_Field = field;
		m_Player = player;
		if (randomizePosition) SetStartPosition();
	}
	void Update() { // обновление врага
		// производим смещение
		UpdatePosition();
		// обработка сторкновений
		UpdateCollisions();
	}
	std::ostream& Draw(std::ostream& os) { // прорисовка врага
		return os << m_Behaviour;
	}
	void Save(std::ostream& os) {
		m_Behaviour.Save(os);
		os << m_Row << ' ' << m_Col << ' ';
	}
};
