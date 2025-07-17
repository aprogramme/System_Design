// followed in wrong way 
#include<iostream>
#include<vector>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class Account {
    public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
}; 

class SavingAccount : public Account {
    private:
    double balance;

    public:
    SavingAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Saving Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance -= amount;
            cout<<"Withdraw: "<<amount<<" from Saving Account. New Balance: "<<balance<<endl;
        } else {
            cout<<"Insufficient funds in Saving Account\n";
        }
    }
};

class CurrentAccount : public Account {
    private:
    double balance;

    public:
    CurrentAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Current Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        if(balance >= amount) {
            balance -= amount;
            cout<<"Withdraw: "<<amount<<" from Current Account. New Balance: "<<balance<<endl;
        } else {
            cout<<"Insufficient funds in Current Account\n";
        }
    }
};

class FixedDepositAccount : public Account {
    private:
    double balance;

    public:
    FixedDepositAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout<<"Deposited: "<<amount<<" in Fixed Account. New Balance: "<<balance<<endl;
    }

    void withdraw(double amount) {
        throw logic_error("Withdraw not allowed in Fixed Account");
    }
};

// violate open-close principle
class BankClient {
    private:
    vector<Account*> account;

    public:
    BankClient(vector<Account*> account) {
        this->account = account;
    }

    void processTransaction() {
        for(Account* acc : account) {
            acc->deposit(1000);  // All accounts allow deposits

            // Checking account type explicitly 
            if(typeid(*acc) == typeid(FixedDepositAccount)) {
                cout<<"Skipping withdrawal for Fixed Account.\n";
            } else {
                try{
                    acc->withdraw(500);
                } catch(const logic_error& e) {
                    cout<<"Exception: "<<e.what()<<endl;
                }
            }
        }
    }
};

int main() {
    vector<Account*> account;
    account.push_back(new SavingAccount());
    account.push_back(new CurrentAccount());
    account.push_back(new FixedDepositAccount());

    BankClient* client = new BankClient(account);
    client->processTransaction();

    return 0;
}