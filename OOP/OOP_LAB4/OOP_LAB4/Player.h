#pragma once
#include "Iterator.h"

namespace Maps {
	class Iterator;
}

namespace Game {
	class EndMapStrattegy;
	enum States // состояния игры
	{
		IN_GAME,	// играет
		WIN,		// победил
		DEAD		// помер
	};

#define WIN_COINS 100 // сколько очков нужно чтобы переключить страттегию конца на страттегию победы

	class Player: public Maps::Iterator::Listener // наследуемся от наблюдателя за итератором
	{
		States m_State;				// текущее состояние игрока
		unsigned int m_Coins;		// монеты
		double m_Health;
		Maps::Iterator* m_Iterator; // положение игрока на карте
		EndMapStrattegy* m_EndMapStrattegy;

		virtual void OnMove(Maps::Iterator* iterator); // происходит, когда двигается итератор

	public:

		Player(Maps::Iterator* mapIterator);
		
		double GetHealth();
		double SetHealth(double health);
		double GetCoins();
		unsigned int SetCoins(unsigned int);
		States GetState();
		States SetState(States state);

		Maps::Iterator& GetIterator() { return *m_Iterator; }
		void TellAboutEndCell();	// сказать игроку, что он стоит вконце поля

		Player& operator+(Maps::Cell& cell); // сложение игрока и ячейки(для взаимодействия игрока с ячейкой)
		friend std::ostream& operator<<(std::ostream& os, Player& player);
	};
}

