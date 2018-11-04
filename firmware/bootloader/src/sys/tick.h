#ifndef SYS_TICK_H
#define SYS_TICK_H

#include "types.h"

void tick_init(void);
uint32_t tick_get_value(void);
void tick_service(void);

#endif