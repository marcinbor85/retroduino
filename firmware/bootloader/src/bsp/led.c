#include "led.h"

#include <at89s8253.h>

#define LED_PIN_STATE      P1_0

void led_init(void)
{
        LED_PIN_STATE = 1;
}

void led_set_state(uint8_t state)
{
        LED_PIN_STATE = (state == 0) ? 1 : 0;
}

void led_toggle(void)
{
        LED_PIN_STATE = !LED_PIN_STATE;
}