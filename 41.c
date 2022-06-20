#include <stdio.h>
#include <string.h>

#define MAX_ARR_SIZE 20

typedef struct {
    int path[MAX_ARR_SIZE];
    int len;
    int acc_time;
} Route;

void append(Route *route, int value) {
    route->path[route->len] = value;
    route->len++;
}

void print_route(const Route route) {
    int i;

    for (i = 0; i < route.len; i++)
        printf("%d", route.path[i]);
}

void print_stack(const Route *stack, const int size) {
    int i;

    for (i = 0; i < size; i++) {
        print_route(stack[i]);
        printf(" ");
    }

    printf("\n");
}

int is_valid(Route route, int target) {
    int i;

    for(i = 0; i < route.len; i++) {
        if(route.path[i] == target)
            return 0;
    }

    return 1;
}

void perm(int start, int count, int map[][MAX_ARR_SIZE]) {
    int i, top = 1, min_time = 10000000;
    Route stack[MAX_ARR_SIZE];
    Route curr;

    memset(stack, 0, sizeof(stack));
    append(&stack[0], 0);

    while (top) {
        top--;
        curr = stack[top];

        if (curr.len == count) {
            curr.acc_time += map[curr.path[curr.len - 1]][0];

            if (curr.acc_time < min_time)
                min_time = curr.acc_time;

            continue;
        }

        for (i = 0; i < count; i++) {
            if (is_valid(curr, i)) {
                stack[top] = curr;
                stack[top].acc_time += map[curr.path[curr.len - 1]][i];

                append(&stack[top], i);
                top++;
            }
        }
    }

    printf("%d\n", min_time);
}

int main() {
    int i, j, count;
    int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE];

    scanf("%d", &count);

    for (i = 0; i < count; i++)
        for (j = 0; j < count; j++)
            scanf("%d", &matrix[i][j]);

    perm(0, count, matrix);
}
