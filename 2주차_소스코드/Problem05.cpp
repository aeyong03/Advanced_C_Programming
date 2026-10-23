#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void sort_Ascending(int arr[100]) {
    int temp;
    for (int i = 0; i < 99; i++) {
        for (int j = i + 1; j < 100; j++) { 
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n\n");
}

void sort_Descending(int arr[100]) {
    int temp;
    for (int i = 0; i < 99; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (arr[i] < arr[j]) {       
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
}

void main() {
	int arr[100];

	for (int i = 0; i < 100;i++) {
        arr[i] = i;
		
	}

	sort_Ascending(arr);
	sort_Descending(arr);

}