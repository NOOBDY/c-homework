#include <stdio.h>
#include <stdlib.h>

typedef struct person_s {
    char name[20];
    int age;
    int year;
    int month;
    int date;
    struct person_s *next;
} Person;

void print_person(const Person *p) {
    printf("%s %d %d_%d_%d\n", p->name, p->age, p->year, p->month, p->date);
}

void push(Person **head_ref) {
    Person *new = malloc(sizeof(Person));
    scanf("%s", new->name);
    scanf("%d", &new->age);
    scanf("%d", &new->year);
    scanf("%d", &new->month);
    scanf("%d", &new->date);
    new->next = NULL;
    getchar();

    new->next = *head_ref;
    *head_ref = new;
}

void pop(Person **head_ref) {
    int op;
    Person *tmp = *head_ref;

    scanf("%d", &op);
    getchar();

    if (!(*head_ref)) {
        printf("The Stack is empty\n");
        return;
    }

    *head_ref = (*head_ref)->next;

    switch (op) {
        case 1:
            printf("%s\n", tmp->name);
            break;
        case 2:
            printf("%d\n", tmp->age);
            break;
        case 3:
            printf("%d_%d_%d\n", tmp->year, tmp->month, tmp->date);
            break;
    }

    free(tmp);
}

void pop_all(Person **head_ref) {
    Person *tmp;

    if (!(*head_ref)) {
        printf("The Stack is empty\n");
        return;
    }

    while (*head_ref) {
        tmp = *head_ref;
        print_person(tmp);
        *head_ref = (*head_ref)->next;
        free(tmp);
    }
}

void print_all(Person **head_ref) {
    if (!(*head_ref)) {
        printf("The Stack is empty\n");
        return;
    }

    while (*head_ref) {
        print_person(*head_ref);
        head_ref = &(*head_ref)->next;
    }
}

void list_len(Person **head_ref) {
    int count = 0;

    while (*head_ref) {
        head_ref = &(*head_ref)->next;
        count++;
    }

    printf("%d\n", count);
}

int main() {
    int op = 0;

    Person *stack = NULL;

    while (op != 5) {
        scanf("%d", &op);

        switch (op) {
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                pop_all(&stack);
                break;
            case 4:
                print_all(&stack);
                break;
            case 5:
                list_len(&stack);
                break;
        }
    }

    return 0;
}
