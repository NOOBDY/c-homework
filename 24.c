#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char id[10];
    float avg_score;
} Student;

typedef enum {
    G,
    GPA,
    S
} GradeType;

GradeType get_type() {
    char input[5];

    scanf("%s", input);
    getchar();

    if (strcmp(input, "G") == 0)
        return G;
    else if (strcmp(input, "GPA") == 0)
        return GPA;
    else
        return S;
}

float get_grade() {
    char grade[3];

    scanf("%s", grade);
    getchar();

    if (strcmp(grade, "A+") == 0) return 95;
    else if (strcmp(grade, "A") == 0) return 87;
    else if (strcmp(grade, "A-") == 0) return 82;
    else if (strcmp(grade, "B+") == 0) return 78;
    else if (strcmp(grade, "B") == 0) return 75;
    else if (strcmp(grade, "B-") == 0) return 70;
    else if (strcmp(grade, "C+") == 0) return 68;
    else if (strcmp(grade, "C") == 0) return 65;
    else if (strcmp(grade, "C-") == 0) return 60;
    else return 50;
}

float get_gpa() {
    float gpa;

    scanf("%f", &gpa);
    getchar();

    if (gpa == 4.3f) return 95;
    else if (gpa == 4.0f) return 87;
    else if (gpa == 3.7f) return 82;
    else if (gpa == 3.3f) return 78;
    else if (gpa == 3.0f) return 75;
    else if (gpa == 2.7f) return 70;
    else if (gpa == 2.3f) return 68;
    else if (gpa == 2.0f) return 65;
    else if (gpa == 1.7f) return 60;
    else return 50;
}

float get_score() {
    char s[7];

    scanf("%s", s);
    getchar();

    if (strcmp(s, "90-100") == 0) return 95;
    else if (strcmp(s, "85-89") == 0) return 87;
    else if (strcmp(s, "80-84") == 0) return 82;
    else if (strcmp(s, "77-79") == 0) return 78;
    else if (strcmp(s, "73-76") == 0) return 75;
    else if (strcmp(s, "70-72") == 0) return 70;
    else if (strcmp(s, "67-69") == 0) return 68;
    else if (strcmp(s, "63-66") == 0) return 65;
    else if (strcmp(s, "60-62") == 0) return 60;
    else return 50;
}

void get_avg(Student *student, GradeType *types, int course_count) {
    int i;
    float total = 0;

    scanf("%s", student->id);
    getchar();

    for (i = 0; i < course_count; i++) {
        switch (types[i]) {
            case G:
                total += get_grade();
                break;

            case GPA:
                total += get_gpa();
                break;

            case S:
                total += get_score();
                break;
        }

    }

    student->avg_score = total / course_count;
}

int cmp(const void *a, const void *b) {
    if (((Student *)a)->avg_score > ((Student *)b)->avg_score)
        return -1;

    if (((Student *)a)->avg_score < ((Student *)b)->avg_score)
        return 1;

    return 0;
}

int main() {
    int i, course_count, student_count;
    Student students[10];
    GradeType types[10];

    scanf("%d", &course_count);
    getchar();

    for (i = 0; i < course_count; i++)
        types[i] = get_type();

    scanf("%d", &student_count);
    getchar();

    for (i = 0; i < student_count; i++) {
        get_avg(&students[i], types, course_count);

    }

    qsort(students, student_count, sizeof(Student), cmp);

    for (i = 0; i < 3; i++) {
        printf("%s\n%d\n", students[i].id, (int)(students[i].avg_score + 0.5));
    }

    return 0;
}
