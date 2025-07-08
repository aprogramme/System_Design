// STATIC POLYMORPHISM 
// Method Overloading

#include<iostream>
#include<string>
using namespace std;
 
class ManualCar {
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    public:
    ManualCar(string b, string m) {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0;
    }

    void startEngine() {
        isEngineOn = true;
        cout<<brand<<" "<<model<<" : Engine starts!"<<endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Engine turned off!"<<endl;
    }

    // Overloading accelerate - Static polymorphism 
    void accelerate() {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Cannot accelerate! Engine is off!"<<endl;
        }
        currentSpeed += 20;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h "<<endl;
    }

    void accelerate(int speed) {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Cannot accelerate! Engine is off!"<<endl;
        }
        currentSpeed += speed;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h "<<endl;
    }

    void brake() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h "<<endl;
    }

    void shiftGear(int gear) {  // Unique method for Manual Car
        currentGear = gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
    }

    virtual ~ManualCar() {};
};

int main() {
    ManualCar* myManualCar = new ManualCar("Toyota", "Fortuner");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(40);
    myManualCar->shiftGear(1);
    myManualCar->brake();
    myManualCar->stopEngine();

    // cleanup
    delete myManualCar;
}