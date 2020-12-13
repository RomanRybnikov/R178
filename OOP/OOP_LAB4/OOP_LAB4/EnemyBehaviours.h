#pragma once
#include "Player.h"
#include "Map.h"

namespace Game {
#define RandomWolker_ID 1;
#define MoveToPlayer_ID 2;
#define PlayerKiller_ID 3;
#define CoinsTheaf_ID 4;

	// передвигает врага в случайную точку
	class RandomWolker
	{
		Maps::Map* m_Map;

	public:
		int Id() { return RandomWolker_ID; }
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) { // вызывается вначале игры
			m_Map = map;
		}

		Maps::MapPosition GetStartPosition() { // начальная позиция
			return Maps::MapPosition(rand() % m_Map->GetHeight(), rand() % m_Map->GetWidth());
		}

		Maps::MapPosition operator+(Maps::MapPosition position) { // берет текущее положение и возвращает новое
			// запоминаем позицию
			auto newPos = position;
			// смещаемся рандомно
			switch (rand()%4)
			{
			case 0: newPos.SetRow(newPos.GetRow() + 1); break;
			case 1: newPos.SetRow(newPos.GetRow() - 1); break;
			case 2: newPos.SetCol(newPos.GetCol() + 1); break;
			case 3: newPos.SetCol(newPos.GetCol() - 1); break;
			}
			// если сместились нетуда то откат
			if (newPos.GetCol() < 0 || newPos.GetRow() < 0 ||
				newPos.GetCol() >= m_Map->GetHeight() || newPos.GetRow() >= m_Map->GetWidth()) 
				return position;
			// если все ок
			return newPos;
		}
	};

	// двигает врага к игроку
	class MoveToPlayer
	{
		Maps::Map* m_Map;
		Maps::Iterator* m_PlayerPositionIerator;

	public:
		int Id() { return MoveToPlayer_ID; }
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) {
			m_Map = map;
			m_PlayerPositionIerator = playerPositionIerator;
		}

		Maps::MapPosition GetStartPosition() {
			return Maps::MapPosition(rand() % m_Map->GetHeight(), rand() % m_Map->GetWidth());
		}

		Maps::MapPosition operator+(Maps::MapPosition position) {
			// запоминаем позицию
			auto newPos = position;
			auto playerPos = m_PlayerPositionIerator->GetMapPos();
			// смещаемся рандомно
			if (position.GetRow() < playerPos.GetRow())
                position.SetRow(position.GetRow() + 1);
            
			else if (position.GetRow() > playerPos.GetRow())
                position.SetRow(position.GetRow() - 1);
            
			else if (position.GetCol() < playerPos.GetCol())
                position.SetCol(position.GetCol() + 1);
            
			else if (position.GetCol() > playerPos.GetCol())
                position.SetCol(position.GetCol() - 1);
            
			// если все ок
			return position;
		}
	};


	// убивает врага при встрече
	class PlayerKiller
	{
	public:
		int Id() { return PlayerKiller_ID; }
		PlayerKiller& operator+(Player& player) {
			player.SetState(States::DEAD);
			return *this;
		}
		std::ostream&  Print(std::ostream& os) {
			return os<<"K";
		}
	};
	class CoinsTheaf
	{
	public:
		int Id() { return CoinsTheaf_ID; }
		CoinsTheaf& operator+(Player& player) {
			player.SetCoins(0);
			return *this;
		}
		std::ostream& Print(std::ostream& os) {
			return os << "T";
		}
	};
}

