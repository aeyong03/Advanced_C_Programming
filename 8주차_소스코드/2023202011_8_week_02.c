#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int age;
} Student;

int main()
{
    int count;

    printf("입력할 학생 수:");
    scanf("%d", &count);

    Student *p = (Student *)malloc(sizeof(Student) * count);
    if (p == NULL)
    {
        printf("메모리 할당 실패!\n");
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        printf("이름과 나이 입력 : ");
        scanf("%s %d", (p + i)->name, &(p + i)->age);
    }

    printf("-- 학생 명단 --\n");
    for (int i = 0; i < count; i++)
    {
        printf("이름: %s, 나이:%d\n", (p + i)->name, (p + i)->age);
    }

    free(p);
    return 0;
}