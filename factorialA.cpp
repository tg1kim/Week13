#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;		// result = result * i
	return result;
}

void main()
{
	int n;
	printf("�˰� ���� ���丮���� ����? ");
	scanf("%d", &n);
	printf("%d!�� ���� %d�Դϴ�.\n", n, factorial(n));
}