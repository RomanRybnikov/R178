#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Field.h"
#include <list>

class FieldIterator { // итаратор
	//class IObserver;
	Field* field;	// поле
	int row, col;	// позиция (строка и столбец)

	
	void OnMove(); // оповещение наблюдателей
public:
	class IObserver { // наблюдатель за итератором
	public:
		virtual void OnMove(FieldIterator* iterator) = 0;
	};
    std::list<IObserver*> m_Observers; // наблюдатели
	FieldIterator(Field* field);
	~FieldIterator();

	bool Up();
	bool Down();
	bool Left();
	bool Right();
	int GetCol() { return col; }
	int GetRow() { return row; }


	void AddListener(IObserver *observer); // добавить наблюдателя
	void RemoveListener(IObserver* observer); // удалить наблюдателя
	void Save(std::ostream& os);
	void Load(std::istream& is);

	Cage& Value();	// поступ к элементу (ячейке)

	void Print();	// вывод на экран текущего состояния итератора (поле и крест, где стоит итератор)
};

#endif
