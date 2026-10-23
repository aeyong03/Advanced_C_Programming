#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void input_char(char str[], char order[]) {

    printf("정렬할 문자열을 입력하세요: ");
    scanf("%s", str);

    printf("정렬 방식을 입력하세요 (오름차순 / 내림차순): ");
    scanf("%s", order);
}

void func_sort(char str[], char order[]) {
    int len = strlen(str);
    char temp;

    if (strcmp(order, "오름차순") == 0) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (str[i] > str[j]) {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
    }

    else if (strcmp(order, "내림차순") == 0) {
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (str[i] < str[j]) {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
    }
}

void func_print(char str[]) {
    printf("정렬 결과: %s\n", str);
}

int main() {
    char str[100];
    char order[20];

    input_char(str, order);
    func_sort(str, order);
    func_print(str);

    return 0;
}