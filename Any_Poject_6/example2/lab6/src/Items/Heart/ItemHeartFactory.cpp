#include "ItemHeartFactory.h"


Item* ItemHeartFactory::createItem()
{
	return new ItemHeart;
}