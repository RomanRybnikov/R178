#include "ItemHeart.h"

void ItemHeart::operator+(Hero &hero)
{
	hero.AddHealtPoints();
}

void ItemHeart::print(std::ostream& out) const
{
	out << this->itemName;
}
