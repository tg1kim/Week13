#include <stdio.h>
#include <math.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	float height, distance, tree_height, degrees, radians;
	printf("�������� ����(������ ����): ");
	scanf("%f", &distance);

	printf("�������� Ű(������ ����): ");
	scanf("%f", &height);

	printf("����(������ ��): ");
	scanf("%f", &degrees);

	radians = degrees * 3.141592 / 180.0;
	tree_height = tan(radians) * distance + height;
	printf("������ ����(������ ����): %f\n", tree_height);
}