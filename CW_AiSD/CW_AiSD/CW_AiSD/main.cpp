#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"
#include <math.h>

using namespace std;
#define TYPEDEF int

void InputNodes(Tree<TYPEDEF>& t) {
	//cout << "Output items" << endl << endl;
	cout << "Добавление элементов (0 - нет, 1 - да)" << endl << endl;
	bool repeate;
	TYPEDEF value;
	//cout << "Do you want to input items? ";
	cout << "Хотите ввести новый элемент = ";
	cin >> repeate;
	while (repeate) {
		//cout << "New item = ";
		cout << "Новый элемент = ";
		cin >> value;

		t.Add(value);
		//cout << "Do you want to input items? ";
		cout << "Хотите ввести новый элемент? ";
		cin >> repeate;
	}
}

void RemoveNodes(Tree<TYPEDEF>& t) {
	bool repeate;
	TYPEDEF value;
	//cout << "Do you want to input items? ";
	cout << "Хотите удалить элемент? (0 - нет, 1 - да): " << endl;
	cin >> repeate;
	while (repeate) {
		//cout << "New item = ";
		cout << "Удаляемый элемент = ";
		cin >> value;

		t.Remove(value);
		//cout << "Do you want to input items? ";
		cout << "Хотите удалить элемент? (0 - нет, 1 - да): ";
		cin >> repeate;
	}
}

void TestHeigth(int n) {
	cout << "n=" << n << endl;
	Tree<TYPEDEF> t;
	for (int i = 0; i < n; ++i) t.Add(i);
	//cout << t << endl;
	cout << "Height=" << t.GetHeight() << endl;

	// считаем теоретическую высоту
	auto h = log2(n + 1);
	//if (h - (int)h > 0) ++h; // округление в большую сторону
	cout << "Height theory=" << round(h) << endl;
}

void Test1() {
	//stringstream is("9 9 8 7 6 5 4 3 2 1"); // вначале вводим количество элементов
	stringstream is("5 1 2 3 4 5");
	//stringstream is("9 a b c d e f g h i");
	//stringstream is("");
	//Tree<TYPEDEF> t(cin);
	Tree<TYPEDEF> t;
	Tree<TYPEDEF>::os = &std::cout; // задаем выходной поток для демонстрации
	is >> t;
	//cin >> t;
	cout << endl << endl;
	//t.Add(7);
	t.Count(7);
	InputNodes(t);
	RemoveNodes(t);
	cout << endl << endl;
	/*
	t.Remove(1);
	cout << endl << endl;
	t.Count(7);
	*/
	/*
	t.Add('a');
	t.Add('b');
	t.Add('c');
	t.Add('d');
	t.Add('e');
	t.Add('f');
	t.Add('g');
	t.Add('h');
	t.Add('i');
	 */

	 /*t.Remove(11);
	 t.Remove(3);
	 t.Remove(4);
	 t.Remove(5);
	 t.Remove(7);
	 t.Remove(8);
	 t.Remove(9);
	 t.Remove(11);
	 t.Remove(10);
	 t.Remove(10);
	 t.Remove(6);*/

	 //cout << "Входные данные:\n" << "11 10 9 8 7 6 5 4 3" << endl << endl;
	cout << "tree:\n" << t << endl << endl;
	TYPEDEF value;
	cout << "Find item ";
	//cout << "Какой найти элемент?: ";
	cin >> value;
	cout << "items count " << value << ": " << t.Count(value) << endl;
	//cout << "Количество найденных элементов " << value << ": " << t.Count(value) << endl;
}

int main() {
	setlocale(0, "rus");
	//Test1();
	TestHeigth(0);
	TestHeigth(1);
	TestHeigth(5);
	TestHeigth(10);
	TestHeigth(70);
	TestHeigth(81);
	TestHeigth(100);

	return 0;
}
