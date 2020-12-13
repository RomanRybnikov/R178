#include "AreaHandler.h"

ItemType AreaHandler::getCellItem(int x, int y) {
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		return Area::getInstance()->data[y][x].getItemType();
	}
	else
	{
		std::cout << "Incorrect values for getCellItem" << '\n';
	}
}

CellType AreaHandler::getCellType(int x, int y) {
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		return Area::getInstance()->data[y][x].getCellType();
	}
	else
	{
		std::cout << "Incorrect values for getCellType" << '\n';
	}
}

void AreaHandler::addPersone(int x, int y) {
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setItem(ItemType::PERSON);
	}
	else
	{
		std::cout << "Incorrect values for addPersone" << '\n';
	}
}

void AreaHandler::addEnemy(int x, int y) {
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setItem(ItemType::TRAP);
	}
	else
	{
		std::cout << "Incorrect values for addEnemy" << '\n';
	}
}

int AreaHandler::getHeight() {
    return Area::getInstance()->height;
}

int AreaHandler::getWidth() {
    return Area::getInstance()->width;
}

void AreaHandler::clearCell(int x, int y) {
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].clearCell();
	}
	else
	{
		std::cout << "Incorrect values for clearCell" << '\n';
	}
}

void AreaHandler::prepareArea() {
	setWallAroundArea();
	setItem(4, 0, ItemType::PERSON);
	setEntry(4, 0);
	setExit(5, 7);
	setItem(3, 3, ItemType::COIN);
	setItem(7, 4, ItemType::COIN);
	setItem(4, 6, ItemType::COIN);
	setItem(6, 2, ItemType::LIFE_BUFFER);
}

void AreaHandler::setWall(int x, int y)
{
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setWall();
	}
	else
	{
		std::cout << "Incorrect values for setWall" << '\n';
	}
}

void AreaHandler::setWallAroundArea()
{
	for (int x = 0; x < getWidth(); x++)
	{
		setWall(x, 0);
		setWall(x, getHeight() - 1);
	}
	for (int y = 0; y < getHeight(); y++)
	{
		setWall(0, y);
		setWall(getWidth() - 1, y);
	}
}

void AreaHandler::setEntry(int x, int y)
{
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setEntry();
	}
	else
	{
		std::cout << "Incorrect values for setEntry" << '\n';
	}
}

void AreaHandler::setExit(int x, int y)
{
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setExit();
	}
	else
	{
		std::cout << "Incorrect values for setExit" << '\n';
	}
}

void AreaHandler::setItem(int x, int y, ItemType item)
{
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setItem(item);
	}
	else
	{
		std::cout << "Incorrect values for setItem" << '\n';
	}
}

void AreaHandler::setCell(int x, int y, CellType type) 
{
	if (0 <= y && y < getHeight() && 0 <= x && x < getWidth())
	{
		Area::getInstance()->data[y][x].setCell(type);
	}
	else
	{
		std::cout << "Incorrect values for setCell" << '\n';
	}
}