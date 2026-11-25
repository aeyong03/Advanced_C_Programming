#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char menu_index[20][20];
    int price_index[20];
    int i = 0;
    char menu_temp[20];
    int price_temp;
    int choice = 1;
    char *total_menu[100];
    int total_price = 0;

    FILE *fp = fopen("menu.txt", "rt");
    while (fgetc(fp) != '\n')
        ;

    while (fscanf(fp, "%s %d", menu_temp, &price_temp) != EOF)
    {
        strcpy(menu_index[i], menu_temp);
        price_index[i] = price_temp;
        i++;
    }
    fclose(fp);

    int order_count = 0;

    while (1)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d: %-15s %d\n", j + 1, menu_index[j], price_index[j]);
        }
        puts("메뉴 번호 골라라 주문 끝났으면 0 누르고 항상 겸손해라.");
        scanf("%d", &choice);
        if (choice == 0)
        {
            puts("그만 먹기로 했구나 아주 좋은 생각이야 계산하고 나가렴");
            break;
        }
        printf("니가 고른 메뉴 : %s %d원 내놔\n", menu_index[choice - 1], price_index[choice - 1]);

        total_price += price_index[choice - 1];
        total_menu[order_count] = (char *)malloc(sizeof(char) * (strlen(menu_index[choice - 1]) + 1));
        strcpy(total_menu[order_count], menu_index[choice - 1]);
        order_count++;
    }

    fp = fopen("receipt.txt", "wt");
    if (fp == NULL)
    {
        puts("FUCK!!");
        return -1;
    }
    fputs("Your choice menu\n\n", fp);
    for (int j = 0; j < order_count; j++)
    {
        fprintf(fp, "%s\n", total_menu[j]);
        free(total_menu[j]);
    }
    fprintf(fp, "\n\nshow me the money : %d\n", total_price);

    fclose(fp);
    return 0;
}