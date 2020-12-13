#include "ItemView.h"

ItemView::ItemView()
{
	keyTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/Key.png");
	heartTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/Heart.png");
	chestTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/Chest.png");
	openChestTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/OpenChest.png");
}

sf::Sprite ItemView::SetItemTexture()
{
	
	if(itemName == "Chest")  itemSprite.setTexture(chestTexture); 
	if (itemName == "Heart") itemSprite.setTexture(heartTexture); 
	if (itemName == "Key") itemSprite.setTexture(keyTexture);
	if (itemName == "OpenedChest") itemSprite.setTexture(openChestTexture);
	return itemSprite;
}

void ItemView::SetItemType(std::string itemName)
{
	this->itemName = itemName;
}