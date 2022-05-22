#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    int data[20];
} Array;

void output(const Array arr) {
    int i;

    for (i = 0; i < arr.len; i++)
        printf("%d ", arr.data[i]);

    printf("\n");
}

int cmp(const void *a, const void *b) {
    int i;

    const Array *aa = a;
    const Array *bb = b;

    for (i = 0; i < sizeof(int [20]);i++) {
        if (aa->data[i] < bb->data[i])
            return -1;

        if (aa->data[i] > bb->data[i])
            return 1;
    }

    return 0;
}

int main() {
    int i, j, n, m;
    Array matrix[20];

    scanf("%d", &n);
    scanf("%d", &m);
    getchar();

    for (i = 0; i < n; i++) {
        matrix[i].len = m;

        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i].data[j]);
        }

        getchar();
    }

    qsort(matrix, n, sizeof(Array), cmp);

    for (i = 0; i < n; i++)
        output(matrix[i]);

    return 0;
}
