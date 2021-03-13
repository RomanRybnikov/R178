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
bool PutItem(Item item, bool** table, int N, std::list<Item>& list, std::list<Item>& res, int nMax); // попытка добавить еще один итем в текущую раскладку
void Add(bool** table, std::list<Item>& list, Item item); // добавляет указанный обрезок в раскладку
void RemoveLast(bool** table, std::list<Item>& list); // удаляет последний элемент из раскладки
void ShowTable(bool** table, int N); // вывод таблицы на экран (для дебага)
bool IsFull(bool** table, int N); // заполнена ли таблица
bool CanAdd(bool** table, int N, Item item); // можно ли добавить указанный итем в таблицу
bool GetFirstEmpty(bool** table, int N, Position &position); // возвращает первую свободную позицию

int main() {
	// ввод данных
	int N;
#if _DEBUG
	N = 8;
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

	// поиск результата (вставкой всех возможных плиток вначало)
	for (int i = 1; i < N - 1; ++i) {
		int nMax = N - i;
		PutItem(Item(0, 0, i), table, N, list, res, nMax);
	}

	// удаляем доску
	for (auto i = 0; i < N; ++i) delete[] table[i];
	delete[] table;

	// вывод результата
	return res;
}
bool PutItem(Item item, bool** table, int N, std::list<Item>& list, std::list<Item>& res,int nMax) // попытка добавить еще один итем в текущую раскладку
{
	// ограничитель
	if (IsFull(table, N) || !CanAdd(table, N, item)) return false;

	// вставка итема
	Add(table, list, item);

	// берем индекс первого пустого места
	Position position;
	if (GetFirstEmpty(table, N, position)) {
		// поиск макс размера // todo это оптимизация, которую нужно доделать
		if (N - item.w < nMax) 
			nMax = N - item.w;
		// делаем вставку всех итемов, которые возможны
		for (int i = 1; i < nMax; ++i) {
			PutItem(Item(position.x, position.y, i), table, N, list, res, nMax);
		}
	}
	else { // если попали сюда, то доска стала заполненой - проверяем результат
		if (list.size() < res.size() || res.size() == 0) 
			res = list;
	}

	// удаление итема
	RemoveLast(table, list);

	return true;

	// тест вставки
	/*Add(table, list, Item(0, 0, 2));
	Add(table, list, Item(3, 3, 3));
	Add(table, list, Item(0, 3, 1));
	ShowTable(table, N);*/
}
bool GetFirstEmpty(bool** table, int N, Position& position) // возвращает первую свободную позицию
{
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			if (!table[x][y]) {
				position.x = x;
				position.y = y;
				return true;
			}
	return false;
}
bool CanAdd(bool** table, int N, Item item) // можно ли добавить указанный итем в таблицу
{
	if (item.x < 0 || item.x + item.w > N) return false;
	if (item.y < 0 || item.y + item.w > N) return false;

	for (int x = item.x; x < item.x + item.w; ++x)
		for (int y = item.y; y < item.y + item.w; ++y)
			if(table[x][y]) return false;
	return true;
}
bool IsFull(bool** table, int N) // заполнена ли таблица
{
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			if (!table[x][y]) return false;
	return true;
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
	auto item = list.back();
	list.pop_back();

	// чистим таблицу
	for (int x = item.x; x < item.x + item.w; ++x)
		for (int y = item.y; y < item.y + item.w; ++y)
			table[x][y] = false;
}
void ShowTable(bool** table, int N) // вывод таблицы на экран (для дебага)
{
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x)
			std::cout << (int)table[x][y];
		std::cout << std::endl;
	}
}