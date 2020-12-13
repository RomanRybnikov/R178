#include "ItemKey.h"

void ItemKey::operator+(Hero& hero)
{
	hero.AddKey();
}

void ItemKey::print(std::ostream& out) const
{
	out << this->itemName;
}