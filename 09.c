#include <stdio.h>

void binary_to_gray_code(int digits, int n) {
    int i, gray_code;

    gray_code = n ^ (n >> 1);

    for (i = digits - 1; i >= 0; i++)
        printf("%d", (gray_code & (1 << i)) ? 1 : 0);


    printf("\n");
}

int main() {
    int ended = 0, digits, n;

    while (!ended) {
        scanf("%d%d", &digits, &n);
        binary_to_gray_code(digits, n);

        scanf("%d", &ended);
    }

    return 0;
}
