#pragma once
#include "enum.h"
#include <iostream>

class Cell
{
public:
	Cell();
	~Cell() {};
	void setWall();
	void setEntry();
	void setExit();
	void setCell(CellType);
	void setItem(ItemType);
	void clearCell();
	void printCell();
	CellType getCellType();
	ItemType getItemType();

private:
	CellType type;
	ItemType item;
};

