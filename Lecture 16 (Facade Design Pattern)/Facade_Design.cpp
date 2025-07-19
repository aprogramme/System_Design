#include<iostream>
using namespace std;

// SubSystems {
class PowerSupply {
    public:
    void providePower() {
        cout<< "Power supply is providing power...."<<endl;
    }
};

class CoolingSystem {
    public:
    void startFans() {
        cout<< "Cooling system Fans started..."<<endl;
    }
};

class CPU {
    public:
    void initialize() {
        cout<< "CPU is initializing..."<<endl;
    }
};

class Memory {
    public:
    void selfTest() {
        cout<<"Memory is running self-test..."<<endl;
    }
};

class HardDrive {
    public:
    void spinUp() {
        cout<<"Hard Drive is spinning up..."<<endl;
    }
};

class BIOS {
    public:
    void boot(CPU& cpu, Memory& memory) {
        cout<<"BIOS: Booting CPU and Memory checks..."<<endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
    public:
    void load() {
        cout<<"Operating System is loading..."<<endl;
    }
};

// Facade 
class ComputerFacade {
    private:
    PowerSupply powerSupply;
    CoolingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;

    public:
    void startComputer() {
        cout<<"----- Starting Computer -----"<<endl;
        powerSupply.providePower();
        coolingSystem.startFans();
        bios.boot(cpu, memory);
        hardDrive.spinUp();
        os.load();
        cout<<"Computer Booted successfully!"<<endl;
    }
};

// Client  
int main() {
    ComputerFacade computer;
    computer.startComputer();

    return 0;
}