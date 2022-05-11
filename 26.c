#include <stdio.h>
#include <math.h>

double f1(double a, double x) {
    return pow(a - pow(x, 2), 0.5);
}

double f2(double a, double x) {
    return (a * pow(x, 3) + 7 * x) / pow(a + x, 0.5);
}

void calculate_area(double f(double, double)) {
    int i, p, q, err, n = 1;
    double prev_area = 0, curr_area = 0, a, x, delta;

    scanf("%lf", &a);
    getchar();

    scanf("%d", &p);
    getchar();

    scanf("%d", &q);
    getchar();

    scanf("%d", &err);
    getchar();

    delta = pow(10, -err);

    while (1) {
        curr_area = 0.0;

        curr_area += fabs(f(a, p));
        curr_area += fabs(f(a, q));

        x = (double)(q - p) / n;

        for (i = 1; i < n; i++) {
            curr_area += fabs(2.0 * f(a, p + i * x));
        }

        curr_area *= (q - p) / (2.0 * n);

        if (fabs(prev_area - curr_area) < delta && fabs(prev_area - curr_area) != 0)
            break;
        prev_area = curr_area;
        n *= 2;

    }

    printf("%.12lf\n", curr_area);
}

int main() {
    int op;
    double (*func[])(double, double) = {f1, f2};

    while (1) {
        scanf("%d", &op);
        getchar();

        if (op == 0)
            break;

        calculate_area(func[op - 1]);
    }

    return 0;
}
