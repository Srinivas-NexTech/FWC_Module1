#include "pico/stdlib.h"

int main() {
    int X, Y, Z;      // Current state inputs
    int A, B, C, D;   // Next state outputs to 7474
    int f;            // LED output

    // Inputs: X,Y,Z → Pico GPIO 2,3,4
    gpio_init(2); gpio_set_dir(2, false);
    gpio_init(3); gpio_set_dir(3, false);
    gpio_init(4); gpio_set_dir(4, false);

    // Outputs: A,B,C → GPIO 8,9,10, LED → GPIO 12, CLK → GPIO 13
    gpio_init(8);  gpio_set_dir(8, true);
    gpio_init(9);  gpio_set_dir(9, true);
    gpio_init(10); gpio_set_dir(10, true);
    gpio_init(12); gpio_set_dir(12, true);
    gpio_init(13); gpio_set_dir(13, true);

    while (1) {
        // Read current state
        X = gpio_get(4); // MSB
        Y = gpio_get(3);
        Z = gpio_get(2); // LSB

        // Next-state equations
        C = (X && !Y) || (X && !Z) || (!X && Y && Z); // MSB
        B = (!Y && Z) || (Y && !Z);                  // middle
        A = !Z;                                      // LSB
        D = 0;                                       // unused

        // Compute LED output
        f = (!X && !Z) || (X && Y);  // f=1 for XYZ=0,2,6,7

        // Drive LED
        gpio_put(12, f);

        // Output next state to 7474 D inputs
        gpio_put(8,  A);
        gpio_put(9,  B);
        gpio_put(10, C);

        // Toggle 7474 CLK
        gpio_put(13, 1);
        sleep_ms(500);
        gpio_put(13, 0);
        sleep_ms(500);
    }
}

