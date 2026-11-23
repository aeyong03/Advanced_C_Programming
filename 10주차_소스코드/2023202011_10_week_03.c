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

void load_books_from_file(const char *filename, Book list[], int *cnt);
void save_books_to_file(const char *filename, Book list[], int cnt);
void manage_booklist(Book booklist[], int book_cnt, Book rentlist[], int *rent_cnt, int req_id);
void print_booklist(const char *header, Book list[], int cnt);
int admin_check();
void expand_stock(Book booklist[], int book_cnt, Book storagelist[], int storage_cnt);

int main(int argc, char *argv[])
{
    Book booklist[MAX_BOOKS];
    Book storagelist[MAX_BOOKS];
    Book rentlist[MAX_BOOKS];
    int book_cnt = 0;
    int storage_cnt = 0;
    int rent_cnt = 0;
    int req_id;

    load_books_from_file("books.txt", booklist, &book_cnt);
    if (book_cnt == 0)
    {
        printf("불러온 도서 정보가 없습니다.\n");
        return -1;
    }

    if (argc >= 2 && strcmp(argv[1], "admin") == 0)
    {
        if (!admin_check())
        {
            printf("관리자 인증에 실패하여 프로그램을 종료합니다.\n");
            return 0;
        }

        print_booklist("보충 전 현재 보유 도서 목록", booklist, book_cnt);

        load_books_from_file("storage.txt", storagelist, &storage_cnt);
        if (storage_cnt > 0)
        {
            expand_stock(booklist, book_cnt, storagelist, storage_cnt);
            save_books_to_file("storage.txt", storagelist, storage_cnt);

            print_booklist("재고 보충 후 보유 도서 목록", booklist, book_cnt);
            print_booklist("창고(storage.txt) 잔여 도서 현황", storagelist, storage_cnt);
        }

        int mode_choice;
        printf("\n서비스 모드로 전환하시겠습니까? (1: 전환, 0: 종료) : ");
        scanf("%d", &mode_choice);
        if (mode_choice != 1)
        {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
    }

    print_booklist("현재 보유 도서 목록", booklist, book_cnt);

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
            print_booklist("현재 보유 도서 목록", booklist, book_cnt);
            continue;
        }

        manage_booklist(booklist, book_cnt, rentlist, &rent_cnt, req_id);
    }

    return 0;
}

int admin_check()
{
    FILE *fp = fopen("admin_auth.txt", "rt");
    if (fp == NULL)
    {
        printf("admin_auth.txt 파일 열기 실패!\n");
        return 0;
    }

    char file_id[50], file_pw[50];
    if (fscanf(fp, "%s %s", file_id, file_pw) != 2)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);

    char input_id[50], input_pw[50];
    printf("=== 관리자 로그인 ===\n");
    printf("ID : ");
    scanf("%s", input_id);
    printf("PW : ");
    scanf("%s", input_pw);

    if (strcmp(file_id, input_id) == 0 && strcmp(file_pw, input_pw) == 0)
    {
        printf("관리자 인증 성공!\n");
        return 1;
    }

    return 0;
}

void expand_stock(Book booklist[], int book_cnt, Book storagelist[], int storage_cnt)
{
    for (int i = 0; i < book_cnt; i++)
    {
        if (booklist[i].count == 0)
        {
            for (int j = 0; j < storage_cnt; j++)
            {
                if (strcmp(booklist[i].title, storagelist[j].title) == 0 && storagelist[j].count > 0)
                {
                    int bring = (storagelist[j].count >= 3) ? 3 : storagelist[j].count;
                    booklist[i].count += bring;
                    storagelist[j].count -= bring;
                    break;
                }
            }
        }
    }
}

void print_booklist(const char *header, Book list[], int cnt)
{
    printf("\n==================== %s ====================\n", header);
    printf("%-10s %-38s %s\n", "도서 ID", "도서 제목", "권수");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < cnt; i++)
    {
        printf("%-10d %-38s %d권\n", list[i].id, list[i].title, list[i].count);
    }
    printf("=============================================================\n");
}

void load_books_from_file(const char *filename, Book list[], int *cnt)
{
    FILE *fp = fopen(filename, "rt");
    if (fp == NULL)
    {
        printf("%s 파일 열기 실패!\n", filename);
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

        list[idx].count = atoi(&line[num_start]);

        int title_end = num_start - 1;
        while (title_end >= 0 && isspace((unsigned char)line[title_end]))
        {
            line[title_end] = '\0';
            title_end--;
        }

        strncpy(list[idx].title, line, sizeof(list[idx].title) - 1);
        list[idx].title[sizeof(list[idx].title) - 1] = '\0';
        list[idx].id = 101 + idx;
        idx++;
    }

    *cnt = idx;
    fclose(fp);
}

void save_books_to_file(const char *filename, Book list[], int cnt)
{
    FILE *fp = fopen(filename, "wt");
    if (fp == NULL)
        return;

    fprintf(fp, "Book_Name\t\tCount\n");
    for (int i = 0; i < cnt; i++)
    {
        fprintf(fp, "%s\t%d\n", list[i].title, list[i].count);
    }
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