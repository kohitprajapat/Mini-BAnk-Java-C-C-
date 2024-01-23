#include <iostream>
#include <string>

#define MAX_ACCOUNTS 100

struct BankAccount {
    int accountNumber;
    std::string holderName;
    double balance;
};

struct Bank {
    BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts;
};

// Function prototypes
void initializeBank(Bank &bank);
int createAccount(Bank &bank, const std::string &holderName, double initialBalance);
void displayAccountInfo(const Bank &bank, int accountNumber);
void deposit(Bank &bank, int accountNumber, double amount);
void withdraw(Bank &bank, int accountNumber, double amount);

int main() {
    Bank myBank;
    initializeBank(myBank);

    int choice, accountNumber;
    std::string holderName;
    double initialBalance, amount;

    do {
        std::cout << "\nBank Menu:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Display Account Information\n";
        std::cout << "3. Deposit\n";
        std::cout << "4. Withdraw\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter account holder name: ";
                std::cin >> holderName;
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                accountNumber = createAccount(myBank, holderName, initialBalance);
                std::cout << "Account created successfully. Account number: " << accountNumber << std::endl;
                break;

            case 2:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                displayAccountInfo(myBank, accountNumber);
                break;

            case 3:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                deposit(myBank, accountNumber, amount);
                break;

            case 4:
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                withdraw(myBank, accountNumber, amount);
                break;

            case 0:
                std::cout << "Exiting the bank system. Thank you!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

void initializeBank(Bank &bank) {
    bank.totalAccounts = 0;
}

int createAccount(Bank &bank, const std::string &holderName, double initialBalance) {
    if (bank.totalAccounts < MAX_ACCOUNTS) {
        BankAccount newAccount;
        newAccount.accountNumber = bank.totalAccounts + 1;
        newAccount.holderName = holderName;
        newAccount.balance = initialBalance;

        bank.accounts[bank.totalAccounts] = newAccount;
        bank.totalAccounts++;

        return newAccount.accountNumber;
    } else {
        std::cout << "Cannot create more accounts. Bank is full.\n";
        return -1;
    }
}

void displayAccountInfo(const Bank &bank, int accountNumber) {
    if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
        const BankAccount &account = bank.accounts[accountNumber - 1];
        std::cout << "\nAccount Information:\n";
        std::cout << "Account Number: " << account.accountNumber << "\n";
        std::cout << "Account Holder: " << account.holderName << "\n";
        std::cout << "Account Balance: $" << account.balance << "\n";
    } else {
        std::cout << "Invalid account number.\n";
    }
}

void deposit(Bank &bank, int accountNumber, double amount) {
    if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
        bank.accounts[accountNumber - 1].balance += amount;
        std::cout << "Deposit successful. New balance: $" << bank.accounts[accountNumber - 1].balance << "\n";
    } else {
        std::cout << "Invalid account number.\n";
    }
}

void withdraw(Bank &bank, int accountNumber, double amount) {
    if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
        if (bank.accounts[accountNumber - 1].balance >= amount) {
            bank.accounts[accountNumber - 1].balance -= amount;
            std::cout << "Withdrawal successful. New balance: $" << bank.accounts[accountNumber - 1].balance << "\n";
        } else {
            std::cout << "Insufficient funds.\n";
        }
    } else {
        std::cout << "Invalid account number.\n";
    }
}
