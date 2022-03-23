#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

typedef struct {
    Fraction x;
    Fraction y;
} Point;

int GCD(int n1, int n2) {
    int temp;

    while (n2 != 0) {
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }

    return n1;
}

int abs(const int n) {
    return n >= 0 ? n : -n;
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

void print_frac(Fraction n) {
    int gcd = GCD(n.numerator, n.denominator);

    n.numerator /= gcd;
    n.denominator /= gcd;

    n.numerator = (n.numerator * n.denominator) / abs(n.denominator);
    n.denominator = abs(n.denominator);

    if (n.denominator == 1) {
        printf("%d", n.numerator);
        return;
    }

    if (abs(n.numerator) > n.denominator) {
        printf("%d(%d/%d)",
                n.numerator / n.denominator,
                abs(n.numerator) % n.denominator,
                n.denominator
        );

        return;
    }

    printf("%d/%d", n.numerator, n.denominator);
}

void get_point(Point *p) {
    p->x.denominator = 1;
    p->y.denominator = 1;
    scanf("%d", &(p->x.numerator));
    getchar();
    scanf("%d", &(p->y.numerator));
    getchar();
}

void print_point(Point p) {
    print_frac(p.x);
    print_frac(p.y);
}

void print_line(Point p1, Point p2) {
    Fraction m, b;

    m = div(sub(p1.y, p2.y), sub(p1.x, p2.x));
    b = div(sub(mul(p2.x, p1.y), mul(p1.x, p2.y)), sub(p2.x, p1.x));

    printf("y=");

    if (!(m.numerator || b.numerator)) {
        printf("0\n");
        return;
    }

    if (m.numerator) {
        if (m.numerator == -m.denominator)
            printf("-");
        else if (m.numerator != m.denominator)
            print_frac(m);
        printf("x");
    }

    if (b.numerator) {
        if ((b.numerator * b.denominator) > 0)
            printf("+");
        print_frac(b);
    }
}

int main() {
    Point p1, p2;

    get_point(&p1);
    get_point(&p2);

    print_line(p1, p2);
    printf("\n");

    return 0;
}
