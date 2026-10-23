#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char** ptr, int num) {
	for (int i = 0; i < num; i++) {
		int size = (int)strlen(ptr[i]);
		for (int j = 0; j < size; j++) {
			if (ptr[i][j] > 64 && ptr[i][j] < 91) {
				ptr[i][j] = ptr[i][j] + 32;
			}
			else if (ptr[i][j] > 96 && ptr[i][j] < 123){
				ptr[i][j] = ptr[i][j] - 32;
			}
		}
		ptr[i][size] = '\0';
	}

	for (int i = 0; i < num; i++) {
		printf("%d번째 대소문자 바꾼 문자열 : ", i+1);
		printf("%s\n", ptr[i]);
	}
}

int main() {
	int num;
	printf("입력할 문자열 개수 : ");
	scanf("%d", &num);
	char arr[200];
	char** ptr = (char**)malloc(sizeof(char*) * num);
	for (int i = 0; i < num; i++) {
		printf("\n%d번째 문자열 :", i+1);
		scanf("%s", arr);
		ptr[i] = (char*)malloc(sizeof(char) * (int)strlen(arr) + 1);
		strcpy(ptr[i], arr);
		ptr[i][(int)strlen(arr)] = '\0';
	}
	printf("\n");

	change(ptr, num);
	for (int i = 0; i < num; i++) {
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free(ptr);
	**ptr = NULL;



}