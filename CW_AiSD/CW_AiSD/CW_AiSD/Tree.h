#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define OSTREAM if(os) (*os)

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
			OSTREAM << "старт поиска вхождений " << value << " в поддереве " << m_Value << std::endl;
			if (value == m_Value) {
				OSTREAM << "в поддереве " << m_Value << " найдено вхождение" << std::endl;
				count = 1;
			}
			if (m_Left) count += m_Left->Count(value); // если слева есть узел то прибавляем найденное число слева
			if (m_Right) count += m_Right->Count(value); // для права
			OSTREAM << "в поддереве " << m_Value << " найдено " << count << " вхождений " << value << std::endl;
			return count;
		}
		int Count() {
			return GetCount(this);
		}
		Node* GetTop() {
			auto top = this;
			while (top->m_Parent) top = top->m_Parent;
			return top;
		}

		static Node* MakeTree(T* arr, int startIndex, int endIndex) { // создает дерево из сортированного массива. Индексы задаются включительные
			// ограничитель
			if (endIndex < startIndex) return 0;
			// получаем индекс центра
			int n = endIndex - startIndex + 1;
			int centerIndex = startIndex + n / 2;
			// создаем узел со значением в центре
			auto node = new Node(arr[centerIndex]);
			// формируем левое поддерево
			node->m_Left = MakeTree(arr, startIndex, centerIndex - 1);
			// формируем правое поддерево
			node->m_Right = MakeTree(arr, centerIndex + 1, endIndex);
			// выводим результат
			return node;
		}
		static Node* MakeTree1(T* arr, int startIndex, int n) { // создает дерево из сортированного массива. Индексы задаются включительные
			// ограничитель
			if (n <= 0) {
				//OSTREAM << "передан нуливой диапазон значений массива - элемент не формируем" << std::endl;
				return 0;
			}
			// получаем индекс центра
			int nl = n / 2;
			int nr = n - nl - 1;
			// создаем узел со значением в центре

			OSTREAM << "начинаем формировать узел дерева из массива начало = " << startIndex << ", всего = " << n << ", nl = " << nl << ", nr = " << nr << std::endl;

			auto node = new Node(arr[startIndex + nl]);
			OSTREAM << "создан узел со значением " << arr[startIndex + nl] << std::endl;

			// формируем левое поддерево
			node->m_Left = MakeTree1(arr, startIndex, nl);
			if (node->m_Left) {
				OSTREAM << "задаем сформировавшийся узел влево на родительском узле" << std::endl;
				OSTREAM << "Текущее дерево:" << std::endl;
				if (os)PrintUstup(node->GetTop(), *os, 0);
			}

			// формируем правое поддерево
			node->m_Right = MakeTree1(arr, startIndex + nl + 1, nr);
			if (node->m_Right) {
				OSTREAM << "задаем сформировавшийся узел вправо на родительском узле" << std::endl;
				OSTREAM << "Текущее дерево:" << std::endl;
				if(os)PrintUstup(node->GetTop(), *os, 0);
			}
			OSTREAM << std::endl;
			// выводим результат
			OSTREAM << "сформирован узел дерева из массива начало=" << startIndex << ", всего=" << n << std::endl;
			if (!node->m_Left && !node->m_Right) {
				OSTREAM << "который является листом со значением: " << arr[startIndex + nl] << std::endl;
				if(os)PrintUstup(node->GetTop(), *os, 0);
			}
			OSTREAM << std::endl;
			return node;
		}

		static void Add(Node* node, T* arr, int& index) {// добавляет в массив значения всего дерева, начиная с индекса index
			if (!node) return;
			OSTREAM << "добавляем в массив значение " << node->m_Value << std::endl;
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

		static std::ostream& PrintUstup(Node* node, std::ostream& os, unsigned int len) {
			// вывод отступа
			for (int i = 0; i < len; i++) os << '-';
			// ограничитель
			if (!node) return  os << "*" << std::endl;
			// вывод значения
			os << node->m_Value << std::endl;
			// ограничитель двойных пустых потомков
			if (!node->m_Left && !node->m_Right) return os;
			// лево
			PrintUstup(node->m_Left, os, len + 1);
			// право
			PrintUstup(node->m_Right, os, len + 1);
			// вывод результата
			return os;
		}
		static int GetHeight(Node* node, int height) {
			if (!node) return height; // если узла нет
			++height; // узел прибавляет высоту
			if (!node->m_Left && !node->m_Right) return height; // лист
			return std::max(GetHeight(node->m_Left, height), GetHeight(node->m_Right, height)); // если не лист
		}
	};

	Node* m_Root;

	void Parse(std::istream& is) // парсит входной поток и формирует из него дерево (юзается для оператора ввода)
	{
		OSTREAM << "Начинаем обрабатывать поток данных" << std::endl;
		OSTREAM << "**********************************" << std::endl << std::endl;
		// очистка
		delete m_Root;

		// читаем количество
		int count;
		is >> count;
		OSTREAM << "прочитано количество данных в потоке = " << count << std::endl;
		//while(count < 0)
		if (count == 0) {
			OSTREAM << "данных нет - парсить нечего" << std::endl;
			return;
		}

		// создаем массив элементов
		OSTREAM << "создаем массив данных arr из " << count << " элементов" << std::endl;
		T* arr = new T[count];

		// читаем все значения
		for (int i = 0; i < count; ++i) {
			// читаем значение
			OSTREAM << "читаем значение" << std::endl;
			T value;
			is >> value;
			// вставка в массив
			OSTREAM << "arr[" << i << "] = " << value << std::endl;
			arr[i] = value;
		}
		OSTREAM << std::endl;
		// сортировка массива
		Sort(arr, count);
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl << std::endl;
		OSTREAM << std::endl;

		OSTREAM << "______________________" << std::endl;
		// создаем корневой узел из массива
		m_Root = Node::MakeTree1(arr, 0, count);
		OSTREAM << std::endl;
		OSTREAM << "______________________" << std::endl;

		OSTREAM << "задаем на корень дерева сформировавшийся узел" << std::endl;
		// удаляем служебный массив
		OSTREAM << "удаляем служебный массив arr" << std::endl << std::endl;
		OSTREAM << "**********************************" << std::endl << std::endl;

		delete[] arr;
	}
	void Sort(T* arr, int count) {
		OSTREAM << "сортировка массива" << std::endl;
		for (int i = 0; i < count - 1; ++i) {
			int imin = i;
			for (int j = i + 1; j < count; ++j)
				if (arr[j] < arr[imin]) imin = j;
			if (imin != i) std::swap(arr[i], arr[imin]);
		}
	}
public:
	static std::ostream* os;

	Tree() {
		m_Root = 0;
	}

	int Count(T value) { // сколько раз входит значение в дерево
		OSTREAM << "поиск количества вхождений элемента " << value << std::endl;
		OSTREAM << "текущее дерево:" << std::endl;
		OSTREAM << *this << std::endl;
		if (!m_Root) {
			OSTREAM << "корня дерева нет - элементов 0" << std::endl;
			return 0;
		}
		return m_Root->Count(value);
	}
	int Count() { // сколько всего значений в дереве
		if (!m_Root) return 0;
		return m_Root->Count();
	}
	int GetHeight() {
		return Node::GetHeight(m_Root, 0);
	}

	void Add(T value) {
		OSTREAM << "+++++++++++++++++++++++++++" << std::endl << std::endl;
		OSTREAM << "Начинаем добавлять элемент " << value << " в дерево" << std::endl;
		OSTREAM << "текущее дерево:" << std::endl;
		OSTREAM << *this << std::endl;
	
		// создаем массив значений
		auto count = Count() + 1;
		OSTREAM << "всего элементов в дереве: count=" << count - 1 << std::endl << std::endl;
		auto arr = new T[count];
		OSTREAM << "создаем массив arr размером на 1 больше: count=" << count << std::endl << std::endl;

		// вставка в массив всего существующего
		int index = 0;
		OSTREAM << "начинаем заполнять массив существующими значениями" << std::endl << std::endl;
		Node::Add(m_Root, arr, index);

		OSTREAM << std::endl << std::endl;
		// вставка элемента
		arr[index] = value;
		OSTREAM << "вставка добавляемого элемента " << value << " в конец массива" << std::endl << std::endl;
		OSTREAM << "получили массив: " << std::endl;
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl;

		OSTREAM << std::endl;
		// сортируем массив
		Sort(arr, count);
		OSTREAM << std::endl;

		OSTREAM << "отсортированный массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl << std::endl;

		// удаляем корень
		OSTREAM << "удаляем существующий корень дерева" << std::endl;
		delete m_Root;

		// создаем корневой узел из массива
		OSTREAM << "начинаем формировать новый корень дерева" << std::endl;
		m_Root = Node::MakeTree1(arr, 0, count);
		OSTREAM << "задаем на корень дерева сформировавшийся узел" << std::endl << std::endl;
		OSTREAM << "удаляем служебный массив arr" << std::endl;
		OSTREAM << "+++++++++++++++++++++++++++" << std::endl << std::endl;
		// удаляем служебный массив
		delete[] arr;
	}
	void Remove(T value) {
		// создаем массив значений
		OSTREAM << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl << std::endl;
		OSTREAM << "Начинаем удалять элемент " << value << " из дерева" << std::endl;
		OSTREAM << "текущее дерево:" << std::endl;
		OSTREAM << *this << std::endl;
		auto count = Count();
		auto arr = new T[count];

		// вставка в массив всего существующего
		int index = 0;
		OSTREAM << std::endl;
		Node::Add(m_Root, arr, index);
		OSTREAM << std::endl;
		OSTREAM << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl << std::endl;

		// ищем индекс удаляемого элемента
		OSTREAM << "ищем индекс удаляемого элемента" << std::endl;
		index = -1;
		for (int i = 0; i < count; ++i) {
			if (arr[i] == value) {
				index = i;
				break;
			}
		}
		if (index < 0) {
			OSTREAM << "удаляемый элемент не найден - удалять нечего" << std::endl;
			delete[] arr;
			return;
		}

		// удаление элемента
		OSTREAM << "удаляем элемент в позиции: " << index << std::endl;
		for (int i = index; i < count - 1; ++i)
			arr[i] = arr[i + 1];
		--count;

		OSTREAM << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl;

		// сортируем массив
		Sort(arr, count);

		OSTREAM << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			OSTREAM << arr[i] << ' ';
		OSTREAM << std::endl;

		// удаляем корень
		delete m_Root;

		// создаем корневой узел из массива
		m_Root = Node::MakeTree1(arr, 0, count - 1);
		OSTREAM << "удаляем служебный массив arr" << std::endl << std::endl;
		OSTREAM << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
		// удаляем служебный массив
		delete[] arr;
	}

	template<typename T1>
	friend std::ostream& operator << (std::ostream& os, Tree<T1>& t);
	template<typename T1>
	friend std::istream& operator >> (std::istream& is, Tree<T1>& t);
};

template<typename T1>
std::ostream& operator<<(std::ostream& os, Tree<T1>& t) {
	if (!t.m_Root) return os << "()";
	//return t.m_Root->Print(os);
	Tree<T1>::Node::PrintUstup(t.m_Root, os, 0);
	os << "Count=" << t.m_Root->Count();
	return os;
}
template<typename T1>
std::istream& operator >> (std::istream& is, Tree<T1>& t) {
	t.Parse(is);
	return is;
}
template<typename T>
std::ostream* Tree<T>::os = 0;
