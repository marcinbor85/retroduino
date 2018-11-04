#ifndef NET_RETROLOADER_H
#define NET_RETROLOADER_H

#include "types.h"

struct retroloader_descriptor {
        uint8_t (*send_byte)(uint8_t data);
        uint8_t (*recv_byte)(uint8_t *data);
        uint8_t (*write_code)(uint16_t adr, uint8_t data);
};

struct retroloader {
        struct retroloader_descriptor const * desc;
};

void retroloader_init(struct retroloader *self, struct retroloader_descriptor *desc);
void retroloader_service(struct retroloader *self);

#endif