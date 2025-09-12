#include <stdio.h>

int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

int Mul(int a, int b) {
    return a * b;
}

int Div(int a, int b) {
    if (b != 0)
        return a / b;
    else {
        printf("Division by zero error!\n");
        return 0;
    }
}

int Mod(int a, int b) {
    if (b != 0)
        return a % b;
    else {
        printf("Modulo by zero error!\n");
        return 0;
    }
}

int main() {
    int x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Add: %d\n", Add(x, y));
    printf("Subtract: %d\n", Sub(x, y));
    printf("Multiply: %d\n", Mul(x, y));
    printf("Divide: %d\n", Div(x, y));
    printf("Modulo: %d\n", Mod(x, y));

    return 0;
}

