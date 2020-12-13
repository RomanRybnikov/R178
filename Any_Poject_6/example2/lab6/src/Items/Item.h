#ifndef ITEM_H
#define ITEM_H
#include "../Hero/Hero.h"
#include <iostream>
#include <fstream>

class Item
{
public:
	virtual std::string GetItemName() = 0;
	virtual void operator+(Hero &hero) = 0;
	virtual void print(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream out, const Item& item);
};

#endif