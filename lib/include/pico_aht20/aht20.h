#pragma once

#include "pico_aht20/types.h"

void aht20_setup_i2c(AHT20_I2C i2c_c);
bool aht20_is_initialized(AHT20_I2C i2c_c);
void aht20_initialize(AHT20_I2C i2c_c);
void aht20_reset(AHT20_I2C i2c_c);
void aht20_read_raw_data(AHT20_I2C i2c_c, uint8_t output_buff[6]);
void aht20_get_measurements(AHT20_I2C i2c_c, float output_buff[2]);
