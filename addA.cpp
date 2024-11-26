#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int getInteger()
{
	int value;
	printf("정수를 입력하시오: ");
	scanf("%d", &value);
	return value;
}

int add(int x, int y)
{
	return x + y;
}

void main() 
{
	int x = getInteger();
	int y = getInteger();
	int sum = add(x, y);
	printf("두수의 합은 %d입니다.\n", sum);
}