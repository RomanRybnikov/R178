#pragma once
#include "Player.h"
#include "Map.h"

namespace Game {
	class RandomWolker
	{
		Maps::Map* m_Map;
		Player* m_Player;
		Maps::Iterator* m_PlayerPositionIerator;
		Maps::Iterator* m_Iterator;

		void Up();
		void Down();
		void Left();
		void Right();

		bool CheckPosition(Maps::MapPosition pos);
	public:
		RandomWolker();
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator);
		void Update(); // обновление логики в основном цикле
		void CollideWithPlayer(Player* player); // происходит, при столкновении с игроком
		Maps::Iterator* GetIterator(); // итератор позиции врага
	};
}

