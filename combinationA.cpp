// 수학적인 조합 값을 구하는 예제

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
	printf("정수를 입력하시오: ");
	scanf("%d", &n);
	return n;
}

void main() 
{
	int a = getInteger();
	int b = getInteger();
	printf("C(%d, %d) = %d \n", a, b, combination(a, b));
}
