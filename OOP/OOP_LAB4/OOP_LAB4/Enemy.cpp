#include "Enemy.h"
#include "EnemyBehaviours.h"

Game::IEnemy* Game::IEnemy::Load(std::istream& is) {
	// читаем типы шаблона
	int type1;
	int type2;
	is >> type1 >> type2;
	// создаем врага по шаблону
	if (type1 == RandomWolker_ID && type2 == PlayerKiller_ID) 
		return new Game::Enemy<RandomWolker, PlayerKiller>(is);
	if (type1 == RandomWolker_ID && type2 == CoinsTheaf_ID)
		return new Game::Enemy<RandomWolker, CoinsTheaf>(is);
	if (type1 == MoveToPlayer_ID && type2 == PlayerKiller_ID)
		return new Game::Enemy<MoveToPlayer, PlayerKiller>(is);
	if (type1 == MoveToPlayer_ID && type2 == CoinsTheaf_ID)
		return new Game::Enemy<MoveToPlayer, CoinsTheaf>(is);
	throw "unknown enemy behaviour combination";
}