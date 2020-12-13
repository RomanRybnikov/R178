#ifndef ITEMCHESTFACTORY_H
#define ITEMCHESTFACTORY_H

#include "../ItemFactory.h"
#include "ItemChest.h"

class ItemChestFactory:public ItemFactory 
{
public: 
	Item* createItem();
};

#endif