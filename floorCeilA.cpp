#include <stdio.h>
#include <math.h>	// 이것을 반드시 포함하여야 한다. 

#pragma warning(disable: 4996 4326 6031)

void main()
{
	double result, value = 1.6;
	result = floor(value);		// result는 1.0이다. 
	printf("%f ", result);
	result = ceil(value);		// result는 2.0이다. 
	printf("%f ", result);
}