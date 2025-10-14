#include "pico/stdlib.h"

int main() {
    gpio_init(6);
    gpio_set_dir(6, false);   // X input
    gpio_init(7);
    gpio_set_dir(7, false);   // Y input
    gpio_init(8);
    gpio_set_dir(8, false);   // Z input
    gpio_init(9);
    gpio_set_dir(9, true);    // F output

    int X, Y, Z, F;

    while (1) {
        X = gpio_get(6);
        Y = gpio_get(7);
        Z = gpio_get(8);

        F = ((!X && !Y) || (Y && Z));

        if (F)
            gpio_put(9, 1);   // LED ON
        else
            gpio_put(9, 0);   // LED OFF
    }
}
