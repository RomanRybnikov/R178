#ifndef FIELDITERATOR_H
#define FIELDITERATOR_H



#include "Cell.h"

class FieldIterator
{
private: 
	int x, y;
	int height, width;
	Cell** field;

public:
	FieldIterator() = default;
	FieldIterator(Cell** field, int height, int width, int startY, int startX);


	//Функции перемещения
	bool IsLastColumn();
	void NextColumn();
	bool IsFirstColumn();
	void PreviousColumn();
	void next();
	void previous();

	//Функция получения текущей клетки поля
	Cell* GetCurrentCell();

	//Функции получения координат
	int GetX();
	int GetY();

	//Переопределение операторов для перемещения
	void operator++();
	void operator--();
	void operator++(int);
	void operator--(int);

	//Переопределение операторов сравнения
	bool operator==(const FieldIterator& other);
	bool operator!=(const FieldIterator& other);
};

#endif 