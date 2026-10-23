#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num;
	int I_count = 0, V_count = 0, X_count = 0, L_count = 0, C_count = 0, D_count = 0;
	int count = 0;
	printf("숫자 입력:");
	scanf("%d", &num);
	printf("%d = ", num);

	char* ptr;
	ptr = (char*)malloc(sizeof(char) * 1);

	D_count = num / 500;
	num %= 500;
	
	C_count = num / 100;
	num %= 100;
	

	L_count = num / 50;
	num %= 50;
	
	X_count = num / 10;
	num %= 10;
	
	V_count = num / 5;
	num %= 5;

	I_count = num;
	

	if (D_count == 1 && C_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[0] = 'C';
		ptr[1] = 'M';
		count += 2;

		printf("900 + ");
	}
	else if(D_count == 0 && C_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[0] = 'C';
		ptr[1] = 'D';
		count += 2;

		printf("400 + ");
	}
	else {
		ptr = (char*)realloc(ptr, sizeof(char) * (count + D_count + C_count));
		for (int i = 0; i < D_count; i++) {
			ptr[i] = 'D';
		}
		count += D_count;
		for (int i = count; i < count + C_count; i++) {
			ptr[i] = 'C';
		}
		count += C_count;

		printf("%d00 + ", D_count*5 + C_count);
	}



	if (L_count == 1 && X_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[count] = 'X';
		ptr[count + 1] = 'C';
		count += 2;

		printf("90 + ");
	}
	else if (L_count == 0 && X_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[count] = 'X';
		ptr[count + 1] = 'L';
		count += 2;

		printf("40 + ");
	}
	else {
		ptr = (char*)realloc(ptr, sizeof(char) * (count + L_count + X_count));
		for (int i = count; i < count+ L_count; i++) {
			ptr[i] = 'L';
		}
		count += L_count;
		for (int i = count; i < count + X_count; i++) {
			ptr[i] = 'X';
		}
		count += X_count;

		printf("%d0 + ", L_count*5 + X_count);
	}
	/*************************
	940 입력하면 900 + 40 + 0 이라고 나옴 뒤에 0 해결!@!
	
	
	
	
	******************************/



	if (V_count == 1 && I_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[count] = 'I';
		ptr[count+1] = 'X';
		count += 2;

		printf("9 = ");
	}
	else if (V_count == 0 && I_count == 4) {
		ptr = (char*)realloc(ptr, sizeof(char) * (count+2));
		ptr[count] = 'I';
		ptr[count+1] = 'V';
		count += 2;

		printf("4 = ");
	}
	else {
		ptr = (char*)realloc(ptr, sizeof(char) * (count + V_count + I_count));
		for (int i = count; i < count + V_count; i++) {
			ptr[i] = 'V';
		}
		count += V_count;
		for (int i = count; i < count + I_count; i++) {
			ptr[i] = 'I';
		}
		count += I_count;

		printf("%d = ", V_count*5 + I_count);
	}

	for (int i = 0; i < count; i++) {
		printf("%c", ptr[i]);
	}
	printf(", %d", count);

	free(ptr);
	return 0;
}
