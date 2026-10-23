#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



void ref_swap(int*, int*);
void val_swap(int, int);

int main() {
	int a, b;
	
	scanf("%d %d", &a, &b);
	printf("Before swap A : %d, B : %d\n\n", a, b);

	val_swap(a, b);
	printf("After value swap (in main) A : %d, B : %d\n\n", a, b);

	ref_swap(&a, &b);
	printf("Reference value swap (in main) A : %d, B : %d\n\n", a, b);

	return 0;

}

void val_swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("After value swap (in function) A : %d, B : %d\n", a, b);
}


void ref_swap(int *pt1, int *pt2) {
	int temp;
	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;

	printf("After value swap (in function) A : %d, B : %d\n", *pt1, *pt2);
		
}


