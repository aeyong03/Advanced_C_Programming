#include <stdio.h>

typedef enum
{
    Do,
    re,
    mi,
    fa,
    so,
    la,
    ti
} Syllable;

void Sound(Syllable s)
{
    switch (s)
    {
    case Do:
        puts("do is doraji");
        return;
    case re:
        puts("re is fuck");
        return;
    case ti:
        puts("tibal");
        return;
    }
}

int main()
{
    Syllable tone;
    for (tone = 0; tone <= ti; tone++)
    {
        Sound(tone);
    }
    return 0;
}
