// 난수 생성 프로그램
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 45

#pragma warning(disable: 4996 4326 6031)

void main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 6; i++)
		printf("%d ", rand() % MAX + 1);
	putchar('\n');
}