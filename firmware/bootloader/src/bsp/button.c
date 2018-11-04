#include "button.h"

#include <at89s8253.h>

#define BUTTON_PIN_STATE      P1_1

void button_init(void)
{
        BUTTON_PIN_STATE = 1;
}

uint8_t button_is_pressed(void)
{
        return (BUTTON_PIN_STATE == 0) ? 1 : 0;
}
