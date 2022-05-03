#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 50
#define MAX_WORD_LENGTH 15

typedef struct {
    char word[MAX_WORD_LENGTH];
    unsigned int rate;
} Word;

typedef struct {
    Word words[MAX_SENTENCE_LENGTH];
    int len;
} Set;

void read_sentence(Set *set) {
    char *token;
    char buf[MAX_SENTENCE_LENGTH * MAX_WORD_LENGTH];

    memset(set->words, 0, MAX_SENTENCE_LENGTH * sizeof(*set->words));
    set->len = 0;

    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0;

    token = strtok(buf, " ");

    while (token != NULL) {
        strcpy(set->words[set->len].word, token);
        (set->len)++;

        token = strtok(NULL, " ");
    }
}

void substitute(const Set sentence, const char *p, const char *q) {
    int i;

    for (i = 0; i < sentence.len; i++) {
        if (strcmp(sentence.words[i].word, p) == 0)
            printf("%s ", q);
        else
            printf("%s ", sentence.words[i].word);
    }
    printf("\n");
}

void insert(const Set sentence, const char *p, const char *q) {
    int i;

    for (i = 0; i < sentence.len; i++) {
        if (strcmp(sentence.words[i].word, p) == 0)
            printf("%s ", q);

        printf("%s ", sentence.words[i].word);
    }
    printf("\n");
}

void delete(const Set sentence, const char *p, const char *q) {
    int i;

    for (i = 0; i < sentence.len; i++) {
        if (strcmp(sentence.words[i].word, p) == 0)
            continue;

        printf("%s ", sentence.words[i].word);
    }
    printf("\n");
}

int cmp(const void *a, const void *b) {
    Word *aa = (void *)a;
    Word *bb = (void *)b;

    if (aa->rate > bb->rate)
        return -1;

    if (aa->rate < bb->rate)
        return 1;

    if (strlen(aa->word) > strlen(bb->word))
        return 1;

    if (strlen(aa->word) < strlen(bb->word))
        return -1;

    return strcmp(aa->word, bb->word);
}

int main() {
    int i, j, exists;
    Set sentence, set;
    char p[MAX_WORD_LENGTH];
    char q[MAX_WORD_LENGTH];

    read_sentence(&sentence);

    set.len = 0;

    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = 0;

    fgets(q, sizeof(q), stdin);
    q[strcspn(q, "\n")] = 0;

    substitute(sentence, p, q);
    insert(sentence, p, q);
    delete(sentence, p, q);

    for (i = 0; i < sentence.len; i++) {
        exists = 0;

        for (j = 0; j < sentence.len; j++) {
            if (strcmp(sentence.words[i].word, set.words[j].word) == 0) {
                set.words[j].rate++;
                exists = 1;
            }
        }

        if (!exists) {
            memcpy(&set.words[set.len], &sentence.words[i], sizeof(Word));
            set.words[set.len].rate = 1;
            set.len++;
        }
    }

    qsort(set.words, set.len, sizeof(*set.words), cmp);

    for (i = 0; i < set.len; i++) {
        printf("%s %d\n", set.words[i].word, set.words[i].rate);
    }
    printf("\n");

    return 0;
}
