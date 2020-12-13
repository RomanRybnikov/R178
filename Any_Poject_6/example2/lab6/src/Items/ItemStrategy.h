#ifndef ITEMSTRATEGY_H
#define ITEMSTRATEGY_H

#include "Item.h"
#include "../Hero/Hero.h"

class ItemStrategy
{
private:
	Item* itemStrategy = nullptr;

public:
	ItemStrategy() = default;

	void SetStrategy(Item* itemStrategy);

	void UseItem(Hero &hero);

};

#endif // !ITEMSTRATEGY_H