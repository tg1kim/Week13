#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void printMenu()
{
	printf("c: ¼·¾¾¿Âµµ¿¡¼­ È­¾¾¿Âµµ·Î º¯È¯\n");
	printf("f: È­¾¾¿Âµµ¿¡¼­ ¼·¾¾¿Âµµ·Î º¯È¯\n");
	printf("q: Á¾·á\n");
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
		printf("¸Þ´º¿¡¼­ ¼±ÅÃÇÏ¼¼¿ä.");
		scanf(" %c", &choice);
		if (choice == 'q')
			break;
		else if (choice == 'c') {
			printf("¼·¾¾¿Âµµ: ");
			scanf("%lf", &temp);
			printf("È­¾¾¿Âµµ: %.1f\n", Celsi2Fahren(temp));
		}
		else if (choice == 'f') {
			printf("È­¾¾¿Âµµ: ");
			scanf("%lf", &temp);
			printf("¼·¾¾¿Âµµ: %.1f\n", Fahren2Celsi(temp));
		}
	}
}