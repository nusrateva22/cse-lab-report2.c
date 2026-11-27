#include <stdio.h>
#include <string.h>

int calculateTotal(int marks[], int n) {
    int i, total = 0;

    for (i = 0; i < n; i++) {
        total = total + marks[i];
    }

    return total;
}

float calculateAverage(int total, int n) {
    return (float) total / n;
}

void calculateGrade(float avg, char grade[], float *gpa) {
    if (avg >= 80) {
        strcpy(grade, "A+");
        *gpa = 4.00;
    } else if (avg >= 70) {
        strcpy(grade, "A");
        *gpa = 3.50;
    } else if (avg >= 60) {
        strcpy(grade, "A-");
        *gpa = 3.00;
    } else if (avg >= 50) {
        strcpy(grade, "B");
        *gpa = 2.50;
    } else if (avg >= 40) {
        strcpy(grade, "C");
        *gpa = 2.00;
    } else {
        strcpy(grade, "F");
        *gpa = 0.00;
    }
}

void displayResult(char name[], int id, int total, float avg, char grade[], float gpa, char result[]) {
    printf("\n------ Student Result ------\n");
    printf("Name    : %s\n", name);
    printf("ID      : %d\n", id);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", avg);
    printf("Grade   : %s\n", grade);
    printf("GPA     : %.2f\n", gpa);
    printf("Result  : %s\n", result);
}

int main() {
    char name[50], grade[3], result[5];
    int id, marks[5], i, total;
    int fail = 0;
    float avg, gpa;

    printf("Enter student name: ");
    scanf(" %[^\n]", name);
   printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter marks of 5 subjects: ");
    for (i = 0; i < 5; i++) {
    for (i = 0; i < 5; i++) {
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid input: marks must be between 0 and 100.\n");
            return 0;
        }
        if (marks[i] < 40) {
            fail = 1;
        }
    }

    total = calculateTotal(marks, 5);
    avg = calculateAverage(total, 5);
    calculateGrade(avg, grade, &gpa);

    if (fail == 1 || avg < 40) {
        strcpy(result, "Fail");
    } else {
        strcpy(result, "Pass");
    }

    displayResult(name, id, total, avg, grade, gpa, result);

    return 0;
}