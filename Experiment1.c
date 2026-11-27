#include <stdio.h>

float calculateBill(int units) {
    float bill;

    if (units <= 100) {
        bill = units * 5;
    } else if (units <= 200) {
        bill = 100 * 5 + (units - 100) * 6;
    } else {
        bill = 100 * 5 + 100 * 6 + (units - 200) * 8;
    }

    return bill;
}

float calculateVAT(float bill) {
    return bill * 5 / 100;
}

void displayBill(int id, char name[], int units, float bill, float vat) {
    float finalBill = bill + vat;

    printf("\n------ Electricity Bill ------\n");
    printf("Customer ID        : %d\n", id);
    printf("Customer Name      : %s\n", name);
    printf("Units Consumed     : %d\n", units);
    printf("Electricity Charge : Tk %.2f\n", bill);
    printf("VAT (5%%)           : Tk %.2f\n", vat);
    printf("Final Bill         : Tk %.2f\n", finalBill);
}

int main() {
    int id, units;
    char name[50];
    float bill, vat;

    printf("Enter customer ID: ");
    scanf("%d", &id);
    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter units consumed: ");
    scanf("%d", &units);

    if (units < 0) {
        printf("Invalid input: units consumed cannot be negative.\n");
        return 0;
    }

    bill = calculateBill(units);
    vat = calculateVAT(bill);
    displayBill(id, name, units, bill, vat);

    return 0;
}