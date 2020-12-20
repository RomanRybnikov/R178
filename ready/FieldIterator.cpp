#include "FieldIterator.h"
#include <iostream>

using namespace std;

FieldIterator::FieldIterator(Field* field) {
	this->field = field;
	row = 0;
	col = 0;
}

FieldIterator::~FieldIterator() {
}

Cage& FieldIterator::Value() {
	return field->matrix[row][col];
}

bool FieldIterator::Up() {
	if (row <= 0) return false;
	--row;
	OnMove();
	return true;
}
bool FieldIterator::Down() {
	if (row >= field->row-1) return false;
	++row;
	OnMove();
	return true;
}
bool FieldIterator::Left() {
	if (col <= 0) return false;
	--col;
	OnMove();
	return true;
}
bool FieldIterator::Right() {
	if (col >= field->col - 1) return false;
	++col;
	OnMove();
	return true;
}
void FieldIterator::Print() {
	for (int i = 0; i < field->row; i++) {
		for (int j = 0; j < field->col; j++) {
			// выводим крест, если выводим позицию итератора, и выводим поле, в противном случае
			if (i == row && j == col) cout << "x";
			else cout <<field->matrix[i][j].GetType();
			// провел в любом случае
			cout << " ";
		}
		cout << endl;
	}	
}
void FieldIterator::AddListener(IObserver* observer) // добавить наблюдателя
{
	m_Observers.push_back(observer);
}
void FieldIterator::RemoveListener(IObserver* observer) // удалить наблюдателя
{
	m_Observers.remove(observer);
}
void FieldIterator::OnMove() // оповещение наблюдателей
{
	for (auto i = m_Observers.begin(); i != m_Observers.end(); ++i)
		(*i)->OnMove(this);
}
void FieldIterator::Save(std::ostream& os) {
	os << row << ' ' << col << ' ';
}
void FieldIterator::Load(std::istream& is) {
	is >> row >> col;
}
