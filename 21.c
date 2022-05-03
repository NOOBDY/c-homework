#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LEN 50
#define MAX_WORD_LEN 15

typedef struct {
    char words[MAX_SENTENCE_LEN][MAX_WORD_LEN];
    unsigned int len;
} Strings;

void read_string(Strings *str) {
    char buf[750], *token;

    memset(str, 0, sizeof(Strings));

    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0;

    token = strtok(buf, " ");

    while (token != NULL) {
        strcpy(str->words[str->len], token);
        str->len++;

        token = strtok(NULL, " ");
    }
}

void print_string(const Strings str) {
    int i;

    for (i = 0; i < str.len; i++)
        printf("%s ", str.words[i]);

    printf("\n");
}

int compliment(const Strings sentence, const Strings a, const Strings b) {
    int i, j, max_len, count[MAX_SENTENCE_LEN] = {0};

    max_len = a.len > b.len ? a.len : b.len;

    /* check for overlapping */
    for (i = 0; i < max_len; i++) {
        for (j = 0; j < max_len; j++) {
            if (strcmp(a.words[i], b.words[j]) == 0)
                return 0;
        }
    }

    for (i = 0; i < sentence.len; i++) {
        for (j = 0; j < max_len; j++) {
            if (strcmp(sentence.words[i], a.words[j]) == 0)
                count[i]++;

            else if (strcmp(sentence.words[i], b.words[j]) == 0)
                count[i]++;
        }
    }

    /* check for uncovered words */
    for (i = 0; i < sentence.len; i++) {
        if (count[i] == 0)
            return 0;
    }

    return 1;
}

int main() {
    int i, j, count, total = 0;
    Strings sentence, str_list[20];

    read_string(&sentence);

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++)
        read_string(&str_list[i]);

    for (i = 0; i < count; i++)
        for (j = i + 1; j < count; j++)
            total += compliment(sentence, str_list[i], str_list[j]);

    printf("%d\n", total);
}
