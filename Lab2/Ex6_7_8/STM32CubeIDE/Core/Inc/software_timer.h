#ifndef INC_SOFTWARE_TIMER_H
#define INC_SOFTWARE_TIMER_H

extern int timer0_flag, timer0_counter, TIMER_CYCLE;

void setTimer0(int duration);

void timer_run();

#endif //INC_SOFTWARE_TIMER_H
