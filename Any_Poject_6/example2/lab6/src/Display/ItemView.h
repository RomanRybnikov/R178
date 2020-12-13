#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <SFML/Graphics.hpp>
#include "../GameField/Cell.h"
#include <iostream>

class ItemView
{
private:
	std::string itemName;

	sf::Sprite itemSprite;

	sf::Texture openChestTexture;
	sf::Texture keyTexture;
	sf::Texture heartTexture;
	sf::Texture chestTexture;
public:
	ItemView();

	sf::Sprite SetItemTexture();
	void SetItemType(std::string itemName);
};



#endif