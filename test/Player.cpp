#include "Player.h"

Player::Player(Field* field) : m_Iterator(field)
{
	m_Field = field;
	m_HP = 100;
	m_Scores = 0;
}

FieldIterator& Player::GetIterator()
{
	return m_Iterator;
}

int Player::GetScores()				// возвращает очки
{
	return m_Scores;
}
int Player::SetScores(int scores)	// задает очки
{
	m_Scores = scores;
	return m_Scores;
}

void Player::Update()					// обновляет игрока
{
	// взаимодействуем с ячейкой
	m_Iterator.Value() + *this;
}

std::ostream& operator<<(std::ostream& os, Player& player)
{
	// вывод параметров игрока
	os << "HP:\t" << player.m_HP << std::endl;
	os << "SCORES:\t" << player.m_Scores << std::endl;

	// вывод поля
	for (int i = 0; i < player.m_Field->GetRow(); i++) {
		for (int j = 0; j < player.m_Field->GetCol(); j++) {
			// выводим крест, если выводим позицию итератора, и выводим поле, в противном случае
			if (&player.GetIterator().Value() == &player.m_Field->GetCage(i, j)) os << 'X';			
			else os << player.m_Field->GetCage(i, j);
			// провел в любом случае
			os << ' ';
		}
		os << std::endl;
	}

	return os;
}

float Player::GetHP() { return m_HP; }

float Player::SetHP(float value)		// задает хп
{
	m_HP = value;
	if (m_HP < 0) m_HP = 0;
	return m_HP;
}

void Player::Save(std::ostream& os)
{
	os << m_HP << ' ' << m_Scores << ' ';
	m_Iterator.Save(os);
	os << std::endl;
}
void Player::Load(std::istream& is)
{
	is >> m_HP >> m_Scores;
	m_Iterator.Load(is);
}