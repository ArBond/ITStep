#pragma once

#include <iostream>

struct TreeNode
{
	int Data;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;
	TreeNode* Parent = nullptr;
	TreeNode(int value) : Data(value)
	{
	}

};

class BinaryTree
{
	TreeNode* m_root = nullptr;

public:
	BinaryTree() = default;

	void Insert(int value)
	{
		if (!m_root)
		{
			TreeNode* newNode = new TreeNode(value);
			m_root = newNode;
		}
		InsertRecursive(m_root, value);
	}

	void InsertRecursive(TreeNode* node, int value)
	{
		if (value == node->Data)
		{
			return;
		}
		if (value < node->Data)
		{
			if (node->Left)
			{
				InsertRecursive(node->Left, value);
			}
			else
			{
				TreeNode* newNode = new TreeNode(value);
				node->Left = newNode;
				newNode->Parent = node;
			}
		}
		else
		{
			if (node->Right)
			{
				InsertRecursive(node->Right, value);
			}
			else
			{
				TreeNode* newNode = new TreeNode(value);
				node->Right = newNode;
				newNode->Parent = node;
			}
		}
	}

	void Print()
	{
		PrintRecursive(m_root);
	}

	void PrintRecursive(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		PrintRecursive(node->Left);
		std::cout << node->Data << " ";
		PrintRecursive(node->Right);
	}

	TreeNode* FindRecursive(TreeNode* node, int value)
	{
		if (node)
		{
			if (value == node->Data)
			{
				return node;
			}
			if (value < node->Data)
			{
				return FindRecursive(node->Left, value);
			}
			else
			{
				return FindRecursive(node->Right, value);
			}
		}
		else
		{
			return nullptr;
		}
	}
	TreeNode* Find(int value)
	{
		return FindRecursive(m_root, value);
	}

	void Erase(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		TreeNode* forReplace = nullptr;
		TreeNode* newParent = node->Parent;
		if (node->Left != nullptr && node->Right != nullptr)
		{
			forReplace = node->Right;
			while (forReplace->Left != nullptr)
			{
				forReplace = forReplace->Left;
			}
			forReplace->Data = std::move(node->Data);
			node = forReplace;
			forReplace = nullptr;
		}

		if (node->Left != nullptr)
		{
			forReplace = node->Left;
		}
		else if (node->Right != nullptr)
		{
			forReplace = node->Right;
		}
		if (forReplace != nullptr)
		{
			forReplace->Parent = newParent;
		}
		if (newParent)
		{
			if (newParent->Left == node)
			{
				newParent->Left = forReplace;
			}
			else
			{
				newParent->Right = forReplace;
			}
		}
		delete node;
	}

};