#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void x_symmetry(int x, int y) {
	char arr[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 'O';
		}
	}

	y = -y;
	int row = (y > 0) ? (2 - y) : (1 - y);
	int col = (x < 0) ? (x + 2) : (x + 1);
	arr[row][col] = 'X';

	printf("\nx축 대칭 결과:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

void y_symmetry(int x, int y) {
	char arr[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 'O';
		}
	}

	x = -x;
	int row = (y > 0) ? (2 - y) : (1 - y);
	int col = (x < 0) ? (x + 2) : (x + 1);
	arr[row][col] = 'X';

	printf("\ny축 대칭 결과:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

void origin_symmetry(int x, int y) {
	char arr[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 'O';
		}
	}

	x = -x;
	y = -y;
	int row = (y > 0) ? (2 - y) : (1 - y);
	int col = (x < 0) ? (x + 2) : (x + 1);
	arr[row][col] = 'X';

	printf("\n원점 대칭 결과:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {

	char arr[4][4];

	int x, y = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 'O';
		}
	}
	printf("'X'로 표시할 좌표 입력 : ");
	scanf("%d %d", &x, &y);

	int row = (y > 0) ? (2 - y) : (1 - y);
	int col = (x < 0) ? (x + 2) : (x + 1);

	arr[row][col] = 'X';

	printf("\n입력값 반영 좌표평면:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

	x_symmetry(x, y);
	y_symmetry(x, y);
	origin_symmetry(x, y);

	return 0;
}