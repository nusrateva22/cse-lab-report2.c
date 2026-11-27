#include <stdio.h>

float getPercent(float amount) {
    if (amount >= 5000) {
        return 10;
    } else if (amount >= 3000) {
        return 5;
    } else {
        return 0;
    }
}

float calculateDiscount(float amount) {
    return amount * getPercent(amount) / 100;
}

float calculateFinalAmount(float amount, float discount) {
    return amount - discount;
}

void displayReceipt(char name[], float amount, float discount, float finalAmount) {
    printf("\n------ Receipt ------\n");
    printf("Customer Name : %s\n", name);
    printf("Purchase Amount: Tk %.2f\n", amount);
    printf("Discount (%.0f%%) : Tk %.2f\n", getPercent(amount), discount);
    printf("Final Payable : Tk %.2f\n", finalAmount);
}

int main() {
    char name[50];
    float amount, discount, finalAmount;

    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter purchase amount: ");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Invalid input: purchase amount cannot be negative.\n");
        return 0;
    }

    discount = calculateDiscount(amount);
    finalAmount = calculateFinalAmount(amount, discount);
    displayReceipt(name, amount, discount, finalAmount);

    return 0;
}