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
	printf("���� 2���� �Է��Ͻÿ�: ");
	scanf("%d %d", &x, &y);
	larger = max(x, y);
	printf("�� ū���� %d�Դϴ�.\n", larger);
}