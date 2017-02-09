/* Задание 4: ДОП. ЗАДАНИЕ С УРОКА
Грузовой самолет должен пролететь с грузом из пункта А в пункт С через пункт В.
Емкость бака для топлива у самолета – 300литров. Потребление топлива на 1 км в зависимости
от веса груза у самолета следующее :
-до 500 кг : 1 литров / км
- до 1000 кг : 4 литров / км
- до 1500 кг : 7 литров / км
- до 2000 кг : 9 литров / км.
- более 2000 кг – самолет не поднимает.
Пользователь вводит расстояние между пунктами А и В, и расстояние между пунктами В и С, а
также вес груза.Программа должна рассчитать какое минимальное количество топлива
необходимо для дозаправки самолету в пункте В, чтобы долететь из пункта А в пункт С.В
случае невозможности преодолеть любое из расстояний – программа должна вывести
сообщение о невозможности полета по введенному маршруту. */


//ДОП. ЗАДАНИЕ С УРОКА

#include <stdio.h>

int main()
{
	const int jomkost = 300;
	int vesGruza;
	int rashod;
	printf("Jomkost' vashego baka ravna 300 l!\nVvedite ves gruza(kg):\n");
	scanf("%i", &vesGruza);
	if (vesGruza > 2000)
	{
		printf("Samoljot ne smozet vzletet'!\n");
		return 1;
	}
	else if (vesGruza <= 500)
	{
		rashod = 1;
		printf("Rashod budet raven %i l/km.\n", rashod);
	}
	else if (vesGruza <= 1000 && vesGruza > 500)
	{
		rashod = 4;
		printf("Rashod budet raven %i l/km.\n", rashod);
	}
	else if (vesGruza <= 1500 && vesGruza > 1000)
	{
		rashod = 7;
		printf("Rashod budet raven %i l/km.\n", rashod);
	}
	else
	{
		rashod = 9;
		printf("Rashod budet raven %i l/km.\n", rashod);
	}
	int rasstojanieAB;
	printf("Vvedite rasstojanie ot punkta A do punkta B(km):\n");
	scanf("%i", &rasstojanieAB);
	int nuznoLitrovAB = rasstojanieAB * rashod;
	if (nuznoLitrovAB > 300)
	{
		printf("Samoljot ne doletit do punkta B!\n");
		return 1;
	}
	int rasstojanieBC;
	printf("Vvedite rasstojanie ot punkta B do punkta C(km):\n");
	scanf("%i", &rasstojanieBC);
	int nuznoLitrovBC = rasstojanieBC * rashod;
	if (nuznoLitrovBC > 300)
	{
		printf("Samoljot ne doletit do punkta C!\n");
		return 1;
	}
	int ostatokTopliva = 300 - nuznoLitrovAB;
	if (ostatokTopliva >= nuznoLitrovBC)
	{
		printf("Samoljot ne nuzdaetsja v dozapravke.\n");
	}
	else
	{
		int nuznoDozapravit = nuznoLitrovBC - ostatokTopliva;
		printf("Nuzno budet dozapravit' %i l topliva v punkte B chtoby doletet' do punkta C.\n", nuznoDozapravit);
	}
	return 0;
}