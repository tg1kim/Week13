#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void printMenu()
{
	printf("c: �����µ����� ȭ���µ��� ��ȯ\n");
	printf("f: ȭ���µ����� �����µ��� ��ȯ\n");
	printf("q: ����\n");
}

double Cels2Fahren(double c_temp)
{
	return 9.0 / 5.0 * c_temp + 32;
}

double Fahren2Celsi(double f_temp)
{
	return (f_temp - 32.0) * 5.0 / 9.0;
}

void main()
{
	char choice;
	double temp;
	while (1) {
		printMenu();
		printf("�޴����� �����ϼ���.");
		scanf(" %c", &choice);
		if (choice == 'q')
			break;
		else if (choice == 'c') {
			printf("�����µ�: ");
			scanf("%lf", &temp);
			printf("ȭ���µ�: %.1f\n", Celsi2Fahren(temp));
		}
		else if (choice == 'f') {
			printf("ȭ���µ�: ");
			scanf("%lf", &temp);
			printf("�����µ�: %.1f\n", Fahren2Celsi(temp));
		}
	}
}