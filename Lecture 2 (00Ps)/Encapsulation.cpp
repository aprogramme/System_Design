#include<iostream>
#include<string>
using namespace std;

class SportCar {
    // character 
    private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

    public:
    SportCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // neutral
        tyre = "MRF";
    }

    // getter and setter 
    int getCurrentSpeed() {
        return currentSpeed;
    }

    string getTyre() {
        return this->tyre;
    }

    void setTyre(string tyre) {
        this->tyre = tyre;
    }

    // behaviour --> methods
    void startEngine() {
        isEngineOn = true;
        cout<<brand<<" "<<model<<" : Engine starts with a roar!"<<endl;
    }
    void shiftGear(int gear) {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Engine is off! Cannot shift gear!"<<endl;
            return;
        }
        currentGear = gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<endl;
    }

    void accelerate() {
        if(!isEngineOn) {
            cout<<brand<<" "<<model<<" : Engine is off! Cannot accelerate!"<<endl;
            return;
        }
        currentSpeed += 20;
        cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/h "<<endl;
    }

    void brake() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h "<<endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<" : Engine turned off!"<<endl;
    }

    ~SportCar() {}
};

// Main Method 
int main() {
    SportCar* mySportCar = new SportCar("Ford", "Mustang");

    mySportCar->startEngine();
    mySportCar->shiftGear(1);
    mySportCar->accelerate();
    mySportCar->shiftGear(2);
    mySportCar->accelerate();
    mySportCar->brake();
    mySportCar->stopEngine();

    // Setting arbitrary value to speed 
    // mySportCar->currentSpeed = 500;  // throw error because of currentSpeed is private 

    // cout<<"Current speed of my sport car is set to "<<mySportCar->currentSpeed<<endl;

    cout<<mySportCar->getCurrentSpeed();

    delete mySportCar;

    return 0;
}