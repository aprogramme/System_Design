#include<iostream>
using namespace std;

// 1. Pre-Condition : 
// A Pre-condition must be statisfied before a method can be executed 
// Sub classes can weaken the precondition but cannot strengthen it 

// class User {
//     public:
//     // Preconditon : Password must be at least 8 character long 
//     virtual void setPassword(string password) {
//         if(password.length() < 8) {
//             throw invalid_argument("Password must be at least 8 character long");
//         }
//         cout<<"Password set successfully"<<endl;
//     }
// };

// class AdminUser : public User {
//     public:
//     // Precondition: Password must be at least 6 character  
//     void setPassword(string password) override {
//         if(password.length() < 6) {
//             throw invalid_argument("Password must be at least 6 character long");
//         }
//         cout<<"Password set successfully"<<endl;
//      }
// };

// int main() {
//     // User* user = new User();
//     User* user = new AdminUser();
//     user->setPassword("Admin1"); // Works fine: AdminUser shorter password.

//     return 0;
// }

// 2. Post-Condition : 
// A Post-condition must be statisfied after a method is executed.
// Sub class can strengthen the post-conditon but cannot weaken it.

class Car {
    protected:
    int speed;

    public:
    Car() {
        speed = 0;
    }

    void accelerate() {
        cout<<"Accelerating"<<endl;
        speed += 30;
    }

    // Post-Condition : Speed must reduce after brake 
    virtual void brake() {
        cout<<"Applying brakes."<<endl;
        speed -= 20;
    }
};

// Sub-class can strengthen post-condition - Does not violate LSP 
class HybridCar : public Car {
    private:
    int charge;

    public:
    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake 
    // PostCondition : Charge must increase 
    void brake() {
        cout<<"Applying brakes"<<endl;
        speed -= 20;
        charge += 10;
    }
};

int main() {
    Car* car = new Car();
    car->brake();
}