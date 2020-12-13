#include "ItemChestFactory.h"

Item* ItemChestFactory::createItem()
{
	return new ItemChest;
}