#include <stdio.h>

int IsPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i  <= num/2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void AllPrimes(int a, int b) {
    printf("Prime numbers between %d and %d:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (IsPrime(i))
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int a, b;
    printf("Enter two numbers (start and end): ");
    scanf("%d %d", &a, &b);

    AllPrimes(a, b);
    return  0;
}
