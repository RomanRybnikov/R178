#include "EnemyBehaviours.h"

std::ostream& operator << (std::ostream& os, EnemyKillBehaviour&)
{
	return os << "%";
}
std::ostream& operator << (std::ostream& os, EnemyScoresBehaviour&)
{
	return os << "-";
}
std::ostream& operator << (std::ostream& os, EnemyTeleportBehaviour&)
{
	return os << "7";
}