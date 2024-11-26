#include <stdio.h>
#include <math.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	float height, distance, tree_height, degrees, radians;
	printf("나무와의 길이(단위는 미터): ");
	scanf("%f", &distance);

	printf("측정자의 키(단위는 미터): ");
	scanf("%f", &height);

	printf("각도(단위는 도): ");
	scanf("%f", &degrees);

	radians = degrees * 3.141592 / 180.0;
	tree_height = tan(radians) * distance + height;
	printf("나무의 높이(단위는 미터): %f\n", tree_height);
}
