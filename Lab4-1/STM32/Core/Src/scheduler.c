#include "scheduler.h"

struct task *head = NULL;
struct task *newTask;
struct task *ptr;
struct task *del;

int size_task = 0;

uint32_t current_taskID = 0;
uint32_t sum;

void SCH_Add_Task(void (*PTASK)(), uint32_t DELAY, uint32_t PERIOD) {
    newTask = malloc(sizeof(struct task));

    newTask->pTask = PTASK;
    newTask->delay = DELAY;
    newTask->period = PERIOD;
    newTask->taskID = current_taskID++;

    if (size_task == 0) {
        newTask->next = NULL;
        head = newTask;
    } else if (newTask->delay < head->delay) {
        head->delay -= newTask->delay;
        newTask->next = head;
        head = newTask;
    } else {
        sum = 0;
        ptr = head;
        while (1) {
            sum += ptr->delay;
            if (newTask->delay == sum) {
                newTask->delay = 0;
                break;
            }
            if (ptr->next == NULL) {
                newTask->delay -= sum;
                break;
            }
            if (sum + ptr->next->delay > newTask->delay) {
                newTask->delay -= sum;
                ptr->next->delay -= newTask->delay;
                break;
            }
            ptr = ptr->next;
        }
        newTask->next = ptr->next;
        ptr->next = newTask;
    }
    size_task++;
}

void SCH_Delete_Task(uint32_t TASKID) {
    del = NULL;
    if (head->taskID == TASKID) {
        if (head->next != NULL)
            head->next->delay += head->delay;
        del = head;
        head = head->next;
    } else {
        ptr = head;
        while (1) {
            if (ptr == NULL)
                return;
            if (ptr->next->taskID == TASKID) {
                if (ptr->next->next != NULL)
                    ptr->next->next->delay += ptr->next->delay;
                del = ptr->next;
                ptr->next = ptr->next->next;
                break;
            }
        }
    }
    free(del);
    size_task--;
}

void SCH_Update() {
    if (head->delay != 0)
        head->delay--;
}

void SCH_Dispatch_Task() {
    if (head->delay == 0) {
        ptr = head;
        while (ptr->delay == 0) {
            (*ptr->pTask)();
            if (ptr->next == NULL)
                break;
            else
                ptr = ptr->next;
        }
        while (head->delay == 0) {
            if (head->period != 0)
                SCH_Add_Task(head->pTask, head->period, head->period);
            SCH_Delete_Task(head->taskID);
            if (size_task == 0)
                break;
        }
    }
}

void SCH_Display() {
    printf("\n--SCHEDULER--\n");
    if (size_task == 0)
        printf("EMPTY!");
    else {
        printf("%d(%d)", head->taskID, head->delay);
        ptr = head->next;
        while (ptr != NULL) {
            printf("->%d(%d)", ptr->taskID, ptr->delay);
            ptr = ptr->next;
        }
    }
    printf("\n--SCHEDULER--\n");
}
