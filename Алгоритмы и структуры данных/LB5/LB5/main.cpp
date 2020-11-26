#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;
#define TYPEDEF int

void InputNodes(Tree<TYPEDEF>& t) {
	cout << "Input nodes:" << endl;
	bool repeate;
	TYPEDEF value;
	cout << "Do you want input? ";
	cin >> repeate;
	while (repeate) {
		cout << "new value = ";
		cin >> value;
		t.Add(value);
		cout << "Do you want input? ";
		cin >> repeate;
	}
}

int main() {
	stringstream is("9 7 8 9 4 5 6 1 2 3"); // вначале вводим количество элементов

	//Tree<TYPEDEF> t(cin);
	Tree<TYPEDEF> t(is);

	t.Add(10);
	t.Add(11);
	t.Add(0);

	//printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "tree:\n" << t << endl;
	InputNodes(t);
	cout << "tree:\n" << t << endl;
	TYPEDEF value;
	cout << "Find element: ";
	cin >> value;
	cout << "count of " << value << ": " << t.Count(value) << endl;

	return 0;
}
