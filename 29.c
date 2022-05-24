#include <stdio.h>

typedef struct {
    int machine;
    int time;
} SubTask;

typedef struct {
    int count, curr_index, acc_time;
    SubTask subtasks[20];
} Task;

typedef struct {
    int acc_time;
} Machine;

void get_task(Task *task) {
    int i;

    scanf("%d", &task->count);
    task->curr_index = 0;
    task->acc_time = 0;

    for (i = 0; i < task->count; i++) {
        scanf("%d", &task->subtasks[i].machine);
        scanf("%d", &task->subtasks[i].time);
    }

    getchar();
}

void add_task(Task *tasks, Machine *machines, const int m) {
    int i, min_index = -1, min_time = 1000, req_time[10], task_acc_time, machine_acc_time;

    for (i = 0; i < m; i++) {
        if (tasks[i].curr_index >= tasks[i].count)
            continue;

        task_acc_time = tasks[i].acc_time;
        machine_acc_time = machines[tasks[i].subtasks[tasks[i].curr_index].machine].acc_time;
        req_time[i] = task_acc_time > machine_acc_time ? task_acc_time : machine_acc_time;

        req_time[i] += tasks[i].subtasks[tasks[i].curr_index].time;

        if (req_time[i] < min_time) {
            min_time = req_time[i];
            min_index = i;
        }
    }

    machines[tasks[min_index].subtasks[tasks[min_index].curr_index].machine].acc_time = min_time;
    tasks[min_index].acc_time = min_time;
    tasks[min_index].curr_index++;
}

int main() {
    int i, n, m, total_count = 0, total_time = 0;
    Task tasks[10];
    Machine machines[10];

    scanf("%d", &n);
    scanf("%d", &m);
    getchar();

    for (i = 0; i < n; i++) {
        machines[i].acc_time = 0;
    }

    for (i = 0; i < m; i++) {
        get_task(&tasks[i]);
        total_count += tasks[i].count;
    }

    for (i = 0; i < total_count; i++) {
        add_task(tasks, machines, m);
    }

    for (i = 0; i < m; i++) {
        total_time += tasks[i].acc_time;
    }

    printf("%d\n", total_time);
}
