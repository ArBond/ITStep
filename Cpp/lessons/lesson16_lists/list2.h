#pragma once

#include <initializer_list>



struct Node2
{
	int Data;
	Node2* Next = nullptr;
	Node2* Prev = nullptr;

	Node2(int data) : Data(data)
	{
	}
};



class Iterator2
{
private:
	Node2* m_node;

public:
	Iterator2(Node2* node) :m_node(node)
	{
	}

	Iterator2 operator++()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Next;
		}
		return *this;
	}

	Iterator2 operator--()
	{
		if (m_node != nullptr)
		{
			m_node = m_node->Prev;
		}
		return *this;
	}

	int operator*()
	{
		return m_node->Data;
	}

	bool operator==(Iterator2 const& rhs) const
	{
		return m_node == rhs.m_node;
	}

	bool operator!=(Iterator2 const& rhs) const
	{
		return !(*this == rhs);
	}

	friend class List2;
};



class List2
{
private:
	Node2* m_head = nullptr;

	Node2* getLast()
	{
		Node2* cur = m_head;
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
	List2() = default;

	List2(std::initializer_list<int> const& list)
	{
		Node2* prevNode = nullptr;
		for (int value : list)
		{
			Node2* newNode = new Node2(value);
			if (prevNode != nullptr)
			{
				prevNode->Next = newNode;
				newNode->Prev = prevNode;
			}
			else
			{
				m_head = newNode;
			}
			prevNode = newNode;
		}
	}

	void insert(int value, Iterator2 position)
	{
		Node2* curNode = position.m_node;
		Node2* prevNode = curNode->Prev;
		Node2* newNode = new Node2(value);

		if (curNode)
		{
			if (prevNode)
			{
				prevNode->Next = newNode;
				newNode->Prev = prevNode;
			}
			else
			{
				m_head = newNode;
			}
			newNode->Next = curNode;
			curNode->Prev = newNode;
		}
		else
		{
			curNode = getLast();
			if (curNode)
			{
				curNode->Next = newNode;
				newNode->Prev = curNode;
			}
			else
			{
				m_head = newNode;
			}
		}
	}

	void erase(Iterator2 position)
	{
		Node2* curNode = position.m_node;
		if (!curNode)
		{
			return;
		}
		Node2* prevNode = curNode->Prev;
		Node2* nextNode = curNode->Next;
		if (prevNode)
		{
			prevNode->Next = nextNode;
		}
		else
		{
			m_head = nullptr;
		}
		if (nextNode)
		{
			nextNode->Prev = prevNode;
		}
		delete curNode;
	}

	int getCount() const
	{
		int count = 0;
		Node2* node = m_head;
		while (node != nullptr)
		{
			count++;
			node = node->Next;
		}
		return count;
	}

};