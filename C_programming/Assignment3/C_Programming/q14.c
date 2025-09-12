#include <stdio.h>

int square(int num) {
    int result = 0;
    for (int i = 0; i < num; i++) {
        result += num;
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Square of %d is %d\n", n, square(n));
    return 0;
}

