#include <stdio.h>

int main()
{
    int num;
    puts("출력할 단 입력 : ");
    scanf("%d", &num);
    char Filename[20] = "0_dan.txt";
    Filename[0] = num + '0';
    FILE *fp = fopen(Filename, "wt");

    for (int i = 1; i < 10; i++)
    {
        fprintf(fp, "%d X %d = %d\n", num, i, num * i);
    }
    fclose(fp);
    return 0;
}