#include <stdio.h>

void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapValue: a = %d, b = %d\n", a, b);
}

int main() {
    int x = 5, y = 10;
    swapValue(x, y);
    printf("After swapValue: x = %d, y = %d\n", x, y);
    return 0;
}
