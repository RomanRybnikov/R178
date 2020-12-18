#include "Player.h"
#include <iostream>
#include "FailWinEndMapStrattegy.h"
#include "WinEndMapStrattegy.h"
#include "EndMapStrattegy.h"
#include "Enemy.h"
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

void Player::Save(std::ostream& os)
{
	auto playerPos = GetIterator().GetMapPos();
	os << playerPos.GetRow() << ' ' << playerPos.GetCol() << ' ';
	os << m_State << ' ';
	os << m_Coins << ' ';
	os << m_Health << ' ';
	os << m_EndMapStrattegy->Id() << std::endl;
}
void Player::Load(std::istream& is) {
	// позиция
	int row, col;
	is >> row >> col;
	GetIterator().SetMapPos(Maps::MapPosition(row, col));
	// состояние
	int stateId;
	is >> stateId >> m_Coins >> m_Health;
	if (stateId < 0 || stateId > 2) throw "unknown player state id";
	m_State = (Game::States)stateId;
	// страттегия конца
	int endMapStrattegyId;
	is >> endMapStrattegyId; // читаем ID типа
	if (m_EndMapStrattegy) delete m_EndMapStrattegy;
	switch (endMapStrattegyId) { // по прочитанному ID типа создаем нужную страттегию
	case FailWinEndMapStrattegy_ID: m_EndMapStrattegy = new FailWinEndMapStrattegy(); break;
	case WinEndMapStrattegy_ID: m_EndMapStrattegy = new WinEndMapStrattegy(); break;
	default: throw "unknown player end map strattegy id";
	}
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