#pragma once
#include <iostream>
#include <cstdlib>

template<typename T>
class Tree
{
	class Node {
		T m_Value;
		Node* m_Parent;
		Node* m_Left;
		Node* m_Right;

		void AddLeft(T value) {
			if (m_Left) {
				m_Left->Add(value);
				return;
			}
			m_Left = new Node(value);
			m_Left->m_Parent = this;
		}
		void AddRight(T value) {
			if (m_Right) {
				m_Right->Add(value);
				return;
			}
			m_Right = new Node(value);
			m_Right->m_Parent = this;
		}
		static int GetCount(Node* node) {
			if (!node) return 0;// если нет узла то 0

			int count = 1; // если узел не 0 то 1 элемент точно есть
			count += GetCount(node->m_Left); // прибавка того что слева
			count += GetCount(node->m_Right); // прибавка что там справа

			return count; // выводим сумму
		}

	public:
		Node(T value) {
			m_Value = value;
			m_Parent = 0;
			m_Left = 0;
			m_Right = 0;
		}

		void Add(T value) {
			if (value < m_Value) AddLeft(value);
			else AddRight(value);
		}
		int Count(T value) { // возвращает количество элементов в дереве, представленном текущим узлом
			int count = 0;
			if (value == m_Value) count = 1;
			if (m_Left) count += m_Left->Count(value); // если слева есть узел то прибавляем найденное число слева
			if (m_Right) count += m_Right->Count(value); // для права
			return count;
		}
		int Count() {
			return GetCount(this);
		}
		
		static Node* MakeTree(T* arr, int startIndex, int endIndex) { // создает дерево из сортированного массива. Индексы задаются включительные
			// ограничитель
			if (endIndex < startIndex) return 0;
			// получаем индекс центра
			int centerIndex = (endIndex + startIndex) / 2;
			// создаем узел со значением в центре
			auto node = new Node(arr[centerIndex]);		
			// формируем левое поддерево
			node->m_Left = MakeTree(arr, startIndex, centerIndex - 1);
			// формируем правое поддерево
			node->m_Right = MakeTree(arr, centerIndex + 1, endIndex);
			// выводим результат
			return node;
		}
		static void Add(Node* node, T* arr, int& index) {// добавляет в массив значения всего дерева, начиная с индекса index
			if (!node) return;
			arr[index++] = node->m_Value;
			Add(node->m_Left, arr, index);
			Add(node->m_Right, arr, index);
		}

		std::ostream& Print(std::ostream& os) {
			os << '(' << m_Value << ' ';
			if (m_Left) m_Left->Print(os);
			else os << "()";
			if (m_Right) m_Right->Print(os);
			else os << "()";
			os << ')';
			return os;
		}
		std::ostream& PrintUstup(std::ostream& os, unsigned int len) {
			// вывод отступа
			for (int i = 0; i < len; i++) os << '-';
			// вывод значения
			os << m_Value << std::endl;
			// лево
			if (m_Left) m_Left->PrintUstup(os, len + 1);
			// право
			if (m_Right) m_Right->PrintUstup(os, len + 1);
			// вывод результата
			return os;
		}
	};

	Node* m_Root;

	void Parse(std::istream& is) // парсит входной поток и формирует из него дерево (юзается для оператора ввода)
	{
		// очистка
		delete m_Root;

		// читаем количество
		int count;
		is >> count;
        //while(count < 0)
		if (count == 0) return;
        

		// создаем массив элементов
		T* arr = new T[count];

		// читаем все значения
		for (int i = 0; i < count;++i) {
			// читаем значение
			T value;
			is >> value;
			// вставка в массив
			arr[i] = value;
		}

		// сортировка массива
		Sort(arr, count);

		// создаем корневой узел из массива
		m_Root = Node::MakeTree(arr, 0, count - 1);
	}
	void Sort(T* arr, int count) {
		for (int i = 0; i < count - 1; ++i) {
			int imin = i;
			for (int j = i + 1; j < count; ++j)
				if (arr[j] < arr[imin]) imin = j;
			if (imin != i) std::swap(arr[i], arr[imin]);
		}
	}
public:
	Tree(std::istream& is) {
		m_Root = 0;
		Parse(is);
	}

	int Count(T value) { // сколько раз входит значение в дерево
		if (!m_Root) return 0;
		return m_Root->Count(value);
	}
	int Count() { // сколько всего значений в дереве
		if (!m_Root) return 0;
		return m_Root->Count();
	}
	void Add(T value) {
		// создаем массив значений
		auto count = Count() + 1;
		auto arr = new T[count];

		// вставка в массив всего существующего
		int index = 0;
		Node::Add(m_Root, arr, index);

		// вставка элемента
		arr[index] = value;

		// сортируем массив
		Sort(arr, count);

		// удаляем корень
		delete m_Root;

		// создаем корневой узел из массива
		m_Root = Node::MakeTree(arr, 0, count - 1);
	}

	template<typename T1>
	friend std::ostream& operator << (std::ostream& os, Tree<T1>& t);
};

template<typename T1>
std::ostream& operator<<(std::ostream& os, Tree<T1>& t) {
	if (!t.m_Root) return os << "()";
	//return t.m_Root->Print(os);
	t.m_Root->PrintUstup(os, 0);
	os << "Count=" << t.m_Root->Count();
	return os;
}

