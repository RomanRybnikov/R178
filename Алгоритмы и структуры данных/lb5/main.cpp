#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree_испр.h"

using namespace std;
#define TYPEDEF int

void InputNodes(Tree<TYPEDEF>& t) {
    cout << "Ввод элементов" << endl << endl;
	bool repeate;
	TYPEDEF value;
	cout << "Хотите ввести новый элемент? ";
	cin >> repeate;
	while (repeate) {
		cout << "Новый элемент = ";
		cin >> value;
        
		t.Add(value);
		cout << "Хотите ввести новый элемент? ";
		cin >> repeate;
	}
}

int main() {
	//stringstream is("9 9 8 7 6 5 4 3 2 1"); // вначале вводим количество элементов
    stringstream is("9 11 10 9 8 7 6 5 4 3");
	//Tree<TYPEDEF> t(cin);
	Tree<TYPEDEF> t(is);

	

	//printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "tree:\n" << t << endl;
	InputNodes(t);
	cout << "tree:\n" << t << endl;
	TYPEDEF value;
	cout << "Найти элемент ";
	cin >> value;
	cout << "кол-во эл-тов " << value << ": " << t.Count(value) << endl;

	return 0;
}
