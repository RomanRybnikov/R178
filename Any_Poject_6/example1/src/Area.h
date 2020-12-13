#pragma once
#include "Cell.h"
#include <iostream>

class Area
{
public:
	static Area* getInstance();
	static bool DeleteInstance();

private:
	friend class Display;
	friend class AreaHandler;
	Area(const Area& other);
	Area(Area&& other) noexcept;
	Area& operator= (const Area& other);
	Area& operator= (Area&& other) noexcept;
	Area();
	~Area();
	void destroyArea();

	Cell** data = nullptr;
	static Area* uniqueInstance;
	int height, width;
};
