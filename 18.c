#include <stdio.h>
#include <string.h>

#define SIZE 30

int collide(char *arr, int offset, int width) {
    int i, j, pass = 1;

    for (i = offset; i < width + offset; i++) {
        for (j = i + 1; j < width + offset; j++) {
            if (!(arr[i] * arr[j]))
                pass = 0;

            if (arr[i] == arr[j])
                pass = 0;
        }
    }

    return pass;
}

int main() {
    int i, len = 0, width, res = 0;
    char ch = 0, arr[SIZE];

    memset(arr, 0, SIZE * sizeof(char));

    while (1) {
        ch = getchar();

        if (ch == '\n')
            break;

        arr[len] = ch;
        len++;
    }

    scanf("%d", &width);

    for (i = 0; i < len; i++)
        res += collide(arr, i, width);

    printf("%d\n", res);

    return 0;
}
