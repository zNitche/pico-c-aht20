#include "hardware/i2c.h"
#include "pico/stdlib.h"

#include "pico_aht20/aht20.h"
#include "pico_aht20/communication.h"
#include "pico_aht20/defines.h"
#include "pico_aht20/types.h"

void aht20_setup_i2c(AHT20_I2C i2c_c) {
    i2c_init(i2c_c.i2c, PICO_AHT20_I2C_BAUDRATE);

    gpio_set_function(i2c_c.sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(i2c_c.scl_pin, GPIO_FUNC_I2C);

    gpio_pull_up(i2c_c.sda_pin);
    gpio_pull_up(i2c_c.scl_pin);
}

bool aht20_is_initialized(AHT20_I2C i2c_c) {
    uint8_t out[1] = {0x00};

    _aht20_read_from_reg(i2c_c, 0x00, 1, out);

    return out[0] != 0x18;
}

void aht20_initialize(AHT20_I2C i2c_c) {
    uint8_t buff[3] = {0xBE, 0x08, 0x00};

    _aht20_write_to_reg(i2c_c, 0x00, buff, sizeof(buff));
}

void aht20_reset(AHT20_I2C i2c_c) {
    uint8_t buff[1] = {0xBA};

    _aht20_write_to_reg(i2c_c, 0x00, buff, sizeof(buff));
}

void aht20_read_raw_data(AHT20_I2C i2c_c, uint8_t output_buff[6]) {
    uint8_t command_buff[3] = {0xAC, 0x33, 0x00};

    _aht20_write_to_reg(i2c_c, 0x00, command_buff, sizeof(command_buff));
    sleep_ms(100);

    _aht20_read_from_reg(i2c_c, 0x00, 6, output_buff);
}

void aht20_get_measurements(AHT20_I2C i2c_c, float output_buff[2]) {
    // output_buff[0] = temperature
    // output_buff[1] = humidity

    uint8_t raw_readings[6] = {0x00};
    aht20_read_raw_data(i2c_c, raw_readings);

    float temperature = 0.0;
    float humidity = 0.0;

    // temperature parsing
    temperature = ((raw_readings[3] & 0xF) << 16) | (raw_readings[4] << 8) |
                  raw_readings[5];
    temperature = ((temperature / 1048576) * 200.0) - 50;

    // humidity parsing
    humidity = ((raw_readings[1] << 12) | (raw_readings[2] << 4) |
                (raw_readings[3] >> 4));
    humidity = humidity / 1048576 * 100;

    output_buff[0] = temperature;
    output_buff[1] = humidity;
}
