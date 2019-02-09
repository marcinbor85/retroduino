#include <at89s8253.h>
#include <stdint.h>

#define LED_PIN_STATE           P1_0
#define BUTTON_PIN_STATE        P1_1
#define BANK_PIN_SELECT         P1_4

#define EXTMEM_ADR_START        ((uint16_t)0x8000)
#define EXTMEM_ADR_END          ((uint16_t)0xFFFF)

static void delay(uint16_t val)
{
        while (val-- > 0) {};
}

static void blinking_loop(void)
{
        uint8_t i = 0;
 
        LED_PIN_STATE = i;
        while (1) {
                delay(50000);
                i = (i == 0) ? 1 : 0;
                LED_PIN_STATE = i;
        }
}

static void signal_error(void)
{
        LED_PIN_STATE = 0;
        while (1) {};
}

static uint8_t calc_pattern(uint16_t adr, uint8_t b)
{
        b ^= adr >> 8;
        b ^= adr;
        return b;
}

static void fill_memory(uint16_t adr_start, uint16_t adr_end, uint8_t pattern)
{
        uint16_t adr;
        uint8_t b;

        adr = adr_start;
        while ((adr >= adr_start) && (adr <= adr_end)) {
                b = calc_pattern(adr, pattern++);
                *(__xdata uint8_t*)adr++ = b;                
        }
}

static uint8_t check_memory(uint16_t adr_start, uint16_t adr_end, uint8_t pattern)
{
        uint16_t adr;
        uint8_t b;

        adr = adr_start;
        while ((adr >= adr_start) && (adr <= adr_end)) {
                b = calc_pattern(adr, pattern++);
                if (*(__xdata uint8_t*)adr++ != b)
                        return 1;
        }

        return 0;
}

static void uart_send_byte(uint8_t ch)
{
        SBUF = ch;
        while (TI == 0) {};
        TI = 0;
}

static uint8_t uart_recv_byte(void)
{
        uint8_t ch;

        while (RI == 0) {};
        ch = SBUF;
        RI = 0;
        return ch;
}

static void uart_init(uint32_t baudrate)
{ 
        SCON = 0x50;
        TMOD = 0x20;
        TH1 = 256 - (24000000UL) / (uint32_t)(32UL * 6UL * baudrate);
        TR1 = 1;
}

static void uart_send_data(uint8_t *data, uint16_t size)
{
        while (size-- > 0) {
                uart_send_byte(*data++);
        }
}

static void uart_send_string(char *data)
{
        while (*data != 0) {
                uart_send_byte(*data++);
        }
}

static void echo_loop(void)
{
        uint8_t b;

        while (1) {
                b = uart_recv_byte();
                uart_send_byte(b);
        }
}

void main(void)
{
        LED_PIN_STATE = 1;

        uart_init(9600);

        while (1) {
                BANK_PIN_SELECT = 1;
                fill_memory(EXTMEM_ADR_START, EXTMEM_ADR_END, 0x55);
                if (check_memory(EXTMEM_ADR_START, EXTMEM_ADR_END, 0x55) != 0)
                        break;

                BANK_PIN_SELECT = 0;
                fill_memory(EXTMEM_ADR_START, EXTMEM_ADR_END, 0xAA);
                if (check_memory(EXTMEM_ADR_START, EXTMEM_ADR_END, 0xAA) != 0)
                        break;

                BANK_PIN_SELECT = BUTTON_PIN_STATE;
                if (check_memory(EXTMEM_ADR_START, EXTMEM_ADR_END, 0x55) != 0)
                        break;

                uart_send_string("OK");
                blinking_loop();
        }

        LED_PIN_STATE = 0;
        uart_send_string("ERROR");
        echo_loop();
}
