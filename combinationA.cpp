// �������� ���� ���� ���ϴ� ����

#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;		// result = result * i
	return result;
}

int combination(int n, int r)
{
	return factorial(n) / (factorial(r) * factorial(n - r);
}

int getInteger(void)
{
	int n;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &n);
	return n;
}

void main() 
{
	int a = getInteger();
	int b = getInteger();
	printf("C(%d, %d) = %d \n", a, b, combination(a, b));
}