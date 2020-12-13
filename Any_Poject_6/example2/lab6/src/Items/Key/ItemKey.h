#ifndef ITEMKEY_H
#define ITEMKEY_H

#include "../Item.h"


class ItemKey:public Item
{
private: 
	std::string itemName = "Key";
public:
	std::string GetItemName() { return itemName; }
	void operator+(Hero &hero);
	void print(std::ostream& out) const;
	
};

#endif 