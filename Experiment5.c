#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input: factorial of a negative number is undefined.\n");
        return 0;
    }

    if (n > 20) {
        printf("Input too large: the result does not fit in a long long.\n");
        return 0;
    }

    printf("\nFactorial of %d = %lld\n", n, factorial(n));

    return 0;
}