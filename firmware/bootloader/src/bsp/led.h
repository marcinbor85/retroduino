#ifndef BSP_LED_H
#define BSP_LED_H

#include "types.h"

void led_init(void);
void led_set_state(uint8_t state);
void led_toggle(void);

#endif
