#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

int getInteger()
{
	int value;
	printf("������ �Է��Ͻÿ�: ");
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
	printf("�μ��� ���� %d�Դϴ�.\n", sum);
}