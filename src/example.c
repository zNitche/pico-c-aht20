#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include "pico_aht20/aht20.h"
#include "pico_aht20/defines.h"

int main() {
    stdio_init_all();

#ifdef DEBUG
    // waiting for input
    getchar();
#endif

    AHT20_I2C aht20_i2c = {.i2c = i2c1,
                           .device_address = PICO_AHT20_I2C_DEFAULT_ADDRESS,
                           .sda_pin = 18,
                           .scl_pin = 19};

    aht20_setup_i2c(aht20_i2c);
    sleep_ms(100);

    aht20_reset(aht20_i2c);
    sleep_ms(150);

    aht20_initialize(aht20_i2c);
    sleep_ms(150);
    
    printf("connected\n");

    while (1) {
        float readings[2] = {0.0};

        aht20_get_measurements(aht20_i2c, readings);

        printf("temperature: %f\n", readings[0]);
        printf("humidity: %f\n\n", readings[1]);

        sleep_ms(1000);
    }
}
