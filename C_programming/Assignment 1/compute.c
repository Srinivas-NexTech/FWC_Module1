#include <stdio.h>

void compute(int a, int b) {
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    if (b != 0) {
        printf("Quotient: %d\n", a / b);
        printf("Remainder: %d\n", a % b);
    } else {
        printf("Error: Division by zero!\n");
    }
}

int main() {
    int x = 18, y = 5;
    compute(x, y);
    return 0;
}
