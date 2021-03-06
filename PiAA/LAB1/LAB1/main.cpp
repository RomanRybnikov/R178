#include <iostream>
#include <conio.h>
#include <list>

struct Position { // позиция на столе
	int x;
	int y;
};

struct Item {	// один элемент столешницы
	int x;	// координата x
	int y;	// координата y
	int w;	// размер обрезка

	Item(int x, int y, int w) {
		this->x = x;
		this->y = y;
		this->w = w;
	}

	friend std::ostream& operator <<(std::ostream& os, Item item);
};

std::list<Item> GetRes(int N); // поиск результата
void PutItem(bool** table, int N, std::list<Item>& list, std::list<Item>& res); // попытка добавить еще один итем в текущую раскладку
void Add(bool** table, std::list<Item>& list, Item item); // добавляет указанный обрезок в раскладку
void RemoveLast(bool** table, std::list<Item>& list); // удаляет последний элемент из раскладки
void ShowTable(bool** table, int N); // вывод таблицы на экран (для дебага)

int main() {
	// ввод данных
	int N;
#if _DEBUG
	N = 7;
#else
	std::cout << "N=";
	std::cin >> N;
#endif

	// расчет
	auto res = GetRes(N);
	// вывод результата
	std::cout << res.size() << std::endl;
	for (auto i = res.begin(); i!=res.end(); ++i)
		std::cout << *i << std::endl;

	_getch();
	return 0;
}

std::ostream& operator <<(std::ostream& os, Item item) {
	return os << item.x + 1 << ' ' << item.y + 1 << ' ' << item.w; // +1 тк расчер ведем в системе координат от 0 а на экран требуют от 1
}
std::list<Item> GetRes(int N) { // решает задачу
	// получаем вариант решения
	std::list<Item> list;	// текущий список выложенных квадратов
	std::list<Item> res;	// результат
	// создаем двумерный массив, описывающий доску
	bool** table = new bool* [N];
	for (auto i = 0; i < N; ++i) {
		table[i] = new bool[N];
		for (auto j = 0; j < N; ++j)
			table[i][j] = false;
	}

	// поиск результата
	list.push_back(Item(1, 1, 1));
	PutItem(table, N, list, res);

	// удаляем доску
	for (auto i = 0; i < N; ++i) delete[] table[i];
	delete[] table;

	// вывод результата
	return res;
}
void PutItem(bool** table, int N, std::list<Item>& list, std::list<Item>& res) // попытка добавить еще один итем в текущую раскладку
{
	// берем первое свободное место
	/*Position emptyPos;
	if (!GetEmpty(table, emptypos)) { // если пустого места нет то квадрат заполнен
		// если текущая раскладка лучшая то запоминаем ее
		if (list.size() < res.size() || res.size() == 0) res = list;
		// запоминаем размер последнего элемента из раскладки
		auto lastSize = list.back().w;
		// удаляем последний элемент из раскладки
		RemoveLast(table, list);
	}*/

	// тест вставки
	Add(table, list, Item(0, 0, 2));
	Add(table, list, Item(3, 3, 3));
	Add(table, list, Item(0, 3, 1));
	ShowTable(table, N);

	// тест удаления
}
void Add(bool** table, std::list<Item>& list, Item item) // добавляет указанный обрезок в раскладку
{
	// добавляем в список
	list.push_back(item);

	// в таблицу
	for (int x = item.x; x < item.x + item.w; ++x)
		for (int y = item.y; y < item.y + item.w; ++y)
			table[x][y] = true;
}
void RemoveLast(bool** table, std::list<Item>& list) // удаляет последний элемент из раскладки
{
	// берем последний элемент
	auto last = list.back();
	list.pop_back();

	// чистим таблицу
	for (int i = last.x; i < last.w; ++i)
		for (int j = last.y; j < last.w; ++j)
			table[i][j] = false;
}
void ShowTable(bool** table, int N) // вывод таблицы на экран (для дебага)
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x)
			std::cout << (int)table[x][y];
		std::cout << std::endl;
	}
}