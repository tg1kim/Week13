// ÇÔ¼ö

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable: 4996 4326 6031)

void displayCar(int carNumber, int distance)
{
	printf("CAR #%d:", carNumber);
	for (int i = 0; i < distance / 10; i++) 
		putchar('*');
	putchar('\n');
}

void main()
{
	int car1Dist = 0, car2Dist = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 20; i++) {
		system("cls");
		car1Dist += rand() % 100; 
		car2Dist += rand() % 100; 
		displayCar(1, car1Dist);
		displayCar(2, car2Dist);
		Sleep(1000);
	}
}