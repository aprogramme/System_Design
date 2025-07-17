#include<iostream>
#include<vector>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class DepositOnlyAccount {
    public:
    virtual void deposit(double account) = 0;
};

class WithdrawOnlyAccount : public DepositOnlyAccount {
    public:
    virtual void withdraw(double account) = 0;
};

class SavingAccount : public WithdrawOnlyAccount {
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

class CurrentAccount : public WithdrawOnlyAccount {
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

class FixedDepositAccount : public DepositOnlyAccount {
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
};

class BankClient {
    private:
    vector<WithdrawOnlyAccount*> WithdrawAccount;
    vector<DepositOnlyAccount*> DepositAccount;

    public:
    BankClient(vector<WithdrawOnlyAccount*> WithdrawAccount, vector<DepositOnlyAccount*> DepositAccount ) {
        this->WithdrawAccount = WithdrawAccount;
        this->DepositAccount = DepositAccount;
    }

    void processTransactions() {
        for(WithdrawOnlyAccount* acc : WithdrawAccount) {
            acc->deposit(1000);
            acc->withdraw(500);
        }

        for(DepositOnlyAccount* acc : DepositAccount) {
            acc->deposit(5000);
        }
    }
};

int main() {
    vector<WithdrawOnlyAccount*> WithdrawAccount;
    WithdrawAccount.push_back(new SavingAccount());
    WithdrawAccount.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> DepositAccount;
    DepositAccount.push_back(new FixedDepositAccount());

    BankClient* client = new BankClient(WithdrawAccount, DepositAccount);
    client->processTransactions();
}