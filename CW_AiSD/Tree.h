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
			std::cout << "старт поиска вхождений " << value << " в поддереве " << m_Value << std::endl;
			if (value == m_Value) { 
				std::cout << "в поддереве " << m_Value << " найдено вхождение" << std::endl;
				count = 1;
			}
			if (m_Left) count += m_Left->Count(value); // если слева есть узел то прибавляем найденное число слева
			if (m_Right) count += m_Right->Count(value); // для права
			std::cout << "в поддереве " << m_Value << " найдено " << count << " вхождений " << value << std::endl;
			return count;
		}
		int Count() {
			return GetCount(this);
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
				//std::cout << "передан нуливой диапазон значений массива - элемент не формируем" << std::endl;
				return 0;
			}
			// получаем индекс центра
			int nl = n / 2;
			int nr = n - nl - 1;
			// создаем узел со значением в центре
            
            std::cout << "начинаем формировать узел дерева из массива начало = " << startIndex << ", всего = " << n << ", nl = " << nl << ", nr = " << nr << std::endl;
            
			auto node = new Node(arr[startIndex + nl]);
            
			// формируем левое поддерево
			node->m_Left = MakeTree1(arr, startIndex, nl);
            if (node->m_Left) std::cout << "задаем сформировавшийся узел влево на родительском узле" << std::endl;
            
			// формируем правое поддерево
			node->m_Right = MakeTree1(arr, startIndex + nl + 1, nr);
			if (node->m_Right) std::cout << "задаем сформировавшийся узел вправо на родительском узле" << std::endl;
            std::cout << std::endl;
			// выводим результат
			std::cout << "сформирован узел дерева из массива начало=" << startIndex << ", всего=" << n << std::endl;
			return node;
		}
        
		static void Add(Node* node, T* arr, int& index) {// добавляет в массив значения всего дерева, начиная с индекса index
			if (!node) return;
			std::cout << "добавляем в массив значение " << node->m_Value << std::endl;
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
	};

	Node* m_Root;

	void Parse(std::istream& is) // парсит входной поток и формирует из него дерево (юзается для оператора ввода)
	{
        std::cout << "Начинаем обрабатывать поток данных" << std::endl;
        std::cout << "**********************************" << std::endl << std::endl;
		// очистка
		delete m_Root;

		// читаем количество
		int count;
		is >> count;
        std::cout << "прочитано количество данных в потоке = " << count << std::endl;
		//while(count < 0)
		if (count == 0) {
			std::cout << "данных нет - парсить нечего" << std::endl;
			return; 
		}

		// создаем массив элементов
        std::cout << "создаем массив данных arr из " << count << " элементов" << std::endl;
		T* arr = new T[count];

		// читаем все значения
		for (int i = 0; i < count; ++i) {
			// читаем значение
            std::cout << "читаем значение" << std::endl;
			T value;
			is >> value;
			// вставка в массив
			std::cout << "arr[" << i << "] = " << value << std::endl;
			arr[i] = value;
		}
        std::cout << std::endl;
		// сортировка массива
		Sort(arr, count);
        for (int i = 0; i < count; ++i)
            std::cout << arr[i] << ' ';
        std::cout << std::endl << std::endl;
        std::cout << std::endl;
        
        std::cout << "______________________" << std::endl;
		// создаем корневой узел из массива
		m_Root = Node::MakeTree1(arr, 0, count);
        std::cout << std::endl;
        std::cout << "______________________" << std::endl;
        
		std::cout << "задаем на корень дерева сформировавшийся узел" << std::endl;
		// удаляем служебный массив
        std::cout << "удаляем служебный массив arr" << std::endl << std::endl;
        std::cout << "**********************************" << std::endl << std::endl;
        
		delete[] arr;
	}
	void Sort(T* arr, int count) {
		std::cout << "сортировка массива" << std::endl;
		for (int i = 0; i < count - 1; ++i) {
			int imin = i;
			for (int j = i + 1; j < count; ++j)
				if (arr[j] < arr[imin]) imin = j;
			if (imin != i) std::swap(arr[i], arr[imin]);
		}
	}
public:
	Tree() {
		m_Root = 0;
	}

	int Count(T value) { // сколько раз входит значение в дерево
		std::cout << "поиск количества вхождений элемента " << value << std::endl;
		std::cout << "текущее дерево:" << std::endl;
		std::cout << *this << std::endl;
		if (!m_Root) {
			std::cout << "корня дерева нет - элементов 0" << std::endl;
			return 0;
		}
		return m_Root->Count(value);
	}
	int Count() { // сколько всего значений в дереве
		if (!m_Root) return 0;
		return m_Root->Count();
	}
    
	void Add(T value) {
        std::cout << "+++++++++++++++++++++++++++" << std::endl << std::endl;
		std::cout << "Начинаем добавлять элемент " << value << " в дерево" << std::endl;
		std::cout << "текущее дерево:" << std::endl;
		std::cout << *this << std::endl;
		// создаем массив значений
		auto count = Count() + 1;
        std::cout << "всего элементов в дереве: count=" << count - 1 << std::endl << std::endl;
		auto arr = new T[count];
        std::cout << "создаем массив arr размером на 1 больше: count=" << count << std::endl << std::endl;

		// вставка в массив всего существующего
		int index = 0;
		std::cout << "начинаем заполнять массив существующими значениями" << std::endl << std::endl;
		Node::Add(m_Root, arr, index);
        
        std::cout << std::endl << std::endl;
		// вставка элемента
		arr[index] = value;
		std::cout << "вставка добавляемого элемента " << value << " в конец массива" << std::endl << std::endl;
        std::cout << "получили массив: " << std::endl;
		for (int i = 0; i < count; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
        
        std::cout << std::endl;
		// сортируем массив
		Sort(arr, count);
        std::cout << std::endl;
        
		std::cout << "отсортированный массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl << std::endl;
        
		// удаляем корень
		std::cout << "удаляем существующий корень дерева" << std::endl;
		delete m_Root;

		// создаем корневой узел из массива
		std::cout << "начинаем формировать новый корень дерева" << std::endl;
		m_Root = Node::MakeTree1(arr, 0, count);
        std::cout << "задаем на корень дерева сформировавшийся узел" << std::endl << std::endl;
        std::cout << "удаляем служебный массив arr" << std::endl;
        std::cout << "+++++++++++++++++++++++++++" << std::endl << std::endl;
		// удаляем служебный массив
		delete[] arr;
	}
	void Remove(T value) {
		// создаем массив значений
        std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl << std::endl;
		std::cout << "Начинаем удалять элемент " << value << " из дерева" << std::endl;
		std::cout << "текущее дерево:" << std::endl;
		std::cout << *this << std::endl;
		auto count = Count();
		auto arr = new T[count];

		// вставка в массив всего существующего
		int index = 0;
        std::cout << std::endl;
		Node::Add(m_Root, arr, index);
        std::cout << std::endl;
		std::cout << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			std::cout << arr[i] << ' ';
        std::cout << std::endl << std::endl;

		// ищем индекс удаляемого элемента
		std::cout << "ищем индекс удаляемого элемента" << std::endl;
		index = -1;
		for (int i = 0; i < count; ++i) {
			if (arr[i] == value) {
				index = i;
				break;
			}
		}
		if (index < 0) {
			std::cout << "удаляемый элемент не найден - удалять нечего" << std::endl;
			delete[] arr;
			return;
		}

		// удаление элемента
		std::cout << "удаляем элемент в позиции: " << index << std::endl;
		for (int i = index; i < count - 1; ++i) 
			arr[i] = arr[i + 1];
		--count;

		std::cout << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;

		// сортируем массив
		Sort(arr, count);

		std::cout << "получен массив:" << std::endl;
		for (int i = 0; i < count; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;

		// удаляем корень
		delete m_Root;

		// создаем корневой узел из массива
		m_Root = Node::MakeTree1(arr, 0, count - 1);
        std::cout << "удаляем служебный массив arr" << std::endl << std::endl;
        std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
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

