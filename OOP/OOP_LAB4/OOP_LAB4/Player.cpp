#include "Player.h"
#include <iostream>
#include "FailWinEndMapStrattegy.h"
#include "WinEndMapStrattegy.h"
#include "EndMapStrattegy.h"

using namespace Game;

Player::Player(Maps::Iterator* mapIterator) {
	m_State = Game::States::IN_GAME;
	m_Coins = 0;
	m_Health = 100;
	m_Iterator = mapIterator;
	m_Iterator->AddListener(this); // подписываемся на смещение итератора
	m_EndMapStrattegy = new FailWinEndMapStrattegy();
}

void Player::OnMove(Maps::Iterator* iterator) // происходит, когда двигается итератор
{
	(*this) + iterator->Get();
}

Player& Player::operator+(Maps::Cell& cell) {
	cell.ApplyPlayer(this);
	return *this;
}

double Player::GetCoins() {
	return m_Coins;
}

unsigned int Player::SetCoins(unsigned int coins) {
	m_Coins = coins;
	delete m_EndMapStrattegy;
	if (m_Coins >= WIN_COINS) 
		m_EndMapStrattegy = new WinEndMapStrattegy();	
	else 
		m_EndMapStrattegy = new FailWinEndMapStrattegy();
	return m_Coins;
}

void Player::TellAboutEndCell()	// сказать игроку, что он стоит вконце поля
{
	m_EndMapStrattegy->TellAboutEndCell(this);
}

States Player::GetState() {
	return m_State;
}

States Player::SetState(States state) {
	m_State = state;
	return m_State;
}

double Player::GetHealth() { 
	return m_Health; 
}

double Player::SetHealth(double health) {
	m_Health = health;
	if (m_Health <= 0) {
		m_Health = 0;
		SetState(States::DEAD);
	}
	return m_Health;
}

namespace Game {
	std::ostream& operator<<(std::ostream& os, Player& player)
	{
		// вывод текущих данных
		os << "HEALTH:\t" << player.GetHealth() << std::endl;
		os << "COINS:\t" << player.GetCoins() << std::endl;
		// вывод поля
		os << *player.m_Iterator << std::endl;
		return os;
	}
}