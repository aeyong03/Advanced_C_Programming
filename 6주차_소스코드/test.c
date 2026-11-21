#include <stdio.h>

int main()
{
    char s[20];
    FILE *fp;
    fp = fopen("test.txt", "wt");
    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }
    fscanf(fp, "%s", s);

    fclose(fp);
    return 0;
}