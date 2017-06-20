#include "binary tree.h"
#include "stack.h"
#include "Queue.h"



//			  НАСЛЕДОВАНИЕ


class A
{
public:
	void MethodA()
	{
		std::cout << "method A\n";
	}
protected:
	void MethodC()
	{
		std::cout << "method C\n";
	}
};

class B : public A
{
public:
	void MethodB()
	{
		std::cout << "method B\n";
		MethodC();
	}
};




void main()
{

	//BinaryTree tree1;
	//tree1.Insert(0);
	//tree1.Insert(-4);
	//tree1.Insert(10);
	//tree1.Insert(5);
	//tree1.Insert(8);
	//tree1.Print();
	//std::cout << "  " << tree1.GetCount();

	//TreeNode* node = tree1.Find(8);
	//tree1.Erase(node);
	//std::cout << "\n";
	//tree1.Print();
	//std::cout << "  " << tree1.GetCount();
	//std::cout << "\n";

	//tree1.Erase(tree1.Find(0));
	//tree1.Print();
	//std::cout << "  " << tree1.GetCount();
	//std::cout << "\n";

	//tree1.Clear();
	//tree1.Print();
	//std::cout << "  " << tree1.GetCount();
	//std::cout << "\n";



	//					QUEUE
	//Queue<int> q1;
	//for (int i = 0; i < 10; i++)
	//{
	//	//q1.Push(i + 1);
	//	q1.Push(i + 1);
	//	std::cout << q1.Pop() << " ";
	//}


	//						НАСЛЕДОВАНИЕ

	A a;
	a.MethodA();

	B b;
	b.MethodA();
	b.MethodB();
}


// Гради Буч
