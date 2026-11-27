#include <stdio.h>

struct Patient {
    int id;
    char name[30];
    int age;
    char disease[30];
    float fee;
};

int main() {
    struct Patient p[100];
    int n, i;
    float total = 0;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of patients (1-100 allowed).\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Patient %d (ID name age disease fee): ", i + 1);
        scanf("%d %s %d %s %f", &p[i].id, p[i].name, &p[i].age, p[i].disease, &p[i].fee);
        total = total + p[i].fee;
    }

    printf("\n%-6s%-10s%-7s%-13s%s\n", "ID", "Name", "Age", "Disease", "Fee");
    for (i = 0; i < n; i++) {
        printf("%-6d%-10s%-7d%-13s%.2f\n", p[i].id, p[i].name, p[i].age, p[i].disease, p[i].fee);
    }

    printf("\nTotal consultation fees collected = Tk %.2f\n", total);

    return 0;
}