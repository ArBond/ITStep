/* ������� 2:
   �� �������� ����� ���������� ����� ������� ����� �� ������� S = pi*R2, ������
   ��������� �� ������� ����� ���������� : L = 2 * pi *R ���������� pi = 3.14 */

#include<stdio.h>

int main()
{
	float const pi = 3.14;
	float l = 11.5;
	float s;
	s = l * l / (4 * pi);
	printf("ploshad' kruga = %f\n", s);
	return 0;
}