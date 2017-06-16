#pragma once

#include <initializer_list>

template <class T>
class List;

template <class T>
struct Node
{
	T Data;
	Node* Next = nullptr;

	Node(T data) : Data(data)
	{
	}
};

template <class T>
class Iterator
{
private:
	Node<T>* m_node;

public:
	Iterator(Node<T>* node) :m_node(node)
	{
	}

	Iterator operator++()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Next;
		}
		return *this;
	}

	T& operator*()
	{
		return m_node->Data;
	}

	bool operator==(Iterator const& rhs) const
	{
		return m_node == rhs.m_node;
	}

	bool operator!=(Iterator const& rhs) const
	{
		return !(*this == rhs);
	}

	friend class List<T>;

};


template <class T>
class List
{
private:
	Node<T>* m_head = nullptr;

	Node<T>* GetLast()
	{
		Node<T>* cur = m_head;
		if (m_head)
		{
			while (cur->Next)
			{
				cur = cur->Next;
			}
		}
		return cur;
	}


public:
	typedef Iterator<T> iterator;

	List() = default;

	List(std::initializer_list<T> const& list)
	{
		Node<T>* prevNode = nullptr;
		for (int value : list)
		{
			Node<T>* newNode = new Node<T>(value);
			if (prevNode)
			{
				prevNode->Next = newNode;
			}
			else
			{
				m_head = newNode;
			}
			prevNode = newNode;
		}
	}

	void Clear()
	{
		Node<T>* curNode = m_head;
		while (curNode)
		{
			Node<T>* nextNode = curNode->Next;
			delete curNode;
			curNode = nextNode;
		}
		m_head = nullptr;
	}

	~List()
	{
		Clear();
	}

	iterator begin()
	{
		return iterator(m_head);
	}

	iterator begin(int position)
	{
		Node<T>* curNode = m_head;
		for (int i = 0; i < position - 1; i++)
		{
			if (curNode == nullptr)
			{
				break;
			}
			curNode = curNode->Next;
		}
		return iterator(curNode);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	void insert(int value, iterator position)
	{
		Node<T>* curNode = position.m_node;
		Node<T>* newNode = new Node<T>(value);
		if (curNode)
		{
			newNode->Next = curNode->Next;
			curNode->Next = newNode;
			int buff = newNode->Data;
			newNode->Data = curNode->Data;
			curNode->Data = buff;
		}
		else
		{
			Node<T>* lastNode = GetLast();
			if (!lastNode)
			{
				m_head = newNode;
			}
			else
			{
				lastNode->Next = newNode;
			}
		}
	}

	void erase(iterator position)
	{
		Node<T>* cur = position.m_node;
		if (cur == nullptr)
		{
			return;
		}
		if (cur->Next == nullptr && cur == m_head)
		{
			delete cur;
			m_head = nullptr;
			return;
		}
		Node<T>* next = cur->Next;
		if (next != nullptr)
		{
			cur->Data = next->Data;
			cur->Next = next->Next;
			delete next;
		}
		else
		{
			Node<T>* prelast = m_head;
			while (prelast->Next != cur)
			{
				prelast = prelast->Next;
			}
			prelast->Next = nullptr;
			delete cur;
		}
	}

	int getCount() const
	{
		int count = 0;
		Node<T>* node = m_head;
		while (node != nullptr)
		{
			count++;
			node = node->Next;
		}
		return count;
	}
};