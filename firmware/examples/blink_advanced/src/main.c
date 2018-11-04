#include "app/logic.h"

#include "bsp/bsp.h"

#include "sys/tick.h"

#include "types.h"

void external0_isr(void) __interrupt(0)
{

}

void timer0_isr(void) __interrupt(1)
{
        tick_increment();
}

void external1_isr(void) __interrupt(2)
{

}

void timer1_isr(void) __interrupt(3)
{

}

void serialport_isr(void) __interrupt(4)
{

}

void main(void)
{
        tick_init();
        bsp_init();
        logic_init();

        while (1) {
                bsp_service();
                logic_service();
        }
}

