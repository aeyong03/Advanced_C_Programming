#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("grade.txt", "rt");
    char temp[100];
    fgets("temp", sizeof(temp), fp);
    char subject[50];
    char grade[10];
    int credit;
    double total_score = 0;
    int total_credit = 0;

    while (fscanf(fp, "%s %d %s", subject, &credit, grade) != EOF)
    {

        double score = 0.0;

        if (strcmp(grade, "A+") == 0)
            score = 4.5;
        else if (strcmp(grade, "A0") == 0)
            score = 4.0;
        else if (strcmp(grade, "B+") == 0)
            score = 3.5;
        else if (strcmp(grade, "B0") == 0)
            score = 3.0;
        else if (strcmp(grade, "C+") == 0)
            score = 2.5;
        else if (strcmp(grade, "C0") == 0)
            score = 2.0;
        else if (strcmp(grade, "D+") == 0)
            score = 1.5;
        else if (strcmp(grade, "D0") == 0)
            score = 1.0;
        else if (strcmp(grade, "F") == 0)
            score = 0.0;

        double subject_score = credit * score;
        printf("%-15s\t%.1f\n", subject, subject_score);

        total_score += subject_score;
        total_credit += credit;
    }

    if (total_credit > 0)
    {
        double gpa = total_score / total_credit;
        printf("---------------------------\n");
        printf("총 평점: %.2f\n", gpa);
        printf("%.2f", total_score);
        printf("\n%.2d", total_credit);
    }

    fclose(fp);
    return 0;
}