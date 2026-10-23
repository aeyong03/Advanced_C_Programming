#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void func(int arr[]);
int main() {
	int arr[29];
	for (int i = 0; i < 29; i++) {
		arr[i] = i + 2;
	}
	func(arr);
}

void func(int arr[29]) {
	for (int i = 0; i < 29; i++) {
		for (int j = i+1; j < 29; j++) {
			if (arr[i] == 0) {
				continue;
				}
			if (arr[j] % arr[i] == 0) {
				arr[j] = 0;
			}
		}
		
	}

	for (int i = 0; i < 29; i++) {
		printf("%d ", arr[i]);
	}
}