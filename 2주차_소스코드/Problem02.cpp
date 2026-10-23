#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_index(int arr[]);
void swap_pointer(int*, int*);

int main() {
	int a;
	int arr[2];

	for (int i = 0; i < 2; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}
	printf("Before Swap : %d %d\n", arr[0], arr[1]);

	swap_index(arr);
	printf("Swap by index : %d %d\n\n\n", arr[0], arr[1]);

	for (int i = 0; i < 2; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}
	printf("Before Swap : %d %d\n", arr[0], arr[1]);


	swap_pointer(&arr[0], &arr[1]);
	printf("Swap by Pointer: %d %d\n\n", arr[0], arr[1]);

}

void swap_index(int arr[2]) {
	int temp;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void swap_pointer(int* pt1, int* pt2) {
	int temp;
	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
	
}