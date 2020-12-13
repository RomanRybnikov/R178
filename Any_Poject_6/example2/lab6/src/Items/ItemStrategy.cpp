#include "ItemStrategy.h"

void ItemStrategy::SetStrategy(Item* itemStrategy)
{
	this->itemStrategy = itemStrategy;
}

void ItemStrategy::UseItem(Hero &hero)
{
	if(itemStrategy)
		*itemStrategy + hero;
}
