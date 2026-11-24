#include <stdio.h>

int main()
{
    long fpos;
    int i;

    FILE *fp = fopen("test.txt", "wt");
    fputs("1234-", fp);
    fclose(fp);

    fp = fopen("test.txt", "rt");

    for (int i = 0; i < 4; i++)
    {
        putchar(fgetc(fp));
        fpos = ftell(fp); // 1부터 시작
        fseek(fp, -1, SEEK_END);
        putchar(fgetc(fp)); //-출력
        fseek(fp, fpos, SEEK_SET);
    }

    fclose(fp);
    return 0;
}