#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



char VIP[4] = "VIP";
char Standard[10] = "Standard";


int room_VIP[3] = { 0, 0, 0 };
int room_Standard[5] = { 0, 0, 0, 0, 0 };




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

int VIP_check(int member) {

	if (member > 4) {
		return -1;
	}

	int* p = room_VIP;
	for (int i = 0; i < 3; i++) {
		if (*p == 0) {
			*p = 1;
			return 301 + i;
		}
		p++;
	}

	return -1;
}

int Standard_check(int member) {

	if (member > 2) {
		return -1;
	}

	int* p = room_Standard;
	for (int i = 0; i < 5; i++) {
		if (*p == 0) {
			*p = 1;
			return 201 + i;
		}
		p++;
	}

	return -1;
}

int reservation(int member, char* type) {

	if (my_strcmp(type, VIP) == 0) {
		return VIP_check(member);
	}
	else if (my_strcmp(type, Standard) == 0) {
		return Standard_check(member);
	}
	return -1;
}

int main() {
	int member;
	char type[10];

	for (int i = 0; i < 5; i++) {
		printf("\n예약 인원 입력 : ");
		scanf("%d", &member);
		printf("객실 타입 입력(VIP / Standard) : ");
		scanf("%s", type);

		int room_num = reservation(member, type);

		if (room_num != -1) {
			printf("예약 완료 : %d호\n", room_num);
		}
		else {
			printf("예약 불가\n");
		}
	}

	return 0;



}