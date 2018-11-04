#include "tick.h"

#include <at89s8253.h>

static tick_t tick;

void tick_init(void)
{
        tick = 0;

#ifdef TICK_ISR_BASED
        ET0 = 1;
#endif

        TR0 = 1;
}

#ifdef TICK_SERVICE_BASED

tick_t tick_get_value(void)
{
        tick_t ret;

        if (TF0 != 0) {
                TF0 = 0;
                tick++;
        }

        return tick;
}

#endif

#ifdef TICK_ISR_BASED

tick_t tick_get_value(void)
{
        tick_t ret;

        ET0 = 0;
        ret = tick;
        ET0 = 1;

        return ret;
}

#endif

void tick_delay(tick_t delay)
{
        tick_t last_tick;
        last_tick = tick_get_value();
        while (tick_check_delay(delay, &last_tick) == 0) {};
}

uint8_t tick_check_delay(tick_t delay, tick_t *last_tick)
{
        uint8_t ret;
        ret = (tick_get_value() - *last_tick >= delay) ? 1 : 0;
        return ret;
}

#ifdef TICK_ISR_BASED

void tick_increment(void)
{
        tick++;
}

#endif