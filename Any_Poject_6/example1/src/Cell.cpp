#include "Cell.h"

Cell::Cell()
{
	clearCell();
}

void Cell::setWall()
{
	this->type = CellType::WALL;
}

void Cell::setEntry()
{
	this->type = CellType::ENTRY;
}

void Cell::setExit()
{
	this->type = CellType::EXIT;
}

void Cell::setCell(CellType type)
{
	this->type = type;
}

void Cell::setItem(ItemType item)
{
	this->type = CellType::OBJECT;
	this->item = item;
}

CellType Cell::getCellType()
{
	return this->type;
}

ItemType Cell::getItemType()
{
	return this->item;
}

void Cell::clearCell()
{
	if (this->type != CellType::EXIT)
	{
		this->type = CellType::VOID;
		this->item = ItemType::NONE;
	}
}

void Cell::printCell()
{
	if (type == CellType::OBJECT)
	{
		switch (item)
		{
		case ItemType::COIN:
			std::cout << "5 ";
			break;
		case ItemType::TRAP:
			std::cout << "6 ";
			break;
		case ItemType::LIFE_BUFFER:
			std::cout << "7 ";
			break;
		case ItemType::PERSON:
			std::cout << "9 ";
			break;
		default:
			break;
		}
	}
	else
	{
		switch (type)
		{
		case CellType::VOID:
			std::cout << "0 ";
			break;
		case CellType::WALL:
			std::cout << "1 ";
			break;
		case CellType::ENTRY:
			std::cout << "S ";
			break;
		case CellType::EXIT:
			std::cout << "E ";
		default:
			break;
		}
	}
}

