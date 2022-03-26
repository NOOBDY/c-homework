#include <stdio.h>

int check(char *target) {
    int i, j, a = 0, b = 0;
    char ans[4];

    fgets(ans, 5, stdin);
    getchar();

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (target[i] == ans[j]) {
                if (i == j)
                    a++;

                else
                    b++;
            }
        }
    }

    if (a == 4) {
        printf("win\n");
        return 1;
    }

    printf("%dA%dB\n", a, b);
    return 0;
}

int main() {
    int i, status = 0;
    char target[4];

    fgets(target, 5, stdin);
    getchar();

    for (i = 0; i < 6; i++) {
        status = check(target);

        if (status)
            break;
    }

    return 0;
}
