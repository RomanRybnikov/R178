#include "Field.h"
#include "Cage.h"
#include <iostream>
#include "IPlayerLogicFactory.h"
#include "RandomPlayerLogicFactory.h"

Field* Field::instance = 0;

Field::Field(int row, int col)
{
	std::cout << "CONSTRUCTOR" << std::endl;
	this->row = row;
	this->col = col;
	this->m_Factory = new RandomPlayerLogicFactory();

	matrix = new Cage * [row];
	for (int i = 0; i < row; i++)	
		matrix[i] = new Cage[col];	

	CreateLogic();
}

Field::Field(Field&& object)
{
	this->row = object.row;
	this->col = object.col;
	this->matrix = object.matrix;
	this->m_Factory = object.m_Factory;

	object.matrix = 0; // ?
	object.row = 0;
	object.col = 0;
}

Field::Field(const Field& object) // конструкотор коп-я
{
	std::cout << "CONSTRUCTOR_COPY" << std::endl;
	this->row = object.row;
	this->col = object.col;
	this->m_Factory = object.m_Factory;

	matrix = new Cage * [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new Cage[col];

	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			matrix[i][j] = object.matrix[i][j];
}
Field::~Field()
{
	DataClear();
}

Field* Field::GetInstance() {
	if (instance == 0) 
		instance = new Field(2, 2); 
	return instance;
}
Field* Field::GetInstance(int row, int col) {
	if (instance != 0) {
		delete instance;
		instance = 0;
	}
	if (instance == 0)
		instance = new Field(row, col);
	return instance;
}

void Field::Print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << matrix[i][j].GetType() << " ";
		}

		std::cout << std::endl;
	}
}

void Field::DataClear()
{
	if (matrix) {
		for (int i = 0; i < row; i++)
			delete[] matrix[i];
	}

	delete[] matrix;
	matrix = 0;
}

void Field::DataCopy(const Field& object)
{
	this->row = object.row;
	this->col = object.col;
	this->m_Factory = object.m_Factory;

	matrix = new Cage * [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new Cage[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = object.matrix[i][j];
		}
	}
}

Field& Field::operator = (const Field& field)
{
	std::cout << "OPERQATOR = COPY" << std::endl;
	DataClear();
	DataCopy(field);

	return *this;
}

Field& Field::operator = (const Field&& field)
{
	std::cout << "OPERQATOR = MOVE" << std::endl;
	DataClear();
	this->row = field.row;
	this->col = field.col;
	this->matrix = field.matrix;
	this->m_Factory = field.m_Factory;

	return *this;
}

void Field::CreateLogic()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			matrix[i][j].ReCage(REG);
		}

	matrix[0][0].ReCage(IN);
	matrix[row - 1][col - 1].ReCage(OUT);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			// пропуск необычных ячеек
			if (matrix[i][j].GetType() != REG) continue;
			// генерируем логику ячейке
			matrix[i][j].SetPlayerLogic(m_Factory->MakePlayerLogic(i, j, this));
		}
}
void Field::SetLogicFactory(IPlayerLogicFactory* factory)
{
	delete m_Factory;
	m_Factory = factory;
	CreateLogic();
}
void Field::Save(std::ostream& os) { // сохранение в файл
	os << row << ' ' << col << std::endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			matrix[i][j].Save(os);
		}
		os << std::endl;
	}
}
void Field::Load(std::istream& is) { // загрузка 
	// удаление старого
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
	
	// читаем размеры
	is >> row;
	is >> col;

	// создаем новую матрицу
	matrix = new Cage * [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new Cage[col];

	// читаем данные матрицы
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) 
			matrix[i][j].Load(is);
}

