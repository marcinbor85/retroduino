#ifndef SYS_TICK_H
#define SYS_TICK_H

#include "types.h"

//#define TICK_ISR_BASED 1

#ifndef TICK_ISR_BASED
#define TICK_SERVICE_BASED 1
#endif

typedef uint32_t     tick_t;

void tick_init(void);
tick_t tick_get_value(void);
void tick_delay(tick_t delay);
uint8_t tick_check_delay(tick_t delay, tick_t *last_tick);

#ifdef TICK_ISR_BASED

void tick_increment(void);

#endif

#endif