#include <stdio.h>
#include <math.h>	// �̰��� �ݵ�� �����Ͽ��� �Ѵ�. 

#pragma warning(disable: 4996 4326 6031)

void main()
{
	double result, value = 1.6;
	result = floor(value);		// result�� 1.0�̴�. 
	printf("%f ", result);
	result = ceil(value);		// result�� 2.0�̴�. 
	printf("%f ", result);
}