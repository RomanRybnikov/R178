#include "FieldIterator.h"
#include "iostream"


FieldIterator::FieldIterator(Cell** field, int height, int width, int startY, int startX)
{
	this->field = field;

	this->x = startX;
	this->y = startY;

	this->height = height;
	this->width = width;
} 

void FieldIterator::NextColumn()
{
	if (IsLastColumn())
	{
		std::cout << "No more way.\n";
		y = 0;
		x = width;
		return;
	}
	x++;
}

bool FieldIterator::IsLastColumn()
{
	return (x == width - 1);
}

void FieldIterator::PreviousColumn()
{
	if (IsFirstColumn())
	{
		std::cout << "No more way.\n";
		x = 0;
		y = 0;
	}
	x--;
}

bool FieldIterator::IsFirstColumn()
{
	return (x == 0);
}


void FieldIterator::next()
{
	if (y == 0 && x == width)
	{
		std::cout << "No more way.\n";
		return;
	}

	else if (y == height - 1)
	{
		y = 0;
		x++;
	}
	else {
		y++;
	}
}


void FieldIterator::previous()
{
	if (x == 0 && y == 0)
	{
		std::cout << "No more way.\n";
		return;
	}
	else if (y == 0)
	{
		y = height - 1;
		x--;
	}
	else {
		y--;
	}
}



Cell* FieldIterator::GetCurrentCell()
{
	if (y == 0 && x == width)
	{
		return nullptr;
	}
	return &field[y][x];
}

int FieldIterator::GetX()
{
	return x;
}

int FieldIterator::GetY()
{
	return y;
}

void FieldIterator::operator++()
{
	NextColumn();
}

void FieldIterator::operator--()
{
	PreviousColumn();
}

void FieldIterator::operator++(int)
{
	next();
}

void FieldIterator::operator--(int)
{
	previous();
}

bool FieldIterator::operator==(const FieldIterator& other)
{

	if (this->x == other.x && this->y == other.y)
		return true;
	return false;
}

bool FieldIterator::operator!=(const FieldIterator& other)
{
	if (this->x == other.x && this->y == other.y)
		return false;
	return true;
}