#include<iostream>
using namespace std;

// 1. Class Invariant :
// Class Invariant of a parent class Object should not be broken by child class Object 
// Hence child class can either maintain or strengthen the invariant but never narrows it down 

// Invariant : Balance cannot be negative 
// class BankAccount {
//     protected:
//     double balance;

//     public:
//     BankAccount(double b) {
//         if(b<0) throw invalid_argument("Balance can't be negative");
//         balance = b;
//     }

//     virtual void withdraw(double amount) {
//         if(balance - amount < 0) throw runtime_error("Insufficient funds");
//         balance -= amount;
//         cout<<"Amount withdrawn. Ramaining balance is "<<balance<<endl;
//     }
// };

// class CheatAccount : public BankAccount {
//     public:
//     CheatAccount(double b) : BankAccount(b) {}

//     void withdraw(double amount) override {
//         balance -= amount; // LSP break! Negative balance allowed
//         cout<<"Amout withdrawn. Remaining balance is "<<balance<<endl;
//     }
// };

// int main() {
//     // BankAccount* bankAccount = new BankAccount(100);
//     // bankAccount->withdraw(200);

//     CheatAccount* cheatAccount = new CheatAccount(100);
//     cheatAccount->withdraw(200);
// }

// -----------------------------------------------------------------------------------
// 2. History Constraint 
// Sub class methods should not be allowed state changes what base class never allowed

class BankAccount {
    protected:
    double balance;

    public:
    BankAccount(double b) {
        if(b<0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }

    // History Constraint : Withdraw should be allowed
    virtual void withdraw(double amount) {
        if(balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<<"Amout withdrawn. Remaining balance is "<<balance<<endl;
    }
};

class FixedAccount : public BankAccount {
    public:
    FixedAccount(double b) : BankAccount(b) {}

    //LSP break! History constraint broke!
    // Parent class behaviour change : Now withdraw is not allowed. 
    // This class will brake client code that relies on withdraw.

    void withdraw(double amount) override {
        throw runtime_error("Withdraw not allowed in Fixed Account");
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(50);

    FixedAccount* fixedAccount = new FixedAccount(100);
    fixedAccount->withdraw(50);
}