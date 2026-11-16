#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 50

typedef struct
{
    int id;
    char title[100];
    int count;
} Book;

void initial_booklist(Book booklist[], int *book_cnt);
void manage_booklist(Book booklist[], int book_cnt, Book rentlist[], int *rent_cnt, int req_id);
void print_booklist(Book booklist[], int book_cnt);

int main()
{
    Book booklist[MAX_BOOKS];
    Book rentlist[MAX_BOOKS];
    int book_cnt = 0;
    int rent_cnt = 0;
    int req_id;

    initial_booklist(booklist, &book_cnt);
    if (book_cnt == 0)
    {
        printf("불러온 도서 정보가 없습니다.\n");
        return -1;
    }

    print_booklist(booklist, book_cnt);

    while (1)
    {
        printf("\n대여를 원하는 도서의 ID를 입력하세요 (목록 다시보기: -1, 종료: 0) : ");

        if (scanf("%d", &req_id) != 1)
        {
            printf("[오류] 숫자(도서 ID)만 입력해주세요.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (req_id == 0)
        {
            printf("도서 대여 프로그램을 종료합니다.\n");
            break;
        }
        else if (req_id == -1)
        {
            print_booklist(booklist, book_cnt);
            continue;
        }

        manage_booklist(booklist, book_cnt, rentlist, &rent_cnt, req_id);
    }

    return 0;
}

void print_booklist(Book booklist[], int book_cnt)
{
    printf("\n==================== 현재 보유 도서 목록 ====================\n");
    printf("%-10s %-38s %s\n", "도서 ID", "도서 제목", "보유 권수");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < book_cnt; i++)
    {
        printf("%-10d %-38s %d권\n", booklist[i].id, booklist[i].title, booklist[i].count);
    }
    printf("=============================================================\n");
}

void initial_booklist(Book booklist[], int *book_cnt)
{
    FILE *fp = fopen("books.txt", "rt");
    if (fp == NULL)
    {
        printf("books.txt 파일 열기 실패!\n");
        return;
    }

    char line[256];
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        fclose(fp);
        return;
    }

    int idx = 0;
    while (idx < MAX_BOOKS && fgets(line, sizeof(line), fp) != NULL)
    {
        int len = (int)strlen(line);

        while (len > 0 && isspace((unsigned char)line[len - 1]))
        {
            line[len - 1] = '\0';
            len--;
        }
        if (len == 0)
            continue;

        int num_start = len - 1;
        while (num_start >= 0 && isdigit((unsigned char)line[num_start]))
        {
            num_start--;
        }
        num_start++;

        if (num_start >= len)
            continue;

        booklist[idx].count = atoi(&line[num_start]);

        int title_end = num_start - 1;
        while (title_end >= 0 && isspace((unsigned char)line[title_end]))
        {
            line[title_end] = '\0';
            title_end--;
        }

        strncpy(booklist[idx].title, line, sizeof(booklist[idx].title) - 1);
        booklist[idx].title[sizeof(booklist[idx].title) - 1] = '\0';
        booklist[idx].id = 101 + idx;
        idx++;
    }

    *book_cnt = idx;
    fclose(fp);
}

void manage_booklist(Book booklist[], int book_cnt, Book rentlist[], int *rent_cnt, int req_id)
{
    int found_idx = -1;

    for (int i = 0; i < book_cnt; i++)
    {
        if (booklist[i].id == req_id)
        {
            found_idx = i;
            break;
        }
    }

    if (found_idx == -1)
    {
        printf("[알림] 해당 ID(%d)의 도서는 도서관에 보유하지 않은 도서입니다.\n", req_id);
        return;
    }

    if (booklist[found_idx].count <= 0)
    {
        printf("[알림] '%s' 도서는 현재 보유 도서가 모두 대여되었습니다.\n", booklist[found_idx].title);
        return;
    }

    booklist[found_idx].count--;

    int rent_found = -1;
    for (int i = 0; i < *rent_cnt; i++)
    {
        if (rentlist[i].id == req_id)
        {
            rent_found = i;
            break;
        }
    }

    if (rent_found != -1)
    {
        rentlist[rent_found].count++;
    }
    else
    {
        rentlist[*rent_cnt].id = booklist[found_idx].id;
        strcpy(rentlist[*rent_cnt].title, booklist[found_idx].title);
        rentlist[*rent_cnt].count = 1;
        (*rent_cnt)++;
    }

    printf("[완료] '%s' 도서가 정상적으로 대여되었습니다! (남은 보유 권수: %d권)\n",
           booklist[found_idx].title, booklist[found_idx].count);
}