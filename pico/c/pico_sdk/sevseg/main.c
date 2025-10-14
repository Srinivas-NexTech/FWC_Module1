#include "pico/stdlib.h"

int main() {
    int X, Y, Z, f;

    // Inputs: GPIO 2,3,4 
    gpio_init(2);
    gpio_set_dir(2, false);
    gpio_init(3);
    gpio_set_dir(3, false);
    gpio_init(4);
    gpio_set_dir(4, false);

    // Outputs: seven-seg on GPIO 5-11
    gpio_init(5); gpio_set_dir(5, true);
    gpio_init(6); gpio_set_dir(6, true);
    gpio_init(7); gpio_set_dir(7, true);
    gpio_init(8); gpio_set_dir(8, true);
    gpio_init(9); gpio_set_dir(9, true);  
    gpio_init(10); gpio_set_dir(10, true);
    gpio_init(11); gpio_set_dir(11, true);

    while (1) {
        // Read inputs
        Z = gpio_get(2);
        Y = gpio_get(3);
        X = gpio_get(4);

        // Logic function f = X'Y' + YZ
        f = ((!X && !Y) || (Y && Z));

        if (f == 1) {
            gpio_put(5, 1);
            gpio_put(6, 0);
            gpio_put(7, 0);
            gpio_put(8, 1);
            gpio_put(9, 1);
            gpio_put(10, 1);
            gpio_put(11, 1);
        } else {
	    gpio_put(5, 0);
            gpio_put(6, 0);
            gpio_put(7, 0);
            gpio_put(8, 0);
            gpio_put(9, 0);
            gpio_put(10, 0);
            gpio_put(11, 1);
        }

        sleep_ms(200);
    }
}
