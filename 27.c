#include <stdio.h>

typedef struct {
    int next;
    int acc_time;
} Dep;

void calc_deps(const int id, const int time, Dep *deps, int *deps_size) {
    int i, j, next, dep_count;

    scanf("%d", &dep_count);

    for (i = 0; i < *deps_size; i++)
        if (id == deps[i].next)
            deps[i].acc_time += time;

    for (i = 0; i < dep_count; i++) {
        scanf("%d", &next);

        for (j = 0; j < *deps_size; j++) {
            if (id == deps[j].next) {
                deps[*deps_size].next = next;
                deps[*deps_size].acc_time = deps[j].acc_time;

                (*deps_size)++;
            }
        }
    }

    getchar();
}

int project_time() {
    int i, max_time = 0, task_time, task_count, deps_size;
    Dep deps[10000];

    scanf("%d", &task_count);

    deps_size = task_count;

    for (i = 0; i < task_count; i++) {
        deps[i].next = i + 1;
        deps[i].acc_time = 0;
    }

    for (i = 0; i < task_count; i++) {
        scanf("%d", &task_time);

        calc_deps(i + 1, task_time, deps, &deps_size);
    }

    for (i = 0; i < deps_size; i++)
        max_time = deps[i].acc_time > max_time ? deps[i].acc_time : max_time;

    return max_time;
}

int main() {
    int i, projects;

    scanf("%d", &projects);
    getchar();

    for (i = 0; i < projects; i++)
        printf("%d\n", project_time());

    return 0;
}
