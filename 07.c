#include <stdio.h>

void calculate_score(float *score) {
    int input;

    input = getchar();
    /* negate newline character */
    while (getchar() >= '0') /* using >= '0' to include both \n and EOF */
        continue;

    if (*score != -1) {
        switch (input) {
            case 'A':
                *score += 1;
                break;

            case '1': /* the first character in 10 is unique in this case so */
                *score += 10;
                break;

            case 'J':
            case 'Q':
            case 'K':
                *score += 0.5;
                break;

            default:
                *score += (int)input - '0';
                break;
        }
    }

    if (*score > 10.5)
        *score = -1;

}

int main() {
    int i;
    float scores[2] = {0};

    for (i = 0; i < 6; i++)
        calculate_score(&(scores[(i > 2)]));

    printf("%.1f\n%.1f\n",
            scores[0] == -1 ? 0 : scores[0],
            scores[1] == -1 ? 0 : scores[1]);

    if (scores[0] != scores[1])
        printf("%c wins.\n", scores[0] > scores[1] ? 'A' : 'B');

    else
        printf("It's a tie.");

    return 0;
}
