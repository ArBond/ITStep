//        УКАЗАТЕЛИ НА ФУНКЦИИ

//#include <stdio.h>
//
//void foo2(void(*fff1)(), void(*fff2)(), void(*fff3)())
//{
//	fff1();
//	fff2();
//	fff3();
//}
//
//void foo3()
//{
//	printf("foo3\n");
//}
//
//void main()
//{
//	foo2(foo3, foo3, foo3);
//}






#include <stdio.h>

//typedef

void foo(void(*foo1)(), void(*foo2)(), void(*foo3)())
{
	foo1(1);
	foo2(2);
	foo3(3);
}

void foo1(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("I am a foo1\n");
	}
}

void foo2(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("I am a foo2\n");
	}
}

void foo3(int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("I am a foo3\n");
	}
}

void main()
{
	foo(foo1, foo2, foo3);
}
