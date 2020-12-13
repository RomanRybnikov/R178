#include "Item.h"

std::ostream& operator<<(std::ostream out, const Item& item)
{
	item.print(out);
	return out;
}