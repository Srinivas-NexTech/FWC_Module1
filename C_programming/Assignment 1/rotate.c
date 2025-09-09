#include <stdio.h>

void rotate(int *a, int *b, int *c) {
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;
}

int main() {
    int x = 1, y = 2, z = 3;
    rotate(&x, &y, &z);
    printf("After Rotating: x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
