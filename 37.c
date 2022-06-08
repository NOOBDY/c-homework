#include <stdio.h>
#include <stdlib.h>

typedef struct var_s {
    int coeff;
    int power;
    struct var_s *next;
} Var;

typedef Var *Polynomial;

void push(Polynomial *p, const int coeff, const int power) {
    Var *new = malloc(sizeof(Var));
    new->coeff = coeff;
    new->power = power;
    new->next = NULL;

    if (!(*p)) {
        *p = new;
        return;
    }

    while ((*p)->next)
        p = &(*p)->next;

    (*p)->next = new;
}

void input(Polynomial *p) {
    int i, count = 0, buf[20] = {0};
    char ch = 0;

    while (ch != EOF && ch != '\n') {
        scanf("%d", &buf[count]);
        ch = getchar();
        count++;
    }

    for (i = 0; i < count; i++)
        if (buf[i])
            push(p, buf[i], count - i - 1);

    printf("\n");
}

void output(const Polynomial *p) {
    int is_first = 1, has_non_zero = 0;

    while (*p) {
        if ((*p)->coeff) {
            if ((*p)->coeff > 0 && !is_first)
                printf("+");

            if ((*p)->coeff == -1 && (*p)->power > 0)
                printf("-");
            else if ((*p)->coeff != 1 || (*p)->power == 0)
                printf("%d", (*p)->coeff);

            if ((*p)->power > 1)
                printf("x^%d", (*p)->power);
            else if ((*p)->power == 1)
                printf("x");

            is_first = 0;
            has_non_zero = 1;

        }

        p = &(*p)->next;
    }

    if (!has_non_zero)
        printf("0");

    printf("\n");
}

void output_raw(const Polynomial *p) {
    while (*p) {
        printf("%2dx^%d\n", (*p)->coeff, (*p)->power);
        p = &(*p)->next;
    }
}

void delete_all(Polynomial *p) {
    Var *tmp;

    while (*p) {
        tmp = *p;
        *p = (*p)->next;
        free(tmp);
    }
}

void copy(Polynomial *dest, Polynomial *src) {
    delete_all(dest);

    while (*src) {
        push(dest, (*src)->coeff, (*src)->power);
        src = &(*src)->next;
    }
}

void add(const Polynomial *p1, const Polynomial *p2, Polynomial *ans) {
    Polynomial tmp = NULL;

    while (*p1 || *p2) {
        if (!(*p1)) {
            push(&tmp, (*p2)->coeff, (*p2)->power);
            p2 = &(*p2)->next;
            continue;
        }

        if (!(*p2)) {
            push(&tmp, (*p1)->coeff, (*p1)->power);
            p1 = &(*p1)->next;
            continue;
        }

        if ((*p1)->power > (*p2)->power) {
            push(&tmp, (*p1)->coeff, (*p1)->power);
            p1 = &(*p1)->next;
            continue;
        }

        if ((*p1)->power < (*p2)->power) {
            push(&tmp, (*p2)->coeff, (*p2)->power);
            p2 = &(*p2)->next;
            continue;
        }

        push(&tmp, (*p1)->coeff + (*p2)->coeff, (*p1)->power);
        p1 = &(*p1)->next;
        p2 = &(*p2)->next;
    }

    copy(ans, &tmp);
    delete_all(&tmp);
}

void sub(const Polynomial *p1, const Polynomial *p2, Polynomial *ans) {
    Polynomial tmp = NULL;

    while (*p1 || *p2) {
        if (!(*p1)) {
            push(&tmp, -(*p2)->coeff, (*p2)->power);
            p2 = &(*p2)->next;
            continue;
        }

        if (!(*p2)) {
            push(&tmp, (*p1)->coeff, (*p1)->power);
            p1 = &(*p1)->next;
            continue;
        }

        if ((*p1)->power > (*p2)->power) {
            push(&tmp, (*p1)->coeff, (*p1)->power);
            p1 = &(*p1)->next;
            continue;
        }

        if ((*p1)->power < (*p2)->power) {
            push(&tmp, -(*p2)->coeff, (*p2)->power);
            p2 = &(*p2)->next;
            continue;
        }

        push(&tmp, (*p1)->coeff - (*p2)->coeff, (*p1)->power);
        p1 = &(*p1)->next;
        p2 = &(*p2)->next;
    }

    copy(ans, &tmp);
    delete_all(&tmp);
}

void mul(const Polynomial *p1, const Polynomial *p2, Polynomial *ans) {
    Polynomial product = NULL, _p1 = NULL;

    while (*p2) {
        _p1 = *p1;

        while (_p1) {
            push(&product, (_p1)->coeff * (*p2)->coeff, (_p1)->power + (*p2)->power);
            _p1 = (_p1)->next;
        }

        add(&product, ans, ans);
        delete_all(&product);

        p2 = &(*p2)->next;
    }
}

int main() {
    Polynomial p1 = NULL, p2 = NULL, ans = NULL;

    input(&p1);
    input(&p2);

    add(&p1, &p2, &ans);
    output(&ans);
    delete_all(&ans);

    sub(&p1, &p2, &ans);
    output(&ans);
    delete_all(&ans);

    mul(&p1, &p2, &ans);
    output(&ans);
    delete_all(&ans);

    delete_all(&p1);
    delete_all(&p2);

    return 0;
}
