#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double pi = 3.14;

void Area_func(int r) {
	printf("원의 넓이는 %f\n", r * r * pi);
}

void Circ_func(int r) {
	printf("원의 둘레는 %f\n", 2 * pi * r);
}

void main() {
	int r;
	printf("넓이 / 둘레를 구할 원의 반지름을 입력하시오 : \n");
	scanf("%d", &r);
	printf("입력한 반지름 : %d 에 대한\n", r);
	Area_func(r);
	Circ_func(r);

}
