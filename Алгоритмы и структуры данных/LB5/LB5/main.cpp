#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

using namespace std;

int main(){
	setlocale(0, "RUS");
	stringstream is("4 2 1 3 6 5 7");

	//Tree<int> t(cin); 
	Tree<int> t(is);
    
    printf("На вход подается заранее идеальносбалансированное дерево 4 2 1 3 6 5 7");
	cout << "\nres: " << t << endl;

	//system("PAUSE");
	return 0;
}
