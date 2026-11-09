#include <stdio.h>
#include <string.h>

typedef struct
{
    char subject[50];
    int credit;
    char grade[5];
    double score;
} Subject;

int main()
{
    FILE *fp = fopen("grade.txt", "rt");
    if (fp == NULL)
    {
        printf("grade.txt 파일 열기 실패!\n");
        return -1;
    }

    Subject s;
    double total_score = 0.0;
    int total_credit = 0;

    printf("과목명\t\t과목별 점수\n");
    printf("---------------------------\n");

    char temp[100];
    fgets(temp, sizeof(temp), fp);

    while (fscanf(fp, "%s %d %s", s.subject, &s.credit, s.grade) != EOF)
    {
        double grade_point = 0.0;

        if (strcmp(s.grade, "A+") == 0)
            grade_point = 4.5;
        else if (strcmp(s.grade, "A0") == 0)
            grade_point = 4.0;
        else if (strcmp(s.grade, "B+") == 0)
            grade_point = 3.5;
        else if (strcmp(s.grade, "B0") == 0)
            grade_point = 3.0;
        else if (strcmp(s.grade, "C+") == 0)
            grade_point = 2.5;
        else if (strcmp(s.grade, "C0") == 0)
            grade_point = 2.0;
        else if (strcmp(s.grade, "D+") == 0)
            grade_point = 1.5;
        else if (strcmp(s.grade, "D0") == 0)
            grade_point = 1.0;
        else if (strcmp(s.grade, "F") == 0)
            grade_point = 0.0;

        s.score = s.credit * grade_point;

        printf("%-15s\t%.1f\n", s.subject, s.score);

        total_score += s.score;
        total_credit += s.credit;
    }

    if (total_credit > 0)
    {
        double gpa = total_score / total_credit;
        printf("---------------------------\n");
        printf("총 평점: %.2f\n", gpa);
    }

    fclose(fp);
    return 0;
}