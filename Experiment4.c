#include <stdio.h>

int checkBalance(int balance, int amount) {
    if (balance >= amount) {
        return 1;
    }
    return 0;
}

int validateWithdrawal(int amount) {
    if (amount > 0 && amount % 500 == 0) {
        return 1;
    }
    return 0;
}

int withdrawMoney(int balance, int amount) {
    return balance - amount;
}

void displayTransaction(int success, int amount, int balance, char reason[]) {
    if (success == 1) {
        printf("\nTransaction Status : Successful\n");
        printf("Amount Withdrawn   : Tk %d\n", amount);
    } else {
        printf("\nTransaction Status : Failed (%s)\n", reason);
        printf("Amount Withdrawn   : Tk 0\n");
    }
    printf("Remaining Balance : Tk %d\n", balance);
}

int main() {
    int balance, amount;

    printf("Enter account balance: ");
    scanf("%d", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    if (validateWithdrawal(amount) == 0) {
        displayTransaction(0, 0, balance, "amount must be positive and a multiple of Tk 500");
    } else if (checkBalance(balance, amount) == 0) {
        displayTransaction(0, 0, balance, "insufficient balance");
    } else {
        balance = withdrawMoney(balance, amount);
        displayTransaction(1, amount, balance, "");
    }

    return 0;
}