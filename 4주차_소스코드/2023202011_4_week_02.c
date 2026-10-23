#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int* p = NULL;
	int cnt = 0, sum = 0, data;

	for (int i = 0; ; i++) {
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", &data);

		if (data == 0) {
			break;
		}
		if (data % 2 == 1) {
			continue;
		}
		cnt++;
		if (p == NULL) {
			p = (int*)malloc(sizeof(int) * cnt);
		}
		else {
			p = (int*)realloc(p, sizeof(int) * cnt);
		}

		p[cnt - 1] = data;
	}
	for (int i = 0; i < cnt; i++) {
		sum += *(p + i);
	}

	printf("입력한 짝수 합 ==> %d\n", sum);
	if (p != NULL) {
		free(p);
	}

	return 0;
}
	