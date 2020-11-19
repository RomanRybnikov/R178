#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;
#define TYPEDEF int

void InputNodes(Tree<TYPEDEF> &t) {
	cout << "Input nodes:" << endl;
	bool repeate;
	TYPEDEF value;
	cout << "input=";
	cin >> repeate;
	while (repeate) {
		cout << "value=";
		cin >> value;
		t.Add(value);
		cout << "repeate=";
		cin >> repeate;
	}
}

int main(){
	setlocale(0, "RUS");
	//stringstream is("4 2 1 3 6 5 7");
	stringstream is("4 2 6 1 3 5 6");

	//Tree<int> t(cin); 
	Tree<TYPEDEF> t(is);
    
    printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "\nres: " << t << endl;
	InputNodes(t);
	cout << "\nres: " << t << endl;
	TYPEDEF value;
	cout << "value=";
	cin >> value;
	cout << "count of " << value << ": " << t.Count(value) << endl;

	//system("PAUSE");
	return 0;
}
