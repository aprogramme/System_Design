#include<iostream>
#include<string>

using namespace std; 

// Component Interface: defines a common interface for Mario and all power-up decorators.
class Character {
    public:
    virtual string getAbility() const = 0;
    virtual ~Character() {}  // virtural destructor
};

// Concrete Component: Basic Mario Character with no power-up 
class Mario : public Character {
    public:
    string getAbility() const override {
        return "Mario";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Character and "has-a" Character
class CharacterDecorator : public Character {
    protected:
    Character* character;  // Wrapped component

    public:
    CharacterDecorator(Character* c) {
        this->character = c;
    }
};

// Concrete Decorator: Height-Increasing Power-up 
class HeightUp : public CharacterDecorator {
    public:
    HeightUp(Character* c) : CharacterDecorator(c) { }

    string getAbility() const override {
        return character->getAbility() + " with HeightUp";
    }
};

// Concrete Decorator: Gun Shooting Power-up 
class GunPowerUp : public CharacterDecorator {
    public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }

    string getAbility() const override {
        return character->getAbility() + " with Gun";
    }
};

// Concrete Decorator: Star Power-up (temporary ability).
class StarPowerUp : public CharacterDecorator {
    public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }

    string getAbility() const override {
        return character->getAbility() + " with Star Power (Limited Time)";
    }

    ~StarPowerUp() {
        cout<<"Destroying StarPowerUp Decorator"<<endl;
    }
};

int main() {
    // Create a basic Mario character .
    Character* mario = new Mario();
    cout<<"Basic Character:"<<mario->getAbility()<<endl;

    // Decorator Mario with a HeightUpPower.
    mario = new HeightUp(mario);
    cout<<"After HeightUp: "<<mario->getAbility()<<endl;

    // Decorator Mario with a GunPower.
    mario = new GunPowerUp(mario);
    cout<<"After GunPowerUp: "<<mario->getAbility()<<endl;

    // Finally, add a StarPowerUp decorator.
    mario = new StarPowerUp(mario);
    cout<<"After StartPowerUp: "<<mario->getAbility()<<endl;

    delete mario;

    return 0;
}