#pragma once

#include <initializer_list>

class List;

struct Node
{
	int Data;
	Node* Next = nullptr;

	Node(int data) : Data(data)
	{
	}
};

class Iterator
{
private:
	Node* m_node;

public:
	Iterator(Node* node) :m_node(node)
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

	int operator*()
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

	friend class List;

};

class List
{
private:
	Node* m_head = nullptr;

public:
	List() = default;

	List(std::initializer_list<int> const& list)
	{
		Node* prevNode = nullptr;
		for (int value : list)
		{
			Node* newNode = new Node(value);
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
		Node* curNode = m_head;
		while (curNode)
		{
			Node* nextNode = curNode->Next;
			delete curNode;
			curNode = nextNode;
		}
		m_head = nullptr;
	}

	~List()
	{
		Clear();
	}

	Iterator begin()
	{
		return Iterator(m_head);
	}

	Iterator begin(int position)
	{
		Node* curNode = m_head;
		for (int i = 0; i < position - 1; i++)
		{
			if (curNode == nullptr)
			{
				break;
			}
			curNode = curNode->Next;
		}
		return Iterator(curNode);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	Node* GetLast()
	{
		Node* cur = m_head;
		if (m_head)
		{
			while (cur->Next)
			{
				cur = cur->Next;
			}
		}
		return cur;
	}

	void insert(int value, Iterator position)
	{
		Node* curNode = position.m_node;
		Node* newNode = new Node(value);
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
			Node* lastNode = GetLast();
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
};