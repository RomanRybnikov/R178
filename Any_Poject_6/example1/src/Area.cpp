#include "Area.h"

Area::Area()
{
	this->height = 8;
	this->width = 10;
	this->data = new Cell * [this->height];
	for (int i = 0; i < this->height; i++)
	{
		this->data[i] = new Cell[this->width];
	}
}

Area::~Area()
{
	if (this->data != nullptr) {
		destroyArea();
	}
}

Area* Area::getInstance()
{
	if (!uniqueInstance)
	{
		uniqueInstance = new Area();
	}
	return uniqueInstance;
}

Area* Area::uniqueInstance = nullptr;

bool Area::DeleteInstance()
{
	if (uniqueInstance)
	{
		uniqueInstance->destroyArea();
		uniqueInstance = nullptr;
		return true;
	}
	return false;
}

Area::Area(const Area& other)
{
	this->height = other.height;
	this->width = other.width;

	this->data = new Cell * [other.height];
	for (int i = 0; i < other.height; i++)
	{
		this->data[i] = new Cell[other.width];
		for (int j = 0; j < other.width; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
	std::cout << "Cons cop" << '\n';
}

Area& Area::operator=(const Area& other)
{
	std::cout << "op cop" << '\n';
	if (this == &other)
	{
		return *this;
	}

	this->height = other.height;
	this->width = other.width;

	if (this->data != nullptr)
	{
		destroyArea();
	}

	this->data = new Cell * [this->height];
	for (int i = 0; i < this->height; i++)
	{
		this->data[i] = new Cell[this->width];
		for (int j = 0; j < other.width; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
	return *this;
}

Area::Area(Area&& other) noexcept
{
	this->height = other.height;
	this->width = other.width;
	this->data = other.data;
	other.data = nullptr;
	std::cout << "cons perem" << '\n';
}

Area& Area::operator= (Area&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}

	if (this != nullptr)
	{
		this->destroyArea();
		this->height = other.height;
		this->width = other.width;
		this->data = other.data;

		other.data = nullptr;

	}
	std::cout << "op perem" << '\n';
	return *this;
}


void Area::destroyArea()
{
	if (this->data)
	{
		for (int i = 0; i < this->height; i++)
		{
			delete[] this->data[i];
		}
		delete[] this->data;
	}
}