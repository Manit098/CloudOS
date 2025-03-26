#include <stdint.h>

#define MAX_TASKS 4

typedef struct {
    uint32_t pid;
    uint32_t stack[1024];
    uint32_t state;
} Task;

Task tasks[MAX_TASKS];
int current_task = 0;

void init_scheduler() {
    for (int i = 0; i < MAX_TASKS; i++)
        tasks[i].state = 0;  // Mark tasks as available
}

void schedule() {
    current_task = (current_task + 1) % MAX_TASKS;
}
