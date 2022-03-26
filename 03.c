#include <stdio.h>

int main() {
    float first_month, second_month, hourly_wage, minimum_wage, insurance, tax;

    scanf("%f", &first_month);
    scanf("%f", &second_month);
    scanf("%f", &hourly_wage);
    scanf("%f", &minimum_wage);

    insurance = minimum_wage * 0.05;
    tax = (first_month + second_month) * hourly_wage * 0.08;

    printf("%.1f\n", (first_month + second_month) * hourly_wage - insurance - tax);
    printf("%.1f\n", insurance);
    printf("%.1f\n", tax);
    return 0;
}
