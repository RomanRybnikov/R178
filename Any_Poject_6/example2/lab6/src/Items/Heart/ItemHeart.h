#ifndef ITEMHEART_H
#define ITEMHEART_H

#include "../Item.h"

class ItemHeart:public Item
{
private:
	std::string itemName = "Heart";
public:
	std::string GetItemName() { return itemName; }
	void operator+(Hero &hero);
	void print(std::ostream& out) const;
};

#endif