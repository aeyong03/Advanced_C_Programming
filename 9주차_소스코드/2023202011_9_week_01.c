#include <stdio.h>

union infor
{
    char phone[15];
    char id_num[15];
};

struct user
{
    char name[10];

    union infor info;
};

int main()
{
    struct user a;
    printf("이름 입력 : ");
    scanf("%s", a.name);
    printf("정보 입력 : ");
    scanf("%s", a.info.phone);

    printf("%s\n", a.name);
    printf("%s", a.info.phone);
}