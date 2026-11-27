#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float basic;
    float houseRent;
    float medical;
    float gross;
};

int main() {
    struct Employee emp[100];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of employees (1-100 allowed).\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Employee %d (ID name basic house-rent medical): ", i + 1);
        scanf("%d %s %f %f %f", &emp[i].id, emp[i].name, &emp[i].basic, &emp[i].houseRent, &emp[i].medical);

        emp[i].gross = emp[i].basic + emp[i].houseRent + emp[i].medical;
    }

    printf("\n%-8s%-13s%-14s%-15s%-14s%s\n", "ID", "Name", "Basic", "HouseRent", "Medical", "Gross");
    for (i = 0; i < n; i++) {
        printf("%-8d%-13s%-14.2f%-15.2f%-14.2f%.2f\n", emp[i].id, emp[i].name, emp[i].basic, emp[i].houseRent, emp[i].medical, emp[i].gross);
    }

    return 0;
}