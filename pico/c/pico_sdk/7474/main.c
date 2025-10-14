#include "pico/stdlib.h"

int main() {
    int X, Y, Z, f;

    // Inputs: GPIO 2,3,4
    gpio_init(2); gpio_set_dir(2, false);
    gpio_init(3); gpio_set_dir(3, false);
    gpio_init(4); gpio_set_dir(4, false);

    // Outputs: GPIO 6 → D input of 7474
    //          GPIO 13 → CLK input of 7474
    gpio_init(6); gpio_set_dir(6, true);
    gpio_init(13); gpio_set_dir(13, true);

    while (1) {
        // Read inputs
        Z = gpio_get(2);
        Y = gpio_get(3);
        X = gpio_get(4);

        // Compute logic function f = X'Y' + YZ
        f = ((!X && !Y) || (Y && Z));

        // Output f to D input of 7474
        gpio_put(6, f);

        // Generate clock pulse for 7474
        gpio_put(13, 1);       // CLK HIGH
        sleep_ms(500);
        gpio_put(13, 0);       // CLK LOW
        sleep_ms(500);
    }
}
