#include "Enemy.h"
#include "EnemyBehaviours.h"

IEnemy* IEnemy::Load(std::istream& is)
{
	int id;
	is >> id;
	switch (id) {
	case IEnemy::KILL_BEH_ID: return new Enemy<EnemyKillBehaviour>(is);
	case IEnemy::SCORES_BEH_ID: return new Enemy<EnemyScoresBehaviour>(is);
	case IEnemy::TELEPORT_BEH_ID: return new Enemy<EnemyTeleportBehaviour>(is);
	}
	throw "unknown enemy type";
}
