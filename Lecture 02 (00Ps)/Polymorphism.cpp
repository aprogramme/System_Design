// DYNAIC POLYMORPHISM
// Method Overriding 

#include<iostream>
#include<string>
using namespace std;

// Base Car Class 
class Car {
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b, string m) {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    // Common methods for All cars.
    void startEngine() {
        isEngineOn = true;
        cout<<brand<<" "<<model<<" : Engine starts!"<<endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Engine turned off!"<<endl;
    }

    virtual void accelerate() = 0;  // Abstract method for dymanic polymorphism
    virtual void brake() = 0;  // Abstract method for dymanic polymorphism

    virtual ~Car() {};
};

class ManualCar : public Car {
    private:
    int currentGear = 0;

    public:
    ManualCar(string b, string m) : Car(b, m) {
        this->currentGear = 0;
    }

    // Specialized method for Manual Car 
    void shiftGear(int gear) {  // Unique method for Manual Car
        currentGear = gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
    }

    // Overriding accelerate - Dynamic Polymorphism 
    void accelerate() {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate!"<<endl;
            return;
        }

        currentSpeed += 20;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h "<<endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h "<<endl;
    }

};

class ElectricCar : public Car {
    private:
    int batteryLevel;

    public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLevel = 100;
    }

    // Specialized method for Electric Car
    void chargeBattery() {  // Unique method for Manual Car
        batteryLevel = 100;
        cout<<brand<<" "<<model<<" : Battery fully charged! "<<batteryLevel<<endl;
    }

    // Overriding accelerate - Dynamic Polymorphism 
    void accelerate() {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate!"<<endl;
            return;
        }
        if(batteryLevel <= 0) {
            cout<<brand<<" "<<model<<" : Battery dead! Cannot accelerate"<<endl;
            return;
        }

        batteryLevel -= 10;
        currentSpeed += 15;
        cout<<brand<<" "<<model<<" : Accelerate to "<<currentSpeed<<" km/h. Battery at "<<batteryLevel<<" %"<<endl;
    }

    // Overriding brake - Dynamic Polymorphism
    void brake() {
        currentSpeed -= 15;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Regenerative Braking! Speed is now "<<currentSpeed<<" km/h. Battery at "<<batteryLevel<<" %"<<endl;
    }
};

// Main Method 
int main() {
    Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"---------------------------------------"<<endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
}