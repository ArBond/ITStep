/* ������� 3
   �������� ���������, �����������, � ����� ��������� ����� �������� ���������.
   ������������� ��� ������ �� ����� ���������� ��������� �������� ���� :
   ���������� �������� ����
   ����� ��������� = 1000 �
   �����(���.���) = 3.25
   ����� : 3 ��� 25 ��� = 205 ���
   �� ������ �� ��������� 17.56 �� / �
   ����� ��������� � ����� �������� � ���� ��������� � ����������. */

#include<stdio.h>

int main()
{
	printf("Vychislenie skorosti bega:\n");
	int dlinna = 1000;
	double vremja = 3.25;
	printf("dlinna distancii = %i m\n", dlinna);
	printf("Vremja (min.sec) = %.2f\n", vremja);
	int min = (int)vremja;
	double sec = (vremja - min)*100;
	double allSec = min * 60 + sec;
	printf("Vremja: %i min %.0f sec = %.0f sec\n", min, sec, allSec);
	double skorost = (dlinna / allSec)*3.6;
	printf("Vy bezali so skorostju %.2f km/h\n", skorost);
	return 0;
}