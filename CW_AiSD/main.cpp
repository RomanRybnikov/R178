#include <cstdlib>
#include <locale.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.h"

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


int main() {
	//stringstream is("9 9 8 7 6 5 4 3 2 1"); // вначале вводим количество элементов
	stringstream is("5 1 2 3 4 5");
	//stringstream is("9 a b c d e f g h i");
	//stringstream is("");
	//Tree<TYPEDEF> t(cin);
	Tree<TYPEDEF> t;
	is >> t;
	//cin >> t;
	cout << endl << endl;
	//t.Add(7);
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

	return 0;
}
