/* ������� 1:
   ������ ��� ������������� R1, R2, R3.
   ��������� �������� ������������� R0 �� ������� : 1 / R0 = 1 / R1 + 1 / R2 + 1 / R3.
   ����������� ������ : R1 = 2, R2 = 4, R3 = 8 R0 = 1.142857 */

#include<stdio.h>

int main()
{
	float r1 = 2;
	float r2 = 4;
	float r3 = 8;
	float r0;
	r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);
	printf("soprotivlenie r0 = %f\n", r0);
	return 0;
}