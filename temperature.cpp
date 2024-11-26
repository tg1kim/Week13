#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

printMenu
{
	"c: 섭씨온도에서 화씨온도로 변환\n"
	"f: 화씨온도에서 섭씨온도로 변환\n"
	"q: 종료\n"
}

Celsi2Fahren
{
}

Fahren2Celsi
{
}

void main()
{
	while (1) {
		메뉴 출력
		"메뉴에서 선택하세요."
		choice에 입력
		q인 경우
			break;
		c인 경우
			"섭씨온도: "
			temp에 입력
			"화씨온도: %f\n"
		f인 경우
			"화씨온도: ");
			temp에 입력
			"섭씨온도: %f\n"
		}
	}
}