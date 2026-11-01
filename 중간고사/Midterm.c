#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *q)
{
    char*p;
    int i = 0;
    while (q[i] != '\0')
    {
        p[i] = q[i];
        i++;
    }
    p[i] = '\0';
    return p;
}

int main()
{
    
    char *q;
    q = "Hello";
    printf("%s\n", my_strcpy(q));
    return 0;
    
}