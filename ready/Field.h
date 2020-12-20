#ifndef FIELD_H
#define FIELD_H

#include "Cage.h"
#include <iostream>

class IPlayerLogicFactory;

class Field
{
	int row, col;
	Cage** matrix;
	static Field* instance;				// синглтон
	IPlayerLogicFactory* m_Factory;		// фабрика логик

	void DataClear();
	void DataCopy(Field const& object);

	Field(int row, int col);
	void CreateLogic();

public:
	friend class FieldIterator;

	Field(const Field& object);			// констурктор копирования
	Field(Field&& object);				// констурктор перемещения
	~Field();

	void Print();
	int GetRow() { return row; }
	int GetCol() { return col; }
	void SetLogicFactory(IPlayerLogicFactory* factory);
	Cage& GetCage(int row, int col) { return matrix[row][col]; }
	static Field* GetInstance();
	static Field* GetInstance(int row, int col);

	void Save(std::ostream& os); // сохранение
	void Load(std::istream& is); // загрузка

	Field& operator = (const Field& field); // оп-р копирования
	Field& operator = (const Field&& field); // оп-р перемещения
};

#endif
