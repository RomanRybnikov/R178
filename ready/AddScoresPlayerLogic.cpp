#include "AddScoresPlayerLogic.h"
#include "Player.h"

AddScoresPlayerLogic::AddScoresPlayerLogic(int scores)
{
	m_Scores = scores;
}
Player& AddScoresPlayerLogic::Invoke(Player& player) {
	player.SetScores(player.GetScores() + m_Scores);
	return player;
}