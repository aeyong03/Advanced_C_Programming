#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	char* p[3];
	char res[100];
	int size;

	for (int i = 0; i < 3; i++) {
		printf("%d 번째 문자열 : ", i + 1);
		scanf("%s", res);

		size = strlen(res);
		p[i] = (char*)malloc((sizeof(char) * size) + 1);

		for (int j = 0; j < size; j++) {
			*(p[i] + j) = res[size - 1 - j];
		}
		*(p[i] + size) = '\0';
	}


	printf("\n>>>입력과 반대로 출력<<<\n");
	for (int i = 2; i >= 0; i--) {
		printf("%d : %s\n", i + 1, *(p + i));
	}
	for (int i = 0; i < 3; i++) {
		free(p[i]);
	}
	return 0;
}