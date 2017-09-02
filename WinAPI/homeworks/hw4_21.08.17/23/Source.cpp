#include <cmath>
#include <iostream>
#include <Windows.h>

void main()
{
	wchar_t buff[20];
	float x = std::hypot(float(100 + 40 / 2 - 135), float(150 + 30 / 2 - 298));
	wsprintf(buff, L"%f", x);
	std::cout << x << std::endl;
}