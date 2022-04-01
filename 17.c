#include <stdio.h>
#include <string.h>

int main() {
    int i, len, is_zero = 1, decimal = 0, base7[6];
    char input[15];

    scanf("%s", input);
    getchar();

    len = strlen(input);

    for(i = 0; i < len; i++) {
        if (input[i] >= '2') {
            printf("ERROR\n");
            return 0;
        }

        decimal += (input[len - 1 - i] - '0') << i;
    }

    if(decimal == 0) {
        printf("0\n");
        return 0;
    }

    for(i = 5; i >= 0; i--) {
        base7[i] = decimal % 7;
        decimal /= 7;
    }

    for(i = 0; i < 6; i++) {
        if (base7[i])
            is_zero = 0;

        if (!is_zero)
            printf("%d", base7[i]);
    }
    printf("\n");


    return 0;
}
