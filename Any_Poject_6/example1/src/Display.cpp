#include "Display.h"

Display::Display() {
	field = Area::getInstance();
}

Iterator Display::begin() {
	return Iterator(*field->data, field->height, field->width, field->data);
}

Iterator Display::end() {
	return Iterator(*(field->data + field->height));
}


void Display::printArea(Area* field)
{
	int i = 0;
	for (Iterator it = this->begin(); it != this->end(); ++it)
	{
		it->printCell();
		if (i == this->field->width - 1) {
			std::cout << std::endl;
			i = 0;
		}
		else {
			i++;
		}
	}
}