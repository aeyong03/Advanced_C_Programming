#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* ptr[3];
	char sss[100];
	for (int i = 0; i < 2; i++) {
		printf("문자열 입력 : ");
		gets(sss);
		
		ptr[i] = (char*)malloc(strlen(sss)+1);
		strcpy(ptr[i], sss);
	}

	ptr[2] = (char*)malloc(strlen(ptr[0]) + strlen(ptr[1]) + 1);

	strcpy(ptr[2], ptr[0]);
	strcat(ptr[2], ptr[1]);
	
	for (int i = 0; i < 3; i++) {
		printf("%s\n", ptr[i]);
		free(ptr[i]);
	}
	
	return 0;
}