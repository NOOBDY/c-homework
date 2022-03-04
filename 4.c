#include <stdio.h>

#define PI 3.14159

int main() {
    float r;

    scanf("%f", &r);
    printf("%.3f\n", r * r * PI);
    printf("%.3f\n", 2 * r * PI);

    return 0;
}
