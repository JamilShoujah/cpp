#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, string holder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = (initialBalance >= 0) ? initialBalance : 0; // Balance cannot be negative
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Withdrawal amount must be positive!" << endl;
        }
    }

    // Get the balance
    double getBalance() const {
        return balance;
    }

    // Display account details
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account("123456", "John Doe", 1000);

    account.display();

    account.deposit(500);
    account.withdraw(200);
    account.withdraw(1500);  // Insufficient funds

    account.display();

    return 0;
}

// Explanation:

// Encapsulation: The BankAccount class has private members (accountNumber, accountHolder, and balance) 
// to protect them from direct access outside the class.

// Public Methods: We provide public methods like deposit(), withdraw(), and getBalance() to manipulate and access the balance safely. 
// The deposit and withdrawal methods check for valid conditions (positive amounts and sufficient funds).
