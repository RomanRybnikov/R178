#ifndef ITEMSPEARFACTORY_H
#define ITEMSPEARFACTORY_H

#include "ItemHeart.h"
#include "../ItemFactory.h"

class ItemHeartFactory:public ItemFactory
{
public:
	Item* createItem();
};

#endif