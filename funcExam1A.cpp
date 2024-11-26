// ÇÔ¼ö

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void printStars()
{
	for (int i = 0; i < 30; i++)
		putchar('*');
}

void main()
{
	printStars();
	printf("\nHello World!\n");
	printStars();
}