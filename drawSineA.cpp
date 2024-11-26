// ÇÔ¼ö

#include <stdio.h>
#include <math.h>

#define PI 3.141592

#pragma warning(disable: 4996 4326 6031)

double radian(double degree)
{
        return PI * degree / 180.0;
}

void drawBar(int height)
{
        for (int i = 0; i < height; i++)
                putchat('*');
        printf('\n');
}

void main() 
{
        for (int degree = 0; degree <= 90; degree += 10) {
                int y = (int)(60 * sin(radian(degree)) + 0.5);
                drawBar(y);
        }
}