#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i, j, k, len, _case, curr, max = 0, cases[50];
    char str[100];

    scanf("%d", &k);
    getchar();

    scanf("%s", str);
    getchar();

    len = strlen(str);


    for (i = 0; i < len; i++)
        str[i] = isupper(str[i]) ? 1 : -1;

    for (i = 0; i < len; i++) {
        _case = str[i];

        for (j = i; j < i + k - 1; j++) {
            if (str[j] != str[j + 1]) {
                _case = 0;
                break;
            }
        }

        cases[i] = _case;
    }

    for (i = 0; i < len; i++) {
        curr = 0;

        for (j = i; j < len; j += k) {
            if (cases[j] == 0)
                break;

            curr++;

            if (cases[j] != -cases[j + k])
                break;
        }

        max = curr > max ? curr : max;
    }

    printf("%d\n", max * k);

    return 0;
}
