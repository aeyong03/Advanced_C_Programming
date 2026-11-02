#include <stdio.h>

int main()
{
    int num;
    printf("출력할 단 입력 : ");
    scanf("%d", &num);
    char filename[20] = "0_dan.txt";
    filename[0] = num + '0';

    FILE *task = fopen(filename, "w");
    for (int i = 0; i < 9; i++)
    {
        fprintf(task, "%d X %d = %d\n", num, (i + 1), num * (i + 1));
    }

    fclose(task);
    return 0;
}