#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int value;
    struct node_s *next;
} Node;

Node *new_node(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void append(Node **head_ref, int value) {
    Node *new = new_node(value);

    if (!(*head_ref)) {
        *head_ref = new;
        return;
    }

    while ((*head_ref)->next)
        head_ref = &(*head_ref)->next;

    (*head_ref)->next = new;
}

void insert(Node **head_ref, int target, int value) {
    Node *new;

    while (*head_ref) {
        if ((*head_ref)->value == target) {
            new = new_node(value);
            new->next = (*head_ref)->next;
            (*head_ref)->next = new;
        }

        head_ref = &(*head_ref)->next;
    }
}

void delete(Node **head_ref, int target) {
    Node *tmp = *head_ref;

    if (tmp->value == target) {
        *head_ref = (*head_ref)->next;
        free(tmp);
        return;
    }

    while ((*head_ref)->next) {
        tmp = (*head_ref)->next;

        if (tmp->value == target) {
            (*head_ref)->next = tmp->next;
            free(tmp);
            return;
        }

        head_ref = &(*head_ref)->next;
    }
}

void deque(Node **head_ref) {
    Node *tmp = *head_ref;
    if (tmp)
        *head_ref = tmp->next;
    free(tmp);
}

void pop(Node **head_ref) {
    Node *tmp = *head_ref;

    if (!(*head_ref))
        return;

    if (!(*head_ref)->next) {
        *head_ref = NULL;
        free(tmp);
        return;
    }

    while ((*head_ref)->next) {
        tmp = *head_ref;
        head_ref = &(*head_ref)->next;
    }

    tmp->next = NULL;
    free(*head_ref);
}

void delete_all(Node **head_ref) {
    Node *tmp;

    while (*head_ref) {
        tmp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(tmp);
    }
}

void output(Node **head_ref) {
    if (!(*head_ref)) {
        printf("None any node\n");
        return;
    }

    while ((*head_ref)) {
        printf("%d ", (*head_ref)->value);
        head_ref = &(*head_ref)->next;
    }

    printf("\n");
}

int main() {
    int i, count, num, op, v0, v1;
    Node *head = NULL;

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++) {
        scanf("%d", &num);
        append(&head, num);
    }
    getchar();

    do {
        scanf("%d", &op);

        switch (op) {
            case 1:
                scanf("%d", &v0);
                append(&head, v0);
                break;
            case 2:
                scanf("%d", &v0);
                scanf("%d", &v1);
                insert(&head, v0, v1);
                break;
            case 3:
                scanf("%d", &v0);
                delete(&head, v0);
                break;
            case 4:
                deque(&head);
                break;
            case 5:
                pop(&head);
                break;
            case 6:
                break;
        }
        getchar();

    } while(op != 6);

    output(&head);

    delete_all(&head);

    return 0;
}
