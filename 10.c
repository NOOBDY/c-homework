#include <stdio.h>
#include <string.h>

int C(int m) {
    if(m <= 1)
        return 0;

    return C((m + (m & 1)) / 2) + 1;
}

int main() {
    int i, end, num, depth;
    char ch;

    /* fuck this input shit */
    while(1) {
        num = 0;
        depth = 0;
        for(i = 7; i >= 0; i--) {
            ch = getchar();
            num += (ch - '0') << i;
        }
        getchar();

        depth = C(num);
        for(i = 3; i >= 0; i--)
            printf("%d", (depth & (1 << i)) ? 1 : 0);

        printf("\n");

        scanf("%d", &end);
        getchar();
        if(end == -1)
            return 0;
    }
    return 0;
}
