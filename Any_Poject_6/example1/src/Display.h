#pragma once
#include "Area.h"
#include "Iterator.h"

class Display
{
public:
	Display();
	void printArea(Area* field);
	Iterator begin();
	Iterator end();
private:
	Area* field;
};