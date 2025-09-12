#include <stdio.h>

float SimpleInterest(float principal, float rate, int timeInMonths) {
    float timeInYears = timeInMonths / 12.0;
    float simpleInterest = (principal * rate * timeInYears) / 100;
    return principal + simpleInterest;
}

int main() {
    float principal, rate, totalAmount;
    int timeInMonths;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter rate of interest (in %%): ");
    scanf("%f", &rate);

    printf("Enter time in months: ");
    scanf("%d", &timeInMonths);

    totalAmount = SimpleInterest(principal, rate, timeInMonths);
    printf("Total amount to be repaid: %.2f\n", totalAmount);

    return 0;
}
