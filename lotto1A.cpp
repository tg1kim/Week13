// ÇÔ¼ö

#include <stdio.h>
#include <stdlib.h>		// rand

#pragma warning(disable: 4996 4326 6031)

void main()
{
	for (int i = 0; i < 6; i++)
		printf("%d ", rand());
	putchar('\n');
}