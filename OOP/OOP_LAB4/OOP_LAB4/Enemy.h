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
		Maps::Iterator* m_PlayerPositionIerator;
	public:
		IEnemy(){
			m_Map = 0;
			m_Player = 0;
			m_PlayerPositionIerator = 0;
		}
		virtual ~IEnemy() {}
		virtual void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) { // виртуальна€ функци€ мен€ет свое тело на ту, котора€ описана в другом классе
			m_Map = map;
			m_Player = player;
			m_PlayerPositionIerator = playerPositionIerator;
		}
		virtual void Update() = 0; // обновление логики в основном цикле
		virtual std::ostream& Print(std::ostream& os) = 0;

		Maps::MapPosition GetPosition() { return m_Position; }
		Maps::MapPosition& SetPosition(Maps::MapPosition position) { m_Position = position; }
	};

	template<typename TWolker, typename TCollideWithPlayer>
	class Enemy : public IEnemy
	{
		TWolker m_WolkBehaviour; // тип перемещени€
		TCollideWithPlayer m_CollideWithPlayerBehaviour; // тип действи€ при встрече с игроком
	public:
		void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) {
			IEnemy::Initialize(map, player, playerPositionIerator); // вызываем инициализацию базового класса
			m_WolkBehaviour.Initialize(map, player, playerPositionIerator);
			m_Position = m_WolkBehaviour.GetStartPosition();
		}
		void Update() { 
			// мен€ем позицию
			m_Position = m_WolkBehaviour + m_Position;
			// провер€ем наличие столкновени€ с игроком
			if (m_PlayerPositionIerator->GetMapPos() == m_Position)
				m_CollideWithPlayerBehaviour + *m_Player;
		}
		std::ostream& Print(std::ostream& os) {
			return m_CollideWithPlayerBehaviour.Print(os);
		}
	};
}

//Game g;
//g.SetEnemy(new Enemt<UpdateA, CollideTypeB>());

