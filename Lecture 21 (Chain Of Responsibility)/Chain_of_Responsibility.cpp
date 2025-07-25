#include<iostream>
using namespace std;

// Abstract Handler (Base Class) 
class MoneyHandler {
    protected:
    MoneyHandler* nextHandler;

    public:
    MoneyHandler() {
        this->nextHandler = nullptr;
    }

    void setNextHandler(MoneyHandler *next) {
        nextHandler = next;
    }

    virtual void dispense(int amount) = 0;
};

// Concrete Handler for 1000 Rs Notes
class ThousandHandler : public MoneyHandler {
    private:
    int numNotes;

    public:
    ThousandHandler(int numNotes) {
        this->numNotes = numNotes;
    }

    void dispense(int amount) override {
        int notesNeeded = amount / 1000;

        if(notesNeeded > numNotes) {
            notesNeeded = numNotes;
            numNotes = 0;
        }
        else {
            numNotes -= notesNeeded;
        }

        if(notesNeeded > 0) {
            cout << "Dispensing " << notesNeeded << " x Rs1000 notes. \n" << endl;
        }

        int remainingAmount = amount - (notesNeeded * 1000);
        if(remainingAmount > 0) {
            if(nextHandler != nullptr) 
            nextHandler->dispense(remainingAmount);
            else
            cout<<"Remaining amount of "<<remainingAmount<<" cannot be fullfilled (Insufficient fund in ATM)\n"<<endl;
        }
    }
};

// Concrete Handler for 500 Rs Notes
class FiveHundredHandler : public MoneyHandler {
    private:
    int numNotes;

    public:
    FiveHundredHandler(int numNotes) {
        this->numNotes = numNotes;
    }

    void dispense(int amount) override {
        int notesNeeded = amount / 500;

        if(notesNeeded > numNotes) {
            notesNeeded = numNotes;
            numNotes = 0;
        }
        else {
            numNotes -= notesNeeded;
        }

        if(notesNeeded > 0) {
            cout << "Dispensing " << notesNeeded << " x Rs500 notes. \n" << endl;
        }

        int remainingAmount = amount - (notesNeeded * 500);
        if(remainingAmount > 0) {
            if(nextHandler != nullptr) 
            nextHandler->dispense(remainingAmount);
            else
            cout<<"Remaining amount of "<<remainingAmount<<" cannot be fullfilled (Insufficient fund in ATM)\n"<<endl;
        }
    }
};

// Concrete Handler for 200 Rs Notes
class TwoHundredHandler : public MoneyHandler {
    private:
    int numNotes;

    public:
    TwoHundredHandler(int numNotes) {
        this->numNotes = numNotes;
    }

    void dispense(int amount) override {
        int notesNeeded = amount / 200;

        if(notesNeeded > numNotes) {
            notesNeeded = numNotes;
            numNotes = 0;
        }
        else {
            numNotes -= notesNeeded;
        }

        if(notesNeeded > 0) {
            cout << "Dispensing " << notesNeeded << " x Rs200 notes. \n" << endl;
        }

        int remainingAmount = amount - (notesNeeded * 200);
        if(remainingAmount > 0) {
            if(nextHandler != nullptr) 
            nextHandler->dispense(remainingAmount);
            else
            cout<<"Remaining amount of "<<remainingAmount<<" cannot be fullfilled (Insufficient fund in ATM)\n"<<endl;
        }
    }
};

// Concrete Handler for 100 Rs Notes
class OneHundredHandler : public MoneyHandler {
    private:
    int numNotes;

    public:
    OneHundredHandler(int numNotes) {
        this->numNotes = numNotes;
    }

    void dispense(int amount) override {
        int notesNeeded = amount / 100;

        if(notesNeeded > numNotes) {
            notesNeeded = numNotes;
            numNotes = 0;
        }
        else {
            numNotes -= notesNeeded;
        }

        if(notesNeeded > 0) {
            cout << "Dispensing " << notesNeeded << " x Rs100 notes. \n" << endl;
        }

        int remainingAmount = amount - (notesNeeded * 100);
        if(remainingAmount > 0) {
            if(nextHandler != nullptr) 
            nextHandler->dispense(remainingAmount);
            else
            cout<<"Remaining amount of "<<remainingAmount<<" cannot be fullfilled (Insufficient fund in ATM)\n"<<endl;
        }
    }
};

// Client Code 
int main() {
    // Creating handlers for each note type
    MoneyHandler* thousandHandler = new ThousandHandler(5);           // 5 notes of Rs1000
    MoneyHandler* fiveHundredHandler = new FiveHundredHandler(10);    // 10 notes of Rs500
    MoneyHandler* twoHundredHandler = new TwoHundredHandler(20);      // 20 notes of Rs200
    MoneyHandler* oneHundredHandler = new OneHundredHandler(50);      // 50 notes of Rs100

    // Setting up the Chain of Responsibility
    thousandHandler->setNextHandler(fiveHundredHandler);
    fiveHundredHandler->setNextHandler(twoHundredHandler);
    twoHundredHandler->setNextHandler(oneHundredHandler);

    int amountToDispense = 7000;

    // Initiating the chain
    cout<<"\nDispensing amount: Rs"<<amountToDispense<<"\n"<<endl;
    thousandHandler->dispense(amountToDispense);

    return 0;
}