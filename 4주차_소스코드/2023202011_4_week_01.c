#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int cnd, sum = 0;
	int* p;
	printf("입력할 갯수는 ? : ");
	scanf("%d", &cnd);

	p = (int*)malloc(sizeof(int) * cnd);

	for (int i = 0; i < cnd; i++) {
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", (p + i));
	}
	for (int i = 0; i < cnd; i++) {
		if (*(p + i) % 2 == 0 ) {
			sum += *(p + i);
		}
	}
	printf("입력한 짝수 합 ==> %d", sum);
	free(p);
	return 0;
}