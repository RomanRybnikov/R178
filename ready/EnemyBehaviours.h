#pragma once
#include <iostream>
#include "Field.h"
#include "Player.h"
#include "Enemy.h"

class EnemyKillBehaviour
{
public:
	EnemyKillBehaviour& operator+(Player& player) { player.SetHP(0); return *this; }
	friend std::ostream& operator << (std::ostream& os, EnemyKillBehaviour&);
	void Save(std::ostream& os) {
		os << IEnemy::KILL_BEH_ID << ' ';
	}
};

class EnemyScoresBehaviour
{
public:
	EnemyScoresBehaviour& operator+(Player& player) { player.SetScores(0); return *this; }
	friend std::ostream& operator << (std::ostream& os, EnemyScoresBehaviour&);
	void Save(std::ostream& os) {
		os << IEnemy::SCORES_BEH_ID << ' ';
	}
};

class EnemyTeleportBehaviour
{
public:
	EnemyTeleportBehaviour& operator+(Player& player) {
		while (player.GetIterator().Up());
		while (player.GetIterator().Left());
		return *this;
	}
	friend std::ostream& operator << (std::ostream& os, EnemyTeleportBehaviour&);
	void Save(std::ostream& os) {
		os << IEnemy::TELEPORT_BEH_ID << ' ';
	}
};

