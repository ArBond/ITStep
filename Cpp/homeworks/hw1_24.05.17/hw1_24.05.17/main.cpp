//  hw ->  https://github.com/bugslayer312/CppStudentHomeWorks/blob/master/Oop_basic.pdf

#include "Vector.h"

#include <iostream>

void main()
{
	Vector v1;
	v1.SetValues(1.8, 6.3, -0.4);
	std::cout << "Vector 1: ";
	v1.Print();
	Vector v2(-3.4, -1.25, 7.8);
	std::cout << "Enter V2 coordinates:\n";
	v2.Read();
	std::cout << "add V2 to V1. V1 now: ";
	v1.Add(v2);
	v1.Print();
	std::cout << "Lenght of V1: " << v1.CalculateLength() << "\n";
	std::cout << "Cos(V1, V2): " << v1.CalculateCos(v2) << "\n";
	std::cout << "Scalar multiplication(V1, V2): " << v1.ScalarMult(v2) << "\n";
	Vector v3 = v1.VectorMult(v2);
	std::cout << "Vector multiplication(V1, V2): ";
	v3.Print();
}