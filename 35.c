#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 200
#define FIXED_HALF_LEN 100

typedef struct {
    int sign;
    int digits[FIXED_HALF_LEN * 3];
} Fixed;

void to_fixed(Fixed *num, char *str) {
    int i, len;

    memset(num, 0, sizeof(Fixed));

    if (str[0] == '-')
        num->sign = 1;

    str += num->sign;

    len = strcspn(str, ".");

    for (i = 0; i < FIXED_HALF_LEN; i++) {
        num->digits[i] = i >= FIXED_HALF_LEN - len ? str[i - FIXED_HALF_LEN + len] - '0' : 0;
    }

    str += len + 1;
    len = strlen(str);

    for (i = 0; i < FIXED_HALF_LEN; i++) {
        num->digits[i + FIXED_HALF_LEN] = i < len ? str[i] - '0' : 0;
    }
}

void read_input(Fixed *a, Fixed *b) {
    char a_str[BUF_SIZE];
    char b_str[BUF_SIZE];

    fgets(a_str, BUF_SIZE, stdin);
    a_str[strcspn(a_str, "\n")] = 0;

    fgets(b_str, BUF_SIZE, stdin);
    b_str[strcspn(b_str, "\n")] = 0;

    to_fixed(a, a_str);
    to_fixed(b, b_str);
}

void print_fixed(const Fixed num) {
    int i, start = 0, end = 0;

    for (i = 0; i < FIXED_HALF_LEN * 2; i++) {
        if (num.digits[i])
            break;
    }

    if (i == FIXED_HALF_LEN * 2) {
        printf("0\n");
        return;
    }

    if (num.sign)
        printf("-");

    for (i = 0; i < FIXED_HALF_LEN; i++) {
        if (start)
            printf("%d", num.digits[i]);

        if (num.digits[i + 1])
            start = 1;
    }

    printf(".");

    for (i = FIXED_HALF_LEN; i < FIXED_HALF_LEN * 2; i++) {
        if (num.digits[i] == 0)
            end++;
        else
            end = 0;
    }

    for (i = FIXED_HALF_LEN; i < FIXED_HALF_LEN * 2 - end; i++) {
        printf("%d", num.digits[i]);
    }

    printf("\n");
}

void print_fixed_raw(const Fixed num) {
    int i;
    for (i = 0; i < FIXED_HALF_LEN * 2; i++) {
        printf("%d", num.digits[i]);
    }

    printf("\n");
}

int abs_cmp(const Fixed *a, const Fixed *b) {
    int i;

    for (i = 0; i < FIXED_HALF_LEN * 2; i++) {
        if (a->digits[i] > b->digits[i])
            return 1;

        if (a->digits[i] < b->digits[i])
            return -1;
    }

    return 0;
}

Fixed add(const Fixed *a, const Fixed *b) {
    int i, carry = 0;
    Fixed ans;

    for (i = FIXED_HALF_LEN * 2 - 1; i >= 0; i--) {
        ans.digits[i] = (a->digits[i] + b->digits[i] + carry) % 10;
        carry = (a->digits[i] + b->digits[i] + carry) / 10;
    }

    return ans;
}

Fixed sub(const Fixed *a, const Fixed *b) {
    int i, prev_borrow, curr_borrow = 0;
    Fixed ans;

    for (i = FIXED_HALF_LEN * 2 - 1; i >= 0; i--) {
        prev_borrow = curr_borrow;
        curr_borrow = a->digits[i] - prev_borrow < b->digits[i];
        ans.digits[i] = a->digits[i] - prev_borrow - b->digits[i] + 10 * curr_borrow;
    }

    return ans;
}

Fixed mul(const Fixed *a, const Fixed *b) {
    int i, j, carry = 0, tmp = 0;
    Fixed ans;

    memset(ans.digits, 0, sizeof(ans.digits));

    for (i = -FIXED_HALF_LEN; i < FIXED_HALF_LEN; i++) {
        for (j = FIXED_HALF_LEN * 2 - 1; j >= 0; j--) {
            tmp = (a->digits[j] * b->digits[i + FIXED_HALF_LEN] +
                    ((j + i + 1 >= FIXED_HALF_LEN * 2 || j + i + 1 < 0) ? 0 : ans.digits[j + i + 1]) +
                    carry);

            ans.digits[j + i + 1] = tmp % 10;
            carry = tmp / 10;
        }
    }

    ans.sign = a->sign ^ b->sign;
    print_fixed(ans);
    return ans;
}

int main() {
    Fixed a, b, ans;

    read_input(&a, &b);

    /* real add */
    if (a.sign ^ b.sign) {
        switch (abs_cmp(&a, &b)) {
            case 1:
                ans = sub(&a, &b);
                ans.sign = a.sign;
                break;
            case -1:
                ans = sub(&b, &a);
                ans.sign = b.sign;
                break;
            default:
                memset(&ans, 0, sizeof(Fixed));
                break;
        }
    } else {
        ans = add(&a, &b);
        ans.sign = a.sign;
    }

    print_fixed(ans);

    /* real sub */
    if (a.sign ^ b.sign) {
        ans = add(&a, &b);
        ans.sign = a.sign;
    } else {
        switch (abs_cmp(&a, &b)) {
            case 1:
                ans = sub(&a, &b);
                ans.sign = a.sign;
                break;
            case -1:
                ans = sub(&b, &a);
                ans.sign = !b.sign;
                break;
            default:
                memset(&ans, 0, sizeof(Fixed));
                break;
        }
    }

    print_fixed(ans);

    mul(&a, &b);

    return 0;
}
