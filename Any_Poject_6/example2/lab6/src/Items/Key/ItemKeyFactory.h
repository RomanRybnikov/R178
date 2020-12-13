#ifndef ITEMKEYFACTORY_H
#define ITEMKEYFACTORY_H

#include "ItemKey.h"
#include "../ItemFactory.h"

class ItemKeyFactory:public ItemFactory
{
public: 
	Item* createItem();
};

#endif