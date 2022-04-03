#include <stdio.h>
#include <string.h>
#define SIZE 80

void input(int *arr) {
    int i, len;
    char buf[SIZE];

    scanf("%s", buf);
    getchar();
    len = strlen(buf);

    for (i = 0; i < SIZE; i++) {
        arr[i] = i < SIZE - len ? 0 : buf[i - (SIZE - len)] - '0';
    }
}

void output(const int *arr) {
    int i, is_zero = 1;

    for (i = 0; i < SIZE; i++) {
        if (arr[i] != 0)
            is_zero = 0;

        if (!is_zero)
            printf("%d", arr[i]);
    }

    if (is_zero)
        printf("0");

    printf("\n");
}

int cmp(const int *a, const int *b) {
    int i;

    for (i = 0; i < SIZE; i++) {
        if (a[i] > b[i])
            return 1;

        if (a[i] < b[i])
            return -1;
    }

    return 0;
}

size_t size(const int *n) {
    int s = SIZE;

    while(!n[SIZE - s])
        s--;

    return s;
}

void add(const int *a, const int *b, int *ans) {
    int i, carry = 0, tmp[SIZE];

    for (i = SIZE - 1; i >= 0; i--) {
        tmp[i] = (a[i] + b[i] + carry) % 10;
        carry = (a[i] + b[i] + carry) / 10;
    }

    memcpy(ans, tmp, SIZE * sizeof(int));
}

void sub(const int *a, const int *b, int *ans) {
    int i, prev_borrow, curr_borrow = 0, tmp[SIZE];

    for (i = SIZE - 1; i >= 0; i--) {
        prev_borrow = curr_borrow;
        curr_borrow = a[i] - prev_borrow < b[i];
        tmp[i] = a[i] - prev_borrow - b[i] + 10 * curr_borrow;
    }

    memcpy(ans, tmp, SIZE * sizeof(int));

    if (!curr_borrow)
        return;

    printf("-");
    sub(b, a, ans);
}

void mul(const int *a, const int *b, int *ans) {
    int i, j, tmp, carry;

    memset(ans, 0, sizeof(int) * SIZE);

    for (i = 0; i < SIZE; i++) {
        carry = 0;

        for (j = SIZE - 1; j >= 0; j--) {
            printf("%d %d\n", i, j);
            ans[j - i] += (a[j] * b[SIZE - 1 - i] + carry) % 10;
            carry = (a[j] * b[SIZE - 1 - i] + carry) / 10;
        }
    }

    for (i = SIZE - 1; i >= 0; i--) {
        tmp = (ans[i] + carry) % 10;
        carry = (ans[i] + carry) / 10;
        ans[i] = tmp;
    }
}

void div(const int *a, const int *b, int *ans) {
    int i, size_a, size_b, res, a_cpy[SIZE], b_cpy[SIZE];

    memset(ans, 0, SIZE * sizeof(int));
    if (!cmp(a, b)) {
        ans[SIZE - 1] = 1;
        return;
    }

    memcpy(a_cpy, a, SIZE * sizeof(int));
    size_a = size(a);
    size_b = size(b);

    while (size_a >= size_b) {
        memset(b_cpy, 0, SIZE * sizeof(int));
        for (i = SIZE / 2; i < SIZE; i++)
            b_cpy[i - (size_a - size_b)] = b[i];

        for (i = 0; i < SIZE; i++) {
            res = cmp(a_cpy, b_cpy);

            if (res == 0) {
                ans[SIZE - 1 - (size_a - size_b)] = i + 1;
                break;
            } else if (res == -1) {
                ans[SIZE - 1 - (size_a - size_b)] = i;
                break;
            } else {
                sub(a_cpy, b_cpy, a_cpy);
            }
        }

        size_a--;
    }
}

int main() {
    int a[SIZE], b[SIZE], ans[SIZE];

    input(a);
    input(b);

    div(a, b, ans);

    output(ans);

    return 0;
}
