#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 500

int main() {
    int i, cursor = 0, len;
    char str[MAX_SIZE];
    char op = 0, tmp;

    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;

    while (op != '\n') {
        len = strlen(str);

        op = getchar();

        switch (op) {
            case '0':
                cursor = 0;
                break;
            case '$':
                cursor = len;
                break;
            case 'x':
                for (i = cursor; i < len; i++)
                    str[i] = str[i + 1];
                break;
            case 's':
                if (cursor < len - 1) {
                    tmp = str[cursor];
                    str[cursor] = str[cursor + 1];
                    str[cursor + 1] = tmp;
                }
                break;
            case 'i':
                for (i = len; i > cursor; i--)
                    str[i] = str[i - 1];
                str[cursor] = getchar();
                str[len + 1] = 0;
                cursor++;
                break;
            case 'u':
                if (isalpha(str[cursor]))
                    str[cursor] = toupper(str[cursor]);
                cursor++;
                break;
            case '+':
                cursor++;
                break;
            case '-':
                cursor--;
                break;
        }
    }

    printf("%s\n", str);

    return 0;
}
