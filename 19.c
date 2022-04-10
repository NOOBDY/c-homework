#include <stdio.h>
#include <string.h>

#define SIZE 100

void df(const char *exp, char *ans, const int max_width, int *index, int width, int offset_x, int offset_y) {
    int i, j;

    (*index)++;

    switch (exp[*index]) {
        case '1':
            for (i = offset_x; i < offset_x + width; i++)
                for (j = offset_y; j < offset_y + width; j++)
                    ans[max_width * i + j] = 1;

            break;

        case '2':
            width /= 2;

            for (i = 0; i < 4; i++)
                df(exp, ans, max_width, index, width,
                        offset_x + width * (i >= 2), offset_y + width * (i % 2));

            break;
    }
}

int main() {
    int i, width, index = -1;
    char exp[SIZE];
    char ans[SIZE * SIZE];
    memset(exp, 0, sizeof(exp));
    memset(ans, 0, sizeof(ans));

    scanf("%s", exp);
    getchar();

    scanf("%d", &width);
    getchar();

    if (exp[0] == '0') {
        printf("all white\n");
        return 0;
    }

    df(exp, ans, width, &index, width, 0, 0);

    for (i = 0; i < width * width; i++) {
        if (ans[i])
            printf("%d,%d\n", i / width, i % width);
    }

    return 0;
}
