#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

double Celsi2Fahren(double c_temp); 	// �Լ� ����

void main()
{
	printf("���� %f���� ȭ�� %f�Դϴ�.\n", 36.0, Celsi2Fahren(36.0));
}

double Celsi2Fahren(double c_temp)
{
	return 9.0 / 5.0 * c_temp + 32;
}