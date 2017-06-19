#include "binary tree.h"

void main()
{
	BinaryTree tree1;
	tree1.Insert(0);
	tree1.Insert(-4);
	tree1.Insert(10);
	tree1.Insert(5);
	tree1.Insert(8);
	tree1.Print();

	TreeNode* node = tree1.Find(8);
	tree1.Erase(node);
	std::cout << "\n";
	tree1.Print();
	std::cout << "\n";
}
