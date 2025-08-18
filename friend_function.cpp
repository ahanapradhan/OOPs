#include <iostream>
using namespace std;

class BankAccount {
    double balance;
    string owner;

public:
    BankAccount(string n, double b) {
        balance = b;
        owner = n;
    }

    void display() {
        cout << owner << "'s balance: INR " << balance << endl;
    }

    // Friend function declaration
    friend void transfer(BankAccount &from, BankAccount &to, double amount);
};

// Friend function definition
void transfer(BankAccount &from, BankAccount &to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred INR " << amount << " from " << from.owner
             << " to " << to.owner << endl;
    } else {
        cout << "Insufficient balance in " << from.owner << "'s account." << endl;
    }
}

int main() {
    BankAccount alice("Alice", 1000);
    BankAccount bob("Bob", 500);

    alice.display();
    bob.display();

    cout << "\nTransfer INR 300 from Alice to Bob:\n";
    transfer(alice, bob, 300);

    alice.display();
    bob.display();

    return 0;
}
