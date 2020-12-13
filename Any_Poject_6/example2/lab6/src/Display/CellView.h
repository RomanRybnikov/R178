#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <SFML/Graphics.hpp>
#include "../GameField/Cell.h"
#include <iostream>


class CellView
{
private: 
	CellType cellType;
	
	sf::RectangleShape rectangle; 

	sf::Texture grassTexture;
	sf::Texture wallTexture;
	sf::Texture doorTexture;
	sf::Texture diggedGrassTexture;

public: 
	CellView();
	void SetCellType(CellType cellType);
	sf::RectangleShape SetRectangleTexture();
};


#endif