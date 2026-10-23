#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print(char** ptrarr, int max_length, int count) {
	for (int i = 0; i < max_length; i++) {
		for (int j = 0; j < count; j++) {
			if (strlen(ptrarr[j]) > i) { //건너뛸 생각 말고 //문자열 길이가 출력하려는 열 위치i보다 클때만 글자를 출력
				printf("%c", ptrarr[j][i]);
			}
		}
	}
}


int main() {
	int count, max_length;
	char arr[100];
	printf("문자열 개수 입력: ");
	scanf("%d", &count);

	char** ptrarr = (char**)malloc(sizeof(char*) * count);

	for (int i = 0; i < count; i++) {
		printf("\n%d번째 문자열 입력:", i + 1);
		scanf("%s", arr);
		ptrarr[i] = (char*)malloc(strlen(arr) * sizeof(char) + 1);
		strcpy(ptrarr[i], arr);
		ptrarr[i][strlen(arr)] = '\0';
	}
	max_length = (int)strlen(ptrarr[0]);
	for (int i = 1; i < count; i++) {
		if (max_length < strlen(ptrarr[i])) {
			max_length = (int)strlen(ptrarr[i]);
		}
	}

	printf("\n");
	print(ptrarr, max_length, count);

	for (int i = 0; i < count; i++) {
		free(ptrarr[i]);
	}
	free(ptrarr);
	
}