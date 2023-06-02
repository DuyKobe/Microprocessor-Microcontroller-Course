#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdlib.h>

struct task {
    void (*pTask)(void);

    uint32_t delay;
    uint32_t period;
    uint32_t taskID;

    struct task *next;
};

extern struct task *head;
extern struct task *newTask;
extern struct task *ptr;
extern struct task *del;

extern int size_task;

extern uint32_t current_taskID;
extern uint32_t sum;

void SCH_Add_Task(void (*PTASK)(), uint32_t DELAY, uint32_t PERIOD);

void SCH_Delete_Task(uint32_t TASKID);

void SCH_Update();

void SCH_Dispatch_Task();

#endif /* INC_SCHEDULER_H_ */
