#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int arr[4][8] = { 0 };
	int a;
	int gap = 1;


	for (int i = 0; i < 8; i++) {
		scanf("%d", &a);
		arr[0][i] = a;
	}


	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 8; j += 2 * gap) {

			int val1 = *(*(arr + (i - 1)) + j);
			int val2 = *(*(arr + (i - 1)) + (j + gap));

			*(*(arr + i) + j) = val1 + val2;

		}

		gap *= 2;
	}

	printf("최종 결과 : %d", *(*(arr + 3)) + 0);




}