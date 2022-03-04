#include <stdio.h>
#include <math.h>

typedef struct s_plan{
    float base;
    float internal_call;
    float external_call;
    float landline;
    float internal_message;
    float external_message;
} Plan;

float calculate_plan(Plan plan, Plan rate) {
    int i;
    float sum = 0.0;

    for (i = 1; i < 6; i++) {
        sum += ((float *)&plan)[i] * ((float *)&rate)[i];
    }

    return sum;
}

int main() {
    int i, min = 983;
    Plan plans[3] = {
        {183, 0.08, 0.1393, 0.1349, 1.1287, 1.4803},
        {383, 0.07, 0.1304, 0.1217, 1.1127, 1.2458},
        {983, 0.06, 0.1087, 0.1018, 0.9572, 1.1243}
    };

    Plan rate;
    scanf("%f", &rate.internal_call);
    scanf("%f", &rate.external_call);
    scanf("%f", &rate.landline);
    scanf("%f", &rate.internal_message);
    scanf("%f", &rate.external_message);

    for (i = 0; i < 3; i++){
        float sum = calculate_plan(plans[i], rate);
        int total = sum - plans[i].base > plans[i].base ? sum : plans[i].base;
        min = total < min ? total : min;
    }
    printf("%d\n", min);
    return 0;
}
