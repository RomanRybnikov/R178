#include "EnemyView.h"

EnemyView::EnemyView()
{
	enemyRobTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/RobEnemy.png");
	enemyTPTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/TPEnemy.png");
	enemyBeatTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/BeatEnemy.png");
}

sf::Sprite EnemyView::SetEnemyTexture()
{
	if (enemyType == "TP")  enemySprite.setTexture(enemyTPTexture);
	if (enemyType == "Rob") enemySprite.setTexture(enemyRobTexture);
	if (enemyType == "Beat") enemySprite.setTexture(enemyBeatTexture);
	return enemySprite;
}

void EnemyView::SetEnemyType(std::string enemyType)
{
	this->enemyType = enemyType;
}
