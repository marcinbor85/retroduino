#include "app/logic.h"

#include "bsp/bsp.h"

#include "types.h"

void external0_isr(void)        __interrupt(0) __naked { __asm__("ljmp 0x8003"); }
void timer0_isr(void)           __interrupt(1) __naked { __asm__("ljmp 0x800B"); }
void external1_isr(void)        __interrupt(2) __naked { __asm__("ljmp 0x8013"); }
void timer1_isr(void)           __interrupt(3) __naked { __asm__("ljmp 0x801B"); }
void serialport_isr(void)       __interrupt(4) __naked { __asm__("ljmp 0x8023"); }

void main(void)
{
        tick_init();
        bsp_init();
        logic_init();

        while (1) {
                tick_service();
                bsp_service();
                logic_service();
        }
}

