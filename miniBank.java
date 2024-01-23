import java.util.Scanner;

public class BankSystem {

    static class BankAccount {
        int accountNumber;
        String holderName;
        double balance;
    }

    static class Bank {
        BankAccount[] accounts;
        int totalAccounts;

        Bank(int maxAccounts) {
            accounts = new BankAccount[maxAccounts];
            totalAccounts = 0;
        }
    }

    // Function to initialize the bank
    static void initializeBank(Bank bank) {
        bank.totalAccounts = 0;
    }

    // Function to create a new account
    static int createAccount(Bank bank, String holderName, double initialBalance) {
        if (bank.totalAccounts < bank.accounts.length) {
            BankAccount newAccount = new BankAccount();
            newAccount.accountNumber = bank.totalAccounts + 1;
            newAccount.holderName = holderName;
            newAccount.balance = initialBalance;

            bank.accounts[bank.totalAccounts] = newAccount;
            bank.totalAccounts++;

            return newAccount.accountNumber;
        } else {
            System.out.println("Cannot create more accounts. Bank is full.");
            return -1;
        }
    }

    // Function to display account information
    static void displayAccountInfo(Bank bank, int accountNumber) {
        if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
            BankAccount account = bank.accounts[accountNumber - 1];
            System.out.println("\nAccount Information:");
            System.out.println("Account Number: " + account.accountNumber);
            System.out.println("Account Holder: " + account.holderName);
            System.out.println("Account Balance: $" + account.balance);
        } else {
            System.out.println("Invalid account number.");
        }
    }

    // Function to deposit money into an account
    static void deposit(Bank bank, int accountNumber, double amount) {
        if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
            bank.accounts[accountNumber - 1].balance += amount;
            System.out.println("Deposit successful. New balance: $" + bank.accounts[accountNumber - 1].balance);
        } else {
            System.out.println("Invalid account number.");
        }
    }

    // Function to withdraw money from an account
    static void withdraw(Bank bank, int accountNumber, double amount) {
        if (accountNumber > 0 && accountNumber <= bank.totalAccounts) {
            if (bank.accounts[accountNumber - 1].balance >= amount) {
                bank.accounts[accountNumber - 1].balance -= amount;
                System.out.println("Withdrawal successful. New balance: $" + bank.accounts[accountNumber - 1].balance);
            } else {
                System.out.println("Insufficient funds.");
            }
        } else {
            System.out.println("Invalid account number.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Bank myBank = new Bank(100); // Adjust the maxAccounts parameter as needed

        int choice, accountNumber;
        String holderName;
        double initialBalance, amount;

        do {
            System.out.println("\nBank Menu:");
            System.out.println("1. Create Account");
            System.out.println("2. Display Account Information");
            System.out.println("3. Deposit");
            System.out.println("4. Withdraw");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter account holder name: ");
                    holderName = scanner.next();
                    System.out.print("Enter initial balance: ");
                    initialBalance = scanner.nextDouble();
                    accountNumber = createAccount(myBank, holderName, initialBalance);
                    System.out.println("Account created successfully. Account number: " + accountNumber);
                    break;

                case 2:
                    System.out.print("Enter account number: ");
                    accountNumber = scanner.nextInt();
                    displayAccountInfo(myBank, accountNumber);
                    break;

                case 3:
                    System.out.print("Enter account number: ");
                    accountNumber = scanner.nextInt();
                    System.out.print("Enter deposit amount: ");
                    amount = scanner.nextDouble();
                    deposit(myBank, accountNumber, amount);
                    break;

                case 4:
                    System.out.print("Enter account number: ");
                    accountNumber = scanner.nextInt();
                    System.out.print("Enter withdrawal amount: ");
                    amount = scanner.nextDouble();
                    withdraw(myBank, accountNumber, amount);
                    break;

                case 0:
                    System.out.println("Exiting the bank system. Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }

        } while (choice != 0);

        scanner.close();
    }
}
