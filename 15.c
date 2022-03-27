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

void add(const int *a, const int *b, int *ans) {
    int i, carry = 0;

    for (i = SIZE - 1; i >= 0; i--) {
        ans[i] = (a[i] + b[i] + carry) % 10;
        carry = (a[i] + b[i] + carry) / 10;
    }
}

void sub(const int *a, const int *b, int *ans) {
    int i, prev_borrow, curr_borrow = 0;

    for (i = SIZE - 1; i >= 0; i--) {
        prev_borrow = curr_borrow;
        curr_borrow = a[i] - prev_borrow < b[i];
        ans[i] = a[i] - prev_borrow - b[i] + 10 * curr_borrow;
    }

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

int main() {
    int operation, a[SIZE], b[SIZE], ans[SIZE];
    void (*func[3])(const int *, const int *, int *) = {add, sub, mul};

    operation = getchar() - '1';
    getchar();

    input(a);
    input(b);

    func[operation](a, b, ans);

    output(ans);
}
