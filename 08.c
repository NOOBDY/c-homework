#include <stdio.h>
#include <stdlib.h>

void one(int n) {
    int i, j, count;

    for (i = 0; i < n; i++) {
        count = (n + 1) / 2 - abs(i - (n - 1) / 2);

        for (j = 0; j < count; j++)
            printf("*");

        printf("\n");

    }
}

void two(int n) {
    int i, j, count;

    for (i = 0; i < n; i++) {
        count = abs(i - (n - 1) / 2);

        for (j = 0; j < count; j++)
            printf(".");

        for (j = 0; j < (n + 1) / 2 - count; j++)
            printf("*");

        printf("\n");

    }
}

void three(int n) {
    int i, j, count;

    for (i = 0; i < n; i++) {
        count = abs(i - (n - 1) / 2);

        for (j = 0; j < count; j++)
            printf(".");

        for (j = 0; j < n - count * 2; j++)
            printf("*");

        printf("\n");
    }
}

int main() {
    int type, len;
    void (*func[])(int) = {one, two, three};

    scanf("%d", &type);
    scanf("%d", &len);
    getchar();

    (*func[type - 1])(len);

    return 0;
}
