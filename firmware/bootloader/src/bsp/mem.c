#include "mem.h"

#include "net/eeprom.h"

#include "hw/spi.h"

#define MEM_WRITE_PROTECT_PIN_STATE     P1_2
#define MEM_CHIP_SELECT_PIN_STATE       P1_3

static void set_cs(uint8_t state)
{
        MEM_CHIP_SELECT_PIN_STATE = (state == 0) ? 1 : 0;
}

static struct eeprom_descriptor eeprom = {
        .total_size = 0x8000,
        .page_size = 64,
        .send_buf = spi_send_buf,
        .recv_buf = spi_recv_buf,
        .chip_select = set_cs,
};

void mem_init(void)
{
        set_cs(0);

        eeprom_init(&eeprom);
}