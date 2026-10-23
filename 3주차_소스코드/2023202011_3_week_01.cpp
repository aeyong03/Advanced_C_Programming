#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

	
	int my_strcmp(char* arr1, char* arr2) {
		int i = 0;

		
		while (*(arr1 + i) != '\0' && *(arr1 + i) == *(arr2 + i)) {
			i++;
		}
	
		if (*(arr1 + i) > *(arr2 + i)) {
			return 1;  
		}
		else if (*(arr1 + i) < *(arr2 + i)) {
			return -1; 
		}
		else {
			return 0;
		}
	}
	

char* my_strcat(char* arr1, char* arr2, char* arr3) {
	char* origin = arr3;


	while (*arr1 != '\0') {
		*arr3 = *arr1;
		arr3++;
		arr1++;
		}

	while (*arr2 != '\0') {
		*arr3 = *arr2;
		arr3++;
		arr2++;
		}
	*arr3 = '\0';
	
	return origin;
	
}

char* my_strcpy(char* arr1, char* arr4) {
	char* origin = arr4;

	while (*arr1 != '\0') {
		*arr4 = *arr1;
		arr4++;
		arr1++;
	}
	*arr4 = '\0';

	return origin;
}


int main() {
	char arr1[10], arr2[10];
	char arr3[20];
	char arr4[10];


	scanf("%s", arr1);
	scanf("%s", arr2);

	printf("\n\nmy_strcmp 결과 : %d\n", my_strcmp(arr1, arr2));
	printf("my_strcat 결과 : %s\n", my_strcat(arr1, arr2, arr3));
	printf("my_strcpy 결과 : %s\n", my_strcpy(arr1, arr4));

	return 0;
}

