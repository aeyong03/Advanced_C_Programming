#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU 20

typedef struct
{
    int id;
    char name[50];
    double price;
    int order_cnt;
} Drink;

typedef struct
{
    int id;
    char name[50];
    double price;
    int order_cnt;
} Dessert;

void Initial_menulist(Drink drinks[], int *drink_cnt, Dessert desserts[], int *dessert_cnt);
void drink_count(Drink drinks[], int drink_cnt);
void dessert_count(Dessert desserts[], int dessert_cnt);
void print_receipt(Drink drinks[], int drink_cnt, Dessert desserts[], int dessert_cnt);

int main()
{
    Drink drinks[MAX_MENU];
    Dessert desserts[MAX_MENU];
    int drink_cnt = 0;
    int dessert_cnt = 0;
    int choice;

    Initial_menulist(drinks, &drink_cnt, desserts, &dessert_cnt);

    while (1)
    {
        printf("\n1. 음료 주문하기\n");
        printf("2. 디저트 주문하기\n");
        printf("0. 종료\n");
        printf(":: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            print_receipt(drinks, drink_cnt, desserts, dessert_cnt);
            break;
        }
        else if (choice == 1)
        {
            drink_count(drinks, drink_cnt);
        }
        else if (choice == 2)
        {
            dessert_count(desserts, dessert_cnt);
        }
        else
        {
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

void Initial_menulist(Drink drinks[], int *drink_cnt, Dessert desserts[], int *dessert_cnt)
{
    FILE *fp_drink = fopen("drink.txt", "rt");
    if (fp_drink != NULL)
    {
        int idx = 0;
        while (idx < MAX_MENU && fscanf(fp_drink, "%s %lf", drinks[idx].name, &drinks[idx].price) == 2)
        {
            drinks[idx].id = idx + 1;
            drinks[idx].order_cnt = 0;
            idx++;
        }
        *drink_cnt = idx;
        fclose(fp_drink);
    }
    else
    {
        printf("drink.txt 파일 열기 실패!\n");
    }

    FILE *fp_dessert = fopen("dessert.txt", "rt");
    if (fp_dessert != NULL)
    {
        int idx = 0;
        while (idx < MAX_MENU && fscanf(fp_dessert, "%s %lf", desserts[idx].name, &desserts[idx].price) == 2)
        {
            desserts[idx].id = idx + 1;
            desserts[idx].order_cnt = 0;
            idx++;
        }
        *dessert_cnt = idx;
        fclose(fp_dessert);
    }
    else
    {
        printf("dessert.txt 파일 열기 실패!\n");
    }
}

void drink_count(Drink drinks[], int drink_cnt)
{
    int select_id;

    printf("주문하실 음료를 선택하세요\n");
    printf("drink menues\n");
    for (int i = 0; i < drink_cnt; i++)
    {
        printf("[%d] %-20s %.2f\n", drinks[i].id, drinks[i].name, drinks[i].price);
    }

    scanf("%d", &select_id);

    if (select_id >= 1 && select_id <= drink_cnt)
    {
        drinks[select_id - 1].order_cnt++;
    }
    else
    {
        printf("존재하지 않는 음료 번호입니다.\n");
    }
}

void dessert_count(Dessert desserts[], int dessert_cnt)
{
    int select_id;

    printf("주문하실 디저트를 선택하세요\n");
    printf("dessert menues\n");
    for (int i = 0; i < dessert_cnt; i++)
    {
        printf("[%d] %-20s %.2f\n", desserts[i].id, desserts[i].name, desserts[i].price);
    }

    scanf("%d", &select_id);

    if (select_id >= 1 && select_id <= dessert_cnt)
    {
        desserts[select_id - 1].order_cnt++;
    }
    else
    {
        printf("존재하지 않는 디저트 번호입니다.\n");
    }
}

void print_receipt(Drink drinks[], int drink_cnt, Dessert desserts[], int dessert_cnt)
{
    FILE *fp = fopen("Receipt.txt", "wt");
    if (fp == NULL)
    {
        printf("Receipt.txt 파일 생성 실패!\n");
        return;
    }

    double total = 0.0;

    fprintf(fp, "Receipt\n\n");
    printf("\nReceipt\n\n");

    for (int i = 0; i < drink_cnt; i++)
    {
        if (drinks[i].order_cnt > 0)
        {
            double sub = drinks[i].price * drinks[i].order_cnt;
            fprintf(fp, "%-20s %d   %.2f\n", drinks[i].name, drinks[i].order_cnt, sub);
            printf("%-20s %d   %.2f\n", drinks[i].name, drinks[i].order_cnt, sub);
            total += sub;
        }
    }

    for (int i = 0; i < dessert_cnt; i++)
    {
        if (desserts[i].order_cnt > 0)
        {
            double sub = desserts[i].price * desserts[i].order_cnt;
            fprintf(fp, "%-20s %d   %.2f\n", desserts[i].name, desserts[i].order_cnt, sub);
            printf("%-20s %d   %.2f\n", desserts[i].name, desserts[i].order_cnt, sub);
            total += sub;
        }
    }

    fprintf(fp, "\nTotal ::                 %.2f\n", total);
    printf("\nTotal ::                 %.2f\n", total);

    fclose(fp);
    printf("영수증이 Receipt.txt에 저장되었습니다.\n");
}