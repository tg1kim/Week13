// �ﰢ �Լ� ���̺귯��
#include <math.h>
#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define PI	3.1415926535

void main()
{
	double x, y;
	x = PI / 2;
	y = sin(x);
	printf("sin(%f) = %f\n", x, y);
	y = cos(x);
	printf("cos(%f) = %f\n", x, y);
}