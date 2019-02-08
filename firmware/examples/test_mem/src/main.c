#include <at89s8253.h>
#include <stdint.h>

#define LED_PIN_STATE       P1_0
#define BUTTON_PIN_STATE    P1_1
#define BANK_PIN_SELECT     P1_4

#define EXTERNAL_MEMORY_ADR     ((uint16_t)0x8000)

static void delay(uint16_t val)
{
        while (val-- > 0) {};
}

static void blinking(void)
{
        uint8_t i = 0;
 
        LED_PIN_STATE = i;
        while (1) {
                delay(50000);
                i = (i == 0) ? 1 : 0;
                LED_PIN_STATE = i;
        }
}

static void fill_memory(uint8_t pattern)
{
        uint16_t *ptr;
        uint8_t b;

        ptr = (uint16_t*)EXTERNAL_MEMORY_ADR;
        b = pattern;
        while ((uint16_t)ptr >= EXTERNAL_MEMORY_ADR) {
            *ptr = b;
            ptr++;
            b++;
        }
}

static uint8_t check_memory(uint8_t pattern)
{
        uint16_t *ptr;
        uint8_t b;

        ptr = (uint16_t*)EXTERNAL_MEMORY_ADR;
        b = pattern;
        while ((uint16_t)ptr >= EXTERNAL_MEMORY_ADR) {
            if (*ptr != b)
                return 1;
            ptr++;
            b++;
        }

        return 0;
}

void main(void)
{
        LED_PIN_STATE = 1;

        while (1) {
            BANK_PIN_SELECT = 1;
            fill_memory(0x55);
            if (check_memory(0x55) != 0)
                    break;

            BANK_PIN_SELECT = 0;
            fill_memory(0xAA);
            if (check_memory(0xAA) != 0)
                    break;

            BANK_PIN_SELECT = BUTTON_PIN_STATE;
            if (check_memory(0x55) != 0)
                    break;

            blinking();
            while (1) {};
        }

        LED_PIN_STATE = 0;
        while (1) {};
}

