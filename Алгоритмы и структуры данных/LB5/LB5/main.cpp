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
	//stringstream is("4 2 1 3 6 5 7");
	//stringstream is("4 2 6 1 3 5 6 7 8");
	stringstream is("1 2 3 4 5 6 7 8 9");
	//stringstream is("");

	//Tree<int> t(cin); 
	Tree<TYPEDEF> t(is);

	//printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "res:\n" << t << endl;
	InputNodes(t);
	cout << "res:\n" << t << endl;
	TYPEDEF value;
	cout << "Find element: ";
	cin >> value;
	cout << "count of " << value << ": " << t.Count(value) << endl;

	return 0;
}
