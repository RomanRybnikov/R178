#pragma once
#include "Field.h"
#include "Player.h"
#include "PlayerLoger.h"
#include "Enemy.h"

class Game
{
	Field* m_Field;
	Player* m_Player;
	IEnemy* m_Enemy;
	PlayerLoger* m_PlayerLoger;
	bool m_IsPlaying;
	bool m_IsWin;
public:
	Game(Field* field, IEnemy *enemy);
	~Game();

	void Up();
	void Down();
	void Left();
	void Right();
	bool IsPlaying();
	bool IsWin();
	void Exit();
	void Replay();
	void Draw();
	void Update();

	void Save(std::string fileName);
	void Load(std::string fileName);
};

