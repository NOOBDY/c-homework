#include <stdio.h>

int main() {
    int hours[5][9] = {0};
    int i, j;

    for(i = 0; i < 3; i++) {
        int class_id, class_count;
        scanf("%d", &class_id);
        scanf("%d", &class_count);

        for(j = 0; j < class_count; j++) {
            int tmp;
            scanf("%d", &tmp);

            if(!hours[tmp / 10 - 1][tmp % 10 - 1])
                hours[tmp / 10 - 1][tmp % 10 - 1] = class_id;

            else
                printf("%d and %d conflict on %d\n",
                        hours[tmp / 10 - 1][tmp % 10 - 1], class_id, tmp);

        }
    }
    return 0;
}
