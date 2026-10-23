#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **ptr = (char **)malloc(sizeof(char*) * 3 + 1);
    ptr[0] = "Hi";
    ptr[1] = "HELLO";
    ptr[2] = "안 녕";
    for (int i = 0; i < 3; i++)
    {
        int size = (int)strlen(ptr[i]);
        ptr[i][size ] = '\0';
        printf("%s\n", ptr[i]);
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}