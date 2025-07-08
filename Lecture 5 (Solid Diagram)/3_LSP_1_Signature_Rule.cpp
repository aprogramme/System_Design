#include<iostream>
using namespace std;

// 3.1 Method Argument Rule:
// Subtype method arguments can be identical or wider than the supertype 
// C++ imposes this by keeping signature identical 

// class Parent {
//     public:
//     virtual void print(string msg) {
//         cout<<"Parent: "<<msg<<endl;
//     }
// };

// class Child : public Parent {
//     public:
//     void print(string msg) override {
//         cout<<"Child: "<<msg<<endl;
//     }
// };

// class Client {
//     private:
//     Parent* p;

//     public:
//     Client(Parent* p) {
//         this->p = p;
//     }

//     void printMsg() {
//         p->print("Hello");
//     }
// };

// int main() {
//     Parent* parent = new Parent();
//     Child* child = new Child();

//     // Client client = new Client(parent);
//     Client* client = new Client(child);

//     client->printMsg(); 

//     return 0;
// }


// -----------------------------------------------------------------------------------------------------------------------------
// 3.2 Return Type Rule :
// Subtype override method return should be either identical or narrower then the parent method's return type
// This is also called as return type 'covariance'
// C++ enforces this by covariance 

// class Animal {
//     // some common Animal methods
// };

// class Dog : public Animal {
//     // Additional Dog methods specific to Dogs. 
// };

// class Parent {
//     public:
//     virtual Animal* getAnimal() {
//         cout<<"Parent: Returning Animal instance"<<endl;
//         return new Animal();
//     }
// }; 

// class Child : public Parent {
//     public:
//     Dog* getAnimal() override {
//         cout<<"Child: Returning Dog instance"<<std::endl;
//         return new Dog();
//     }
// };

// class Client {
//     private:
//     Parent* p;

//     public:
//     Client(Parent* p) {
//         this->p = p;
//     }

//      void takeAnimal() {
//         p->getAnimal();
//      }
// };

// int main() {
//     Parent* parent = new Parent();
//     Child* child = new Child();

//     // Client* client = new Client(parent);
//     Client* client = new Client(child);
//     client->takeAnimal();

//     return 0;
// }

// -----------------------------------------------------------------------------------------------------------------------------
// 3.3 Exception Rule :
// A subclass should throw fewer or narrower exceptions (but not additional or broader exception) than the parent.
// C++ does not enforces this. Hence no compilation error.

/*
|---std::logic_error         <--- For logical errors detected before runtime
|   |--std::invalid_argument      <-- Invalid function argumetn 
|   |--std::domain_error          <-- Function argument domain error 
|   |--std::length_error          <-- Exceeding valid length limits 
|   |--std::out_of_range          <-- Array or container index out of bounds 
|
|---std::runtime_error       <--- For errors that occur at runtime 
|   |--std::range_error           <-- Numeric result out of range 
|   |--std::overflow_error        <-- Arithmetic overflow 
|   |--std::underflow_error
|
*/

class Parent {
    public:
    virtual void getValue() noexcept(false) { // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
    public:
    void getValue() noexcept(false) override { // Child thows out_of_range exception
        throw out_of_range("Child error");
    }
};

class Client {
    private:
    Parent* p;

    public:
    Client(Parent* p) {
        this->p = p;
    }

    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout<<"Logic error exception occured: "<<e.what()<<endl;
        }
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);
    client->takeValue();

    return 0;
}