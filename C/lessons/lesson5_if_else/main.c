/*  ����������� ����������� ������  5 ����  */

//#include<stdio.h>
//
//int main()
//{
//	int a;
//	int b;
//	int c;
//	printf("Vvedire 3 chisla:\n");
//	scanf("%i%i%i", &a, &b, &c);
//	if (a <= b && a <= c)
//	{
//		printf("%i ", a);
//		if (b<=c)
//		{
//			printf("%i %i\n", b, c);
//		}
//		else
//		{
//			printf("%i %i\n", c, b);
//		}
//	}
//	else if (b <= a && b <= c)
//	{
//		printf("%i ", b);
//		if (a <= c)
//		{
//			printf("%i %i\n", a, c);
//		}
//		else
//		{
//			printf("%i %i\n", c, a);
//		}
//	}
//	else if (a <= b)
//	{
//		printf("%i %i %i\n", c, a, b);
//	}
//	else
//	{
//		printf("%i %i %i\n", c, b, a);
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int main()
//{
//	srand(time(0));
//	int computerNumber = rand() %10;
//	printf("%i\n", computerNumber);
//	int userNumber;
//	printf("Zagadano chislo ot 0 do 9. Kakoe eto chislo?\n");
//	int kounter = 1;
//	while (kounter < 4)
//	{
//		scanf("%i", &userNumber);
//		if (computerNumber < userNumber)
//		{
//			printf("Men'se\n");
//		}
//		else if (computerNumber > userNumber)
//		{
//			printf("Bol'she\n");
//		}
//		else
//		{
//			printf("Vy ugadali za %i popytku! Eto bylo chislo %i\n", kounter, computerNumber);
//			return 0;
//		}
//		kounter++;
//	}
//	printf("Vy ne ugadali. Eto bylo chislo %i\n", computerNumber);
//	return 0;
//}


/* ������� 4: 
   �������� ������� ������ ��������� � ������ �� ������ � � ����� � ����� ����� �.
   ������� ���� ��� ������� � �������� � 300������. ����������� ������� �� 1 �� � �����������
   �� ���� ����� � �������� ��������� :
   -�� 500 �� : 1 ������ / ��
   - �� 1000 �� : 4 ������ / ��
   - �� 1500 �� : 7 ������ / ��
   - �� 2000 �� : 9 ������ / ��.
   - ����� 2000 �� � ������� �� ���������.
   ������������ ������ ���������� ����� �������� � � �, � ���������� ����� �������� � � �, �
   ����� ��� �����.��������� ������ ���������� ����� ����������� ���������� �������
   ���������� ��� ���������� �������� � ������ �, ����� �������� �� ������ � � ����� �.�
   ������ ������������� ���������� ����� �� ���������� � ��������� ������ �������
   ��������� � ������������� ������ �� ���������� ��������. */

#include<stdio.h>

int main()
{
	const int jomkost = 300;    
	int rasstojanieA_B;
	int rasstojanieB_C;
	int vesGruza;
	int rashod;
	printf("Jomkost' vashego baka ravna 300 l!\n");
	printf("Vvedite ves gruza:\n");
	scanf("%i", &vesGruza);
	if (vesGruza > 2000)
	{
		printf("Samoljot ne smozet vzletet'!\n");
		return 0;
	}
	else if (vesGruza <= 500)
	{
		rashod = 1;
		printf("Rashod budet raven %i l/km\n", rashod);
	}
	else if (vesGruza <= 1000 && vesGruza > 500)
	{
		rashod = 4;
		printf("Rashod budet raven %i l/km\n", rashod);
	}
	else if (vesGruza <= 1500 && vesGruza > 1000)
	{
		rashod = 7;
		printf("Rashod budet raven %i l/km\n", rashod);
	}
	else 
	{
		rashod = 9;
		printf("Rashod budet raven %i l/km\n", rashod);
	}
	printf("Vvedite rasstojanie ot punkta A do punkta B:\n");
	scanf("%i", &rasstojanieA_B);
	int nuznoLitrovA_B = rasstojanieA_B * rashod;
	if (nuznoLitrovA_B > 300)
	{
		printf("Samoljot ne doletit do punkta B\n");
		return 0;
	}
	printf("Vvedite rasstojanie ot punkta B do punkta C:\n");
	scanf("%i", &rasstojanieB_C);
	int nuznoLitrovB_C = rasstojanieB_C * rashod;
	if (nuznoLitrovB_C > 300)
	{
		printf("Samoljot ne doletit do punkta C\n");
		return 0;
	}
	int ostatokTopliva = 300 - nuznoLitrovA_B;
	if (ostatokTopliva >= nuznoLitrovB_C)
	{
		printf("Samoljot ne nuzdaetsja v dozapravke\n");
	}
	else
	{
		int nuznoDozapravit = nuznoLitrovB_C - ostatokTopliva;
		printf("Nuzno budet dozapravit' %i l topliva v punkte B chtoby doletet' do punkta C\n", nuznoDozapravit);
	}
	return 0;
}