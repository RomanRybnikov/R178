#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;
#define TYPEDEF char

void InputNodes(Tree<TYPEDEF>& t) {
	cout << "Output items" << endl << endl;
	bool repeate;
	TYPEDEF value;
	cout << "Do you want to input items? ";
	cin >> repeate;
	while (repeate) {
		cout << "New item = ";
		cin >> value;
		
		t.Add(value);
		cout << "Do you want to input item? ";
		cin >> repeate;
	}
}

int main() {
	//setlocale(0, "rus");
	//stringstream is("9 9 8 7 6 5 4 3 2 1"); // вначале вводим количество элементов
	//stringstream is("9 11 10 9 8 7 6 5 4 3");
	//stringstream is("9 a b c d e f g h i");
	stringstream is("0");
	//Tree<TYPEDEF> t(cin);
	Tree<TYPEDEF> t(is);	

	t.Add('a');
	t.Add('b');
	t.Add('c');
	t.Add('d');
	t.Add('e');
	t.Add('f');
	t.Add('g');
	t.Add('h');
	t.Add('i');

	//printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "tree:\n" << t << endl;
	InputNodes(t);
	cout << "tree:\n" << t << endl;
	TYPEDEF value;
	cout << "Find item ";
	cin >> value;
	cout << "items count " << value << ": " << t.Count(value) << endl;

	return 0;
}
