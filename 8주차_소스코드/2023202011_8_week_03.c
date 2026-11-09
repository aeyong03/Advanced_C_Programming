#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int kor;
    int eng;
    float avg;
} Student;

typedef struct
{
    float kor_avg;
    float eng_avg;
    float total_avg;
} Summary;

int main()
{
    int count;

    printf("학생 수 입력: ");
    scanf("%d", &count);

    Student *s = (Student *)malloc(sizeof(Student) * count);
    if (s == NULL)
    {
        printf("메모리 할당 실패!\n");
        return -1;
    }

    int total_kor = 0;
    int total_eng = 0;
    float sum_student_avg = 0.0f;

    for (int i = 0; i < count; i++)
    {
        printf("%d번째 학생 이름, 국어 점수, 영어 점수 입력: ", i + 1);
        scanf("%s %d %d", (s + i)->name, &(s + i)->kor, &(s + i)->eng);

        (s + i)->avg = ((s + i)->kor + (s + i)->eng) / 2.0f;

        total_kor += (s + i)->kor;
        total_eng += (s + i)->eng;
        sum_student_avg += (s + i)->avg;
    }

    Summary summary;
    summary.kor_avg = (float)total_kor / count;
    summary.eng_avg = (float)total_eng / count;
    summary.total_avg = sum_student_avg / count;

    FILE *fp = fopen("average_strudent.txt", "wt");
    if (fp == NULL)
    {
        printf("파일 열기 실패!\n");
        free(s);
        return -1;
    }

    fprintf(fp, "-- 학생 성적 목록 --\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "이름: %s | 국어: %d | 영어: %d | 평균: %.2f\n",
                (s + i)->name, (s + i)->kor, (s + i)->eng, (s + i)->avg);
    }

    fprintf(fp, "\n-- 전체 요약 --\n");
    fprintf(fp, "국어 과목 평균: %.2f\n", summary.kor_avg);
    fprintf(fp, "영어 과목 평균: %.2f\n", summary.eng_avg);
    fprintf(fp, "모든 학생 총 평균: %.2f\n", summary.total_avg);

    fclose(fp);
    free(s);

    printf("average_strudent.txt에 결과를 성공적으로 저장했습니다.\n");
    return 0;
}