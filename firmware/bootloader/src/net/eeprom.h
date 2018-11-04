#ifndef NET_EEPROM_H
#define NET_EEPROM_H

#include "types.h"

struct eeprom_descriptor {
        uint16_t total_size;
        uint16_t page_size;
        void (*send_buf)(uint8_t *data, uint16_t size);
        void (*recv_buf)(uint8_t *data, uint16_t size);
        void (*chip_select)(uint8_t state);
};

void eeprom_init(struct eeprom_descriptor *desc);
void eeprom_set_write_lock(struct eeprom_descriptor *desc, uint8_t state);
void eeprom_read(struct eeprom_descriptor *desc, uint16_t adr, uint8_t *data, uint16_t size);
void eeprom_write(struct eeprom_descriptor *desc, uint16_t adr, uint8_t *data, uint16_t size);

#endif