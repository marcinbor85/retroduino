#include "logic.h"

#include "bsp/led.h"

#include "sys/tick.h"

#include "types.h"

void logic_init(void)
{
        led_set_state(1);
}

void blink_led_service(void)
{
        static uint32_t last_tick = 0;

        if (tick_check_delay(500UL, &last_tick) == 0)
                return;

        led_toggle();
}

void logic_service(void)
{
        blink_led_service();
}