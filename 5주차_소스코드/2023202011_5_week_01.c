#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcmp(char* ptr[2]) {
	int size1, size2, count = 0;
	size1 = (int)strlen(ptr[0]);
	size2 = (int)strlen(ptr[1]);
	if (size1 != size2) {
		printf("\nFalse");
		return;
	}
		for (int i = 0; i < size1; i++) {
		if (ptr[0][i] > 64 && ptr[0][i] < 91) {
			if (ptr[1][i] == ptr[0][i] || ptr[1][i] == ptr[0][i] + 32) {
				count++;
			}
		}
		if (ptr[0][i] > 96 && ptr[0][i] < 123) {
			if (ptr[1][i] == ptr[0][i] || ptr[1][i] == ptr[0][i] - 32) {
				count++;
			}
		}
	}
	if (count == size1) {
		printf("\nTrue");
	}
	else {
		printf("\nFalse");
	}

}

int main() {
	char str1[200];
	char str2[200];
	char* ptr[2];
	printf("1번째 문자열 입력 : ");
	scanf("%s", str1);
	printf("2번째 문자열 입력 : ");
	scanf("%s", str2);

	ptr[0] = (char*)malloc(sizeof(char) * (int)strlen(str1) + 1);
	ptr[1] = (char*)malloc(sizeof(char) * (int)strlen(str2) + 1);

	strcpy(ptr[0], str1);
	ptr[0][(int)strlen(str1)] = '\0';

	strcpy(ptr[1], str2);
	ptr[1][(int)strlen(str2)] = '\0';
	

	my_strcmp(ptr);
	free(ptr[0]); *ptr[0] = NULL;
	free(ptr[1]); *ptr[1] = NULL;
	

	return 0;

}