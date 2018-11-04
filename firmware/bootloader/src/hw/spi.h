#ifndef HW_SPI_H
#define HW_SPI_H

#include "types.h"

void spi_init(void);
uint8_t spi_send_byte(uint8_t data);
void spi_send_buf(uint8_t *buf, uint16_t size);
void spi_recv_buf(uint8_t *buf, uint16_t size);
void spi_exchange_buf(uint8_t *send_buf, uint8_t *recv_buf, uint16_t size);

#endif
