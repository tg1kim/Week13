#include <stdio.h>
#include <time.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	time_t start, end; 	// time_t는 unsigned long과 동일하다. 
	start = time(NULL);
	printf("10초가 되면 아무 키나 누르세요\n");
	while (1)	{
		if (getchar())
			break;
	}
	printf("종료되었습니다.\n");
	end = time(NULL);
	printf("경과된 시간은 %lld 초입니다.\n", end - start);
}