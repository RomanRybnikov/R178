#ifndef ITEMCHEST_H
#define ITEMCHEST_H

#include "../Item.h"

class ItemChest :public Item
{
private:
	std::string itemName = "Chest";
	void Open() { itemName = "OpenedChest"; }
public:
	std::string GetItemName() { return itemName; }
	void operator+(Hero& hero);
	void print(std::ostream& out) const;
	
};

#endif