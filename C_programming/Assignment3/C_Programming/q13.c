#include <stdio.h>

int product(int a, int b) {
    int result = 0;
    int positive = 1;

    if (b < 0) {
        positive = -1;
        b = -b;
    }
    for (int i = 0; i < b; i++) {
        result += a;
    }

    if (positive == -1)
        result = -result;

    return result;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Product = %d\n", product(x, y));
    return 0;
}

