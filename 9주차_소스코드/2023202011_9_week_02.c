#include <stdio.h>

enum month
{
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

int main()
{
    enum month mon;
    int num;
    printf("월 입력 : ");
    scanf("%d", &num);
    mon = num;
    switch (mon)
    {
    case january:
        printf("%d월은 January 입니다.\n", mon);
        break;
    case february:
        printf("%d월은 February 입니다.\n", mon);
        break;
    case march:
        printf("%d월은 March 입니다.\n", mon);
        break;
    case april:
        printf("%d월은 April 입니다.\n", mon);
        break;
    case may:
        printf("%d월은 May 입니다.\n", mon);
        break;
    case june:
        printf("%d월은 June 입니다.\n", mon);
        break;
    case july:
        printf("%d월은 July 입니다.\n", mon);
        break;
    case august:
        printf("%d월은 August 입니다.\n", mon);
        break;
    case september:
        printf("%d월은 September 입니다.\n", mon);
        break;
    case october:
        printf("%d월은 October 입니다.\n", mon);
        break;
    case november:
        printf("%d월은 November 입니다.\n", mon);
        break;
    case december:
        printf("%d월은 December 입니다.\n", mon);
        break;
    default:
        printf("1~12 사이의 숫자를 입력하세요.\n");
        break;
    }
}