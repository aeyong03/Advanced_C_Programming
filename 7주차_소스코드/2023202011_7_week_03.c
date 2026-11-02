#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char menu_names[20][50];
    int menu_prices[20];
    int menu_count = 0;

    FILE *rfp = fopen("menu.txt", "rt");
    if (rfp == NULL)
    {
        printf("menu.txt 파일 열기 실패!\n");
        return -1;
    }

    char line[100];
    fgets(line, sizeof(line), rfp);

    while (menu_count < 20 &&
           fscanf(rfp, "%49s %d", menu_names[menu_count], &menu_prices[menu_count]) == 2)
    {
        menu_count++;
    }
    fclose(rfp);

    char *selected_names[100];
    int selected_prices[100];
    int select_count = 0;
    int total_price = 0;

    while (1)
    {
        printf("\n[MENU]\n");
        for (int i = 0; i < menu_count; i++)
        {
            printf("[%d] %-15s : %d\n", i + 1, menu_names[i], menu_prices[i]);
        }

        int choice;
        printf("메뉴 번호를 선택하세요 (0번 입력 시 종료) : ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice < 0 || choice > menu_count)
        {
            printf("잘못된 메뉴 번호입니다. 다시 선택해주세요.\n");
            continue;
        }

        int idx = choice - 1;
        printf("선택한 메뉴: %s : %d\n", menu_names[idx], menu_prices[idx]);

        int name_len = strlen(menu_names[idx]);
        selected_names[select_count] = (char *)malloc(sizeof(char) * (name_len + 1));
        strcpy(selected_names[select_count], menu_names[idx]);

        selected_prices[select_count] = menu_prices[idx];
        total_price += menu_prices[idx];

        select_count++;
    }

    FILE *wfp = fopen("receipt.txt", "wt");
    if (wfp == NULL)
    {
        printf("receipt.txt 파일 생성 실패!\n");
        return -1;
    }

    printf("\n==== 영수증 (receipt.txt) ====\n");
    for (int i = 0; i < select_count; i++)
    {
        printf("%d\t%s : %d\n", i + 1, selected_names[i], selected_prices[i]);
        fprintf(wfp, "%d\t%s : %d\n", i + 1, selected_names[i], selected_prices[i]);
    }
    printf("결제금액 : %d\n", total_price);
    fprintf(wfp, "결제금액 : %d\n", total_price);

    fclose(wfp);

    for (int i = 0; i < select_count; i++)
    {
        free(selected_names[i]);
    }

    return 0;
}