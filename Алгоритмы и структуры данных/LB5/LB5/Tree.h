#pragma once
#include <iostream>

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
			if(m_Parent) Balanse(m_Parent);
		}
		void AddRight(T value) {
			if (m_Right) {
				m_Right->Add(value);
				return;
			}
			m_Right = new Node(value);
			m_Right->m_Parent = this;
			if (m_Parent) Balanse(m_Parent);
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
		int GetHeight(int height = 0) {
			if (m_Left) {
				auto lh = m_Left->GetHeight(height + 1);
				if (lh > height) height = lh;
			}
			if (m_Right) {
				auto rh = m_Right->GetHeight(height + 1);
				if (rh > height) height = rh;
			}
			return height;
		}
		
		static Node* Balanse(Node* node) { // балансировка узла, возвращает корень дерева
			std::cout << "b-" << node->m_Value << std::endl;
			// берем высоты левого и правого поддерева
			int lh = 0;
			int rh = 0;
			if (node->m_Left) lh = node->m_Left->GetHeight(1);
			if (node->m_Right) rh = node->m_Right->GetHeight(1);

			// 
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

	void Parse(std::istream& is)
	{
		// очистка
		delete m_Root;

		// читаем значение
		T value;
		is >> value;

		// если фейл то ничего нет
		if (is.fail()) return;

		// создаем коренной узел
		Add(value);

		// вставка в корень пока чтото читается
		while (true) {
			// читаем значение
			is >> value;
			if (is.fail()) return;
			// вставка
			Add(value);
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
	void Add(T value) {
		if (!m_Root) m_Root = new Node(value);
		else m_Root->Add(value);
	}

	template<typename T1>
	friend std::ostream& operator << (std::ostream& os, Tree<T1>& t);
};

template<typename T1>
std::ostream& operator<<(std::ostream& os, Tree<T1>& t) {
	if (!t.m_Root) return os << "()";
	//return t.m_Root->Print(os);
	t.m_Root->PrintUstup(os, 0);
	os << "height=" << t.m_Root->GetHeight();
	return os;
}

