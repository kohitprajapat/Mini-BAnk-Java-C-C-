#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    char holderName[50];
    double balance;
};

struct Bank {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts;
};

// Function prototypes
void initializeBank(struct Bank *bank);
int createAccount(struct Bank *bank, const char *holderName, double initialBalance);
void displayAccountInfo(const struct Bank *bank, int accountNumber);
void deposit(struct Bank *bank, int accountNumber, double amount);
void withdraw(struct Bank *bank, int accountNumber, double amount);

int main() {
    struct Bank myBank;
    initializeBank(&myBank);

    int choice, accountNumber;
    char holderName[50];
    double initialBalance, amount;

    do {
        printf("\nBank Menu:\n");
        printf("1. Create Account\n");
        printf("2. Display Account Information\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account holder name: ");
                scanf("%s", holderName);
                printf("Enter initial balance: ");
                scanf("%lf", &initialBalance);
                accountNumber = createAccount(&myBank, holderName, initialBalance);
                printf("Account created successfully. Account number: %d\n", accountNumber);
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                displayAccountInfo(&myBank, accountNumber);
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                deposit(&myBank, accountNumber, amount);
                break;

            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdraw(&myBank, accountNumber, amount);
                break;

            case 0:
                printf("Exiting the bank system. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void initializeBank(struct Bank *bank) {
    bank->totalAccounts = 0;
}

int createAccount(struct Bank *bank, const char *holderName, double initialBalance) {
    if (bank->totalAccounts < MAX_ACCOUNTS) {
        struct BankAccount newAccount;
        newAccount.accountNumber = bank->totalAccounts + 1;
        strcpy(newAccount.holderName, holderName);
        newAccount.balance = initialBalance;

        bank->accounts[bank->totalAccounts] = newAccount;
        bank->totalAccounts++;

        return newAccount.accountNumber;
    } else {
        printf("Cannot create more accounts. Bank is full.\n");
        return -1;
    }
}

void displayAccountInfo(const struct Bank *bank, int accountNumber) {
    if (accountNumber > 0 && accountNumber <= bank->totalAccounts) {
        const struct BankAccount *account = &bank->accounts[accountNumber - 1];
        printf("\nAccount Information:\n");
        printf("Account Number: %d\n", account->accountNumber);
        printf("Account Holder: %s\n", account->holderName);
        printf("Account Balance: $%.2f\n", account->balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void deposit(struct Bank *bank, int accountNumber, double amount) {
    if (accountNumber > 0 && accountNumber <= bank->totalAccounts) {
        bank->accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", bank->accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void withdraw(struct Bank *bank, int accountNumber, double amount) {
    if (accountNumber > 0 && accountNumber <= bank->totalAccounts) {
        if (bank->accounts[accountNumber - 1].balance >= amount) {
            bank->accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: $%.2f\n", bank->accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}
