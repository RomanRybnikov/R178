#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Item.h"

class ItemFactory
{
public:
	virtual Item* createItem() = 0;
};

#endif
