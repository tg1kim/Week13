#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int getInteger(void)
{
	int n;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);
	return n;
}

int isPrime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void main()
{
	int n = getInteger();
	if (isPrime(n))
		printf("%d은 소수입니다.\n", n);
	else
		printf("%d은 소수가 아닙니다.\n", n);
}