#include <stdio.h>
#include <math.h> 

#pragma warning(disable: 4996 4326 6031)

void main() 
{
        int n;
        printf("1.팩토리얼\n");
        printf("2.싸인\n");
        printf("3.로그(base 10)\n");
        printf("4.제곱근\n");
        printf("5.순열(nPr)\n");
        printf("6.조합(nCr)\n");
        printf("7.종료\n");
        printf("선택해주세요: ");
        scanf("%d", &n);
}

void factorial()
{
        long long n, result = 1;
        "정수를 입력하시오: "
	???
        "결과 = %lld\n\n"
}

void sine()
{
        double a, result;
        "각도를 입력하시오: "
        ???
        "결과 = %lf\n\n", result);
}

void logBase10()
{
        double a, result;
        "실수값을 입력하시오: "
        ???
        if (???)        
                "오류\n"
        else        {
                ???
                "결과 = %lf\n\n"
        }
}

void main()
{
        while (1) {
                switch (menu()) {
                case 1:	// factorial
                case 2:	// sine
                case 3:	// log
                case 7:	// 종료
                        "종료합니다.\n"
                default:	// 선택 오류
                        "잘못된 선택입니다.\n"
                }
        }
}