#pragma once

#include "pico_aht20/types.h"

void _write_to_reg(AHT20_I2C i2c_c, uint8_t reg_address, uint8_t buffer[],
                   uint16_t bufflen);
void _read_from_reg(AHT20_I2C i2c_c, uint8_t reg, int bytes_to_read,
                    uint8_t* buff);
