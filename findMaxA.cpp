#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}


void main()
{
	int x, y, larger;
	printf("정수 2개를 입력하시오: ");
	scanf("%d %d", &x, &y);
	larger = max(x, y);
	printf("더 큰값은 %d입니다.\n", larger);
}