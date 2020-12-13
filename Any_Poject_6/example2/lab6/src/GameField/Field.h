#ifndef FIELD_H
#define FIELD_H

#include "FieldIterator.h"
#include "iostream"
#include "Cell.h"
#include "../Items/Key/ItemKeyFactory.h"
#include "../Items/Chest/ItemChestFactory.h"
#include "../Items/Heart/ItemHeartFactory.h"
#include <cstdlib>
#include <time.h> 




class Field
{
private:
	//Статик поле для Singletone
	static Field* instance;

	//Данные о игровом поле
	int height, width;
	Cell** field = nullptr;

	//Перегрузка конструктора присваивания и конструктора присваивания перемещением
	Field() = default;
	Field(const Field& otherField);
	Field(Field&& otherField);

	//Перегрузка операторов присваивания и присваивания перемещением
	Field& operator=(const Field& otherField);
	Field& operator=(Field&& otherField);

	//Функция для очистки памяти 
	void destroy();


	//Функция генерации лабиринта
	void CreateMaze();
public:

	//Функции получения полей класса
	void GetSize(int& height, int& width);
	Cell** GetField();

	~Field();

	//Функции для создания итератора
	FieldIterator begin();
	FieldIterator end();

	//Функция для инициализации поля
	void DefineField();

	//Функция для создания объекта класса с использованием Singletone
	static Field* GetInstance();
};

#endif