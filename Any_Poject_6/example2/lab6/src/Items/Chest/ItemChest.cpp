#include "ItemChest.h"




void ItemChest::operator+(Hero& hero)
{
	hero.AddOpenedChest();
	Open();
}

void ItemChest::print(std::ostream& out) const
{
	out << this->itemName;
}