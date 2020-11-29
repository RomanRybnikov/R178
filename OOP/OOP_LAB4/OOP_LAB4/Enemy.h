#pragma once
#include "Map.h"
#include "Player.h"

namespace Game {
	class IEnemy {
	public:
		virtual ~IEnemy() {}
		virtual void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) = 0;
		virtual void Update() = 0; // обновление логики в основном цикле
		virtual void CollideWithPlayer(Player* player) = 0; // происходит, при столкновении с игроком
		virtual Maps::Iterator* GetIterator() = 0; // итератор позиции врага
	};

	template<typename TUpdate, typename TCollideWithPlayer>
	class Enemy : public IEnemy
	{
		TUpdate m_UpdateBehaviour;
		TCollideWithPlayer m_CollideWithPlayerBehaviour;
	public:
		virtual void Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator) {
			m_UpdateBehaviour.Initialize(map, player, playerPositionIerator);
			m_CollideWithPlayerBehaviour.Initialize(map, player, playerPositionIerator);
		}
		virtual void Update() {
			m_UpdateBehaviour.Update();
		}
		virtual Maps::Iterator* GetIterator() {
			return m_UpdateBehaviour->GetIterator();
		}
		virtual void CollideWithPlayer(Player *player) { 
			m_CollideWithPlayerBehaviour.CollideWithPlayer(player);
		}
	};
}

//Game g;
//g.SetEnemy(new Enemt<UpdateA, CollideTypeB>());

