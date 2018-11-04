#include <at89s8253.h>

#define LED_PIN_STATE      P1_0

static void delay(int val)
{
        while (val-- > 0) {};
}

void main(void)
{
        LED_PIN_STATE = 0;

        while (1) {
                delay(50000);
                LED_PIN_STATE = !LED_PIN_STATE;
        }
}

