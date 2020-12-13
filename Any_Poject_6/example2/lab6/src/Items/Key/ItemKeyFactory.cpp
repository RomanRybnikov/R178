#include "ItemKeyFactory.h"


Item* ItemKeyFactory::createItem()
{
	return new ItemKey;
}