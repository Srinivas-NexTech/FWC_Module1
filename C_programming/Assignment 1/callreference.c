#include <stdio.h>

void swapReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapReference: a = %d, b = %d\n", *a, *b);
}

int main() {
    int x = 5, y = 10;
    swapReference(&x, &y);
    printf("After swapReference: x = %d, y = %d\n", x, y);
    return 0;
}
