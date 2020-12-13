#ifndef DISPLAY_H
#define DISPLAY_H

#include "iostream"
#include "../GameField/Field.h"
#include <SFML/Graphics.hpp>
#include "CellView.h"
#include "ItemView.h"
#include "EnemyView.h"
#define FIELD_HEIGHT 11
#define FIELD_WIDTH 11
#define CELL_SIZE 50
#define WINDOW_HEIGHT 620
#define WINDOW_WIDTH 550




class Display
{
private:

	//Поля класса, содержащие информацию о поле
	Cell** field;

	sf::Sprite heroSprite;
	sf::Texture heroTexture;
	
	//Поля класса, отвечающие за текстуру предметов и клеток поля
	ItemView itemView;
	CellView cellView;
	EnemyView enemyView;

	void PlaceCellSprite(sf::RenderWindow& window, int x, int y);
	
public:
	Display(Field* gameField);


	//Функции отображения окна игры
	void DisplayField(sf::RenderWindow &window);
	void DisplayHero(sf::RenderWindow& window, Hero& hero);
	void DisplayItemsAndEnemies(sf::RenderWindow& window);
	void DisplayHeroInformation(sf::RenderWindow& window, Hero &hero);
	void DisplayWinWindow(sf::RenderWindow& window);
	void DisplayStartWindow(sf::RenderWindow& window);
	void DisplayLostWindow(sf::RenderWindow& window);
	
};

#endif