#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

void get_frac(Fraction *n) {
    scanf("%d", &(n->numerator));
    getchar();
    scanf("%d", &(n->denominator));
    getchar();
}

int abs(int n) {
    return n >= 0 ? n : -n;
}

void print_frac(Fraction n) {
    int temp, n1, n2;

    /* find GCD */
    n1 = n.numerator;
    n2 = n.denominator;

    while (n2 != 0) {
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }

    n.numerator /= n1;
    n.denominator /= n1;

    n.numerator = (n.numerator * n.denominator) / abs(n.denominator);
    n.denominator = abs(n.denominator);

    if (n.denominator == 1) {
        printf("%d\n", n.numerator);
        return;
    }

    if (abs(n.numerator) > n.denominator) {
        printf("%d(%d/%d)\n",
                n.numerator / n.denominator,
                abs(n.numerator) % n.denominator,
                n.denominator
        );

        return;
    }

    printf("%d/%d\n", n.numerator, n.denominator);
}

Fraction add(Fraction n1, Fraction n2) {
    Fraction res;
    res.numerator = n1.numerator * n2.denominator + n2.numerator * n1.denominator;
    res.denominator = n1.denominator * n2.denominator;

    return res;
}

Fraction sub(Fraction n1, Fraction n2) {
    Fraction res;
    res.numerator = n1.numerator * n2.denominator - n2.numerator * n1.denominator;
    res.denominator = n1.denominator * n2.denominator;

    return res;
}

Fraction mul(Fraction n1, Fraction n2) {
    Fraction res;
    res.numerator = n1.numerator * n2.numerator;
    res.denominator = n1.denominator * n2.denominator;

    return res;
}

Fraction div(Fraction n1, Fraction n2) {
    Fraction res;
    res.numerator = n1.numerator * n2.denominator;
    res.denominator = n1.denominator * n2.numerator;

    return res;
}

int main() {
    char operation, ch = 'y';
    Fraction n1, n2;

    while (ch == 'y') {
        get_frac(&n1);
        get_frac(&n2);

        operation = getchar();
        getchar();

        ch = getchar();
        getchar();

        if (!(n1.denominator * n2.denominator)) {
            printf("ERROR\n");
            continue;
        }

        switch (operation) {
            case '+':
                print_frac(add(n1, n2));
                break;

            case '-':
                print_frac(sub(n1, n2));
                break;

            case '*':
                print_frac(mul(n1, n2));
                break;

            case '/':
                print_frac(div(n1, n2));
                break;

            default:
                printf("     WHEN THE INPUT IS SUS    \n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀\n");
                printf("⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀\n");
                printf("⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀\n");
                printf("⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀\n");
                printf("⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀\n");
                printf("⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀\n");
                printf("⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀\n");
                printf("⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀\n");
                printf("⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀\n");
                printf("⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀\n");
                printf("⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀\n");
                printf("⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
                printf("                              \n");
                printf("       ⠀⢠⣦⡀⣤⣠⡄⢠⠦⡄⣠⠤⠀⣤⠀⡆⣤⣶⡀⠀   \n");
                printf("      ⠀⠀⠟⠻⠃⠏⠉⠇⠸⠶⠋⠻⠾⠇⠙⠒⠃⠘⠾⠃    \n");
                return -1;
        }
    }
    return 0;
}
