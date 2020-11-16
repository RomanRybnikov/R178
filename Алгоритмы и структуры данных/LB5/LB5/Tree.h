#pragma once
#include <iostream>

template<typename T>
class Tree
{
	class Node {
		T m_Value;
		Node* m_Left;
		Node* m_Right;

		void AddLeft(T value) {
			if (m_Left) {
				m_Left->Add(value);
				return;
			}
			m_Left = new Node(value);
		}
		void AddRight(T value) {
			if (m_Right) {
				m_Right->Add(value);
				return;
			}
			m_Right = new Node(value);
		}
	public: 
		Node(T value) {
			m_Value = value;
			m_Left = 0;
			m_Right = 0;
		}

		void Add(T value) {
			if (value < m_Value) AddLeft(value);
			else AddRight(value);
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
		m_Root = new Node(value);

		// вставка в корень пока чтото читается
		while (true) {
			// читаем значение
			is >> value;
			if (is.fail()) return;
			// вставка
			m_Root->Add(value);
		}
	}

public:
	Tree(std::istream& is) {
		m_Root = 0;
		Parse(is);
	}

	template<typename T1>
	friend std::ostream& operator << (std::ostream& os, Tree<T1> &t);
};

template<typename T1>
std::ostream& operator<<(std::ostream& os, Tree<T1> &t) {
	if (!t.m_Root) return os << "()";	
	return t.m_Root->Print(os);
}

