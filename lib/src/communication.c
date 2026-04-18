#include "pico_aht20/communication.h"
#include "pico_aht20/types.h"
#include <stdlib.h>
#include <string.h>

void _aht20_write_to_reg(AHT20_I2C i2c_c, uint8_t reg_address, uint8_t buffer[],
                         uint16_t bufflen) {
    const uint16_t write_buff_length = bufflen + 1;
    uint8_t* write_buff = malloc(write_buff_length);

    write_buff[0] = reg_address;
    memcpy(write_buff + 1, buffer, bufflen);

    i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, write_buff,
                       write_buff_length, false);

    free(write_buff);
}

void _aht20_read_from_reg(AHT20_I2C i2c_c, uint8_t reg, int bytes_to_read,
                          uint8_t* buff) {
    i2c_write_blocking(i2c_c.i2c, i2c_c.device_address, &reg, 1, true);
    i2c_read_blocking(i2c_c.i2c, i2c_c.device_address, buff, bytes_to_read,
                      false);
}
