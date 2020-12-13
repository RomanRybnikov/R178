#ifndef ENEMYVIEW_H
#define ENEMYVIEW_H

#include <SFML/Graphics.hpp>
#include "../GameField/Cell.h"
#include <iostream>

class EnemyView
{
private:

	std::string enemyType;

	sf::Sprite enemySprite;

	sf::Texture enemyTPTexture;
	sf::Texture enemyRobTexture;
	sf::Texture enemyBeatTexture;
public:
	EnemyView();
	sf::Sprite SetEnemyTexture();
	void SetEnemyType(std::string enemyType);

};

#endif
