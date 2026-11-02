#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 500
#define MAX_LEN 100

int my_strcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

void make_dictionary(char *words[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (my_strcmp(words[i], words[j]) > 0)
            {
                // 포인터 주소만 교환하여 정렬
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main()
{
    FILE *fp = fopen("words.txt", "rt");
    char *words[MAX_WORDS];
    int word_count = 0;

    char buffer[10000] = {0};
    fread(buffer, sizeof(char), sizeof(buffer) - 1, fp);
    fclose(fp);

    const char *delims = " \t;|,\r\n";

    char *token = strtok(buffer, delims);
    while (token != NULL)
    {
        if (strlen(token) > 0)
        {
            words[word_count] = (char *)malloc(strlen(token) + 1);
            strcpy(words[word_count], token);
            word_count++;
        }
        token = strtok(NULL, delims);
    }

    make_dictionary(words, word_count);

    FILE *out_fp = fopen("dictionary.txt", "wt");
    for (int i = 0; i < word_count; i++)
    {
        fprintf(out_fp, "%s\n", words[i]);
    }
    fclose(out_fp);

    printf("dictionary.txt 파일 저장이 완료되었습니다.\n");
    for (int i = 0; i < word_count; i++)
    {
        free(words[i]);
    }

    return 0;
}