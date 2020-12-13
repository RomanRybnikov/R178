#include "Field.h"
#include "FieldIterator.h"
#include "iostream"

Field* Field::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Field;
	}

	return instance;
}

void Field::DefineField()
{
	if (!field)
	{
		this->width = 11;
		this->height = 11;


		field = new Cell * [this->height];
		for (int i = 0; i < this->height; i++)
		{
			field[i] = new Cell[this->width];
			for (int j = 0; j < this->width; j++)
			{
				field[i][j].SetPosition(j, i);
			}
		}

		CreateMaze();
	}
}

void Field::GetSize(int& height, int& width)
{
	height = this->height;
	width = this->width;
}


void Field::CreateMaze()
{
	field[6][1].SetType(CellType::WALL);
	for (int i = 0; i < 11; i++)
	{
		if(i < 3 || i > 5)
			field[i][2].SetType(CellType::WALL);
	}
	for (int i = 2; i < 7; i++)
	{
		if(i != 5)
			field[i][3].SetType(CellType::WALL);
	}
	for (int i = 6; i < 10; i++)
		field[i][5].SetType(CellType::WALL);
	for (int i = 9; i < 11; i++)
		field[i][6].SetType(CellType::WALL);
	for (int i = 0; i < 7; i++)
		field[i][7].SetType(CellType::WALL);
	field[4][8].SetType(CellType::WALL);
	for (int i = 1; i < 11; i++)
	{
		if(i != 2 && i != 3 && i != 5)
			field[i][9].SetType(CellType::WALL);
	}
	field[1][10].SetType(CellType::WALL);
	FieldIterator it = begin();
	it.GetCurrentCell()->SetType(CellType::BEGIN);
	it = end();
	it--;
	it.GetCurrentCell()->SetType(CellType::END);
}



Cell** Field::GetField()
{
	return field;
}

Field::~Field()
{
	destroy();
	delete[] instance;
	
}



Field::Field(const Field& otherField) 
{
	this->width = otherField.width;
	this->height = otherField.height;

	this->field = new Cell * [height];
	for (int i = 0; i < height; i++)
	{
		this->field[i] = new Cell[width];
		for (int j = 0; j < width; j++)
		{
			this->field[i][j] = otherField.field[i][j];
		}
	}
}

Field::Field(Field&& otherField)
{
	this->width = otherField.width;
	this->height = otherField.height;

	this->field = otherField.field;

	otherField.field = nullptr;
}

Field& Field::operator=(const Field& otherField)
{
	if (&otherField == this)
		return *this;

	destroy();

	this->width = otherField.width;
	this->height = otherField.height;

	this->field = new Cell*[height];
	for (int i = 0; i < height; i++)
	{
		this->field[i] = new Cell[width];
		for (int j = 0; j < width; j++)
		{
			this->field[i][j] = otherField.field[i][j];
		}
	}
	return *this;
}	

Field& Field::operator=(Field&& otherField)
{
	destroy();
	
	this->width = otherField.width;
	this->height = otherField.height;

	this->field = otherField.field;

	return *this;
}

void Field::destroy()
{
	for (int i = 0; i < height; i++)
	{
		delete[] field[i];
	}
	delete[] field;
}

FieldIterator Field::begin()
{
	FieldIterator iterator(field, height, width, 0, 0);
	return iterator;
}

FieldIterator Field::end()
{
	FieldIterator iterator(field, height, width, 0, width);
	return iterator;
}

Field* Field::instance = nullptr;