#include <stdio.h>
#include <string.h>

int main()
{
    FILE *src = fopen("src.txt", "rt");
    FILE *des = fopen("dst.txt", "wt");
    int ch;

    if (src == NULL || des == NULL)
    {
        puts("FUCK!!");
        return -1;
    }

    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, des);
    }

    if (feof(src) != 0)
    {
        puts("YES!!");
    }
    else
    {
        puts("FUCK!!");
    }

    fclose(src);
    fclose(des);

    return 0;
}