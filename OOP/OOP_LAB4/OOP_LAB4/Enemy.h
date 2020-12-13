#pragma once
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Iterator.h"


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
		virtual void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) { // виртуальная функция меняет свое тело на ту, которая описана в другом классе
			m_Map = map;
			m_Player = player;
			m_PlayerPositionIterator = playerPositionIerator;
		}
		virtual void Update() = 0; // обновление логики в основном цикле
		virtual std::ostream& Print(std::ostream& os) = 0;

		Maps::MapPosition GetPosition() { return m_Position; }
        Maps::MapPosition& SetPosition(Maps::MapPosition position) { return m_Position = position; }
	};

	template<typename TWolker, typename TCollideWithPlayer>

	class Enemy : public IEnemy
	{
		TWolker m_WolkBehaviour; // тип перемещения
		TCollideWithPlayer m_CollideWithPlayerBehaviour; // тип действия при встрече с игроком
	public:
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) {
			IEnemy::Initialize(map, player, playerPositionIerator); // вызываем инициализацию базового класса
			m_WolkBehaviour.Initialize(map, player, playerPositionIerator);
			m_Position = m_WolkBehaviour.GetStartPosition();
		}
		void Update() { 
			// меняем позицию
			m_Position = m_WolkBehaviour + m_Position;
			// проверяем наличие столкновения с игроком
			if (m_PlayerPositionIterator->GetMapPos() == m_Position)
				m_CollideWithPlayerBehaviour + *m_Player;
		}
		std::ostream& Print(std::ostream& os) {
			return m_CollideWithPlayerBehaviour.Print(os);
		}
	};
}

//Game g;
//g.SetEnemy(new Enemt<UpdateA, CollideTypeB>());

