#include <stdio.h>
#include <time.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	time_t start, end; 	// time_t�� unsigned long�� �����ϴ�. 
	start = time(NULL);
	printf("10�ʰ� �Ǹ� �ƹ� Ű�� ��������\n");
	while (1)	{
		if (getchar())
			break;
	}
	printf("����Ǿ����ϴ�.\n");
	end = time(NULL);
	printf("����� �ð��� %lld ���Դϴ�.\n", end - start);
}