#pragma once
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Iterator.h"

#define RandomWolker_ID 1
#define MoveToPlayer_ID 2
#define PlayerKiller_ID 3
#define CoinsTheaf_ID 4

namespace Game {
	// интерфейс врага (чтобы с ним можно было работать геймконтроллеру)
	class IEnemy {
	protected:
		Maps::MapPosition m_Position;
		Maps::Map* m_Map;
		Player* m_Player;
		Maps::Iterator* m_PlayerPositionIterator;
	public:
		IEnemy(){
			m_Map = 0;
			m_Player = 0;
			m_PlayerPositionIterator = 0;
		}
		virtual ~IEnemy() {}
		virtual void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator, bool randomPosition) { // виртуальная функция меняет свое тело на ту, которая описана в другом классе
			m_Map = map;
			m_Player = player;
			m_PlayerPositionIterator = playerPositionIerator;
		}
		virtual void Update() = 0; // обновление логики в основном цикле
		virtual std::ostream& Print(std::ostream& os) = 0;
		virtual void Save(std::ostream& os) = 0;

		static IEnemy* Load(std::istream& is);

		Maps::MapPosition GetPosition() { return m_Position; }
        Maps::MapPosition& SetPosition(Maps::MapPosition position) { return m_Position = position; }
	};

	template<typename TWolker, typename TCollideWithPlayer>
	class Enemy : public IEnemy
	{
		TWolker m_WolkBehaviour; // тип перемещения
		TCollideWithPlayer m_CollideWithPlayerBehaviour; // тип действия при встрече с игроком
	public:
		Enemy() {}
		Enemy(std::istream& is) {
			int row, col;
			is >> row >> col;
			m_Position.SetRow(row);
			m_Position.SetCol(col);
		}
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator, bool randomPosition) {
			IEnemy::Initialize(map, player, playerPositionIerator, randomPosition); // вызываем инициализацию базового класса
			m_WolkBehaviour.Initialize(map, player, playerPositionIerator);
			if (randomPosition) m_Position = m_WolkBehaviour.GetStartPosition();
		}
		void Update() { 
			// меняем позицию
			m_Position = m_WolkBehaviour + m_Position;
			// проверяем наличие столкновения с игроком
			if (m_PlayerPositionIterator->GetMapPos() == m_Position)
				m_CollideWithPlayerBehaviour + *m_Player;
		}
		void Save(std::ostream& os) {
			// пишем тип генерации
			os << m_WolkBehaviour.Id() << ' ' << m_CollideWithPlayerBehaviour.Id() << ' ';
			// пишем позицию	
			os << m_Position.GetRow() << ' ' << m_Position.GetCol() << std::endl;
		}
		std::ostream& Print(std::ostream& os) {
			return m_CollideWithPlayerBehaviour.Print(os);
		}
	};
}

//Game g;
//g.SetEnemy(new Enemt<UpdateA, CollideTypeB>());

