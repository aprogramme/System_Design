#include<iostream>

using namespace std;

class Burger {
    public:
    virtual void prepare() = 0; // Pure virtual function
    virtual ~Burger() {} // Virtual destructor
};

class BasicBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Basic Burger with bun, patty and ketchup!"<<endl;
    }
};

class StandardBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Standard Burger with bun, patty, cheese and lettuce!"<<endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce and secret sauce!"<<endl;
    }
};

class BasicWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Basic Wheat Burger with wheat, bun, patty and ketchup!"<<endl;
    }
};

class StandardWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Standard Wheat Burger with wheat, bun, patty, cheese and lettuce!"<<endl;
    }
};

class PremiumWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Premium Wheat Burger with wheat, gourmet bun, premium patty, cheese, lettuce and secret sauce!"<<endl;
    }
};

// Factory and its Concretion
class BurgerFactory {
    public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
    public:
    Burger* createBurger(string& type) override {
        if(type == "basic") {
            return new BasicBurger();
        }
        else if(type == "standard") {
            return new StandardBurger();
        }
        else if(type == "premium") {
            return new PremiumBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
    public:
    Burger* createBurger(string& type) override {
        if(type == "basic") {
            return new BasicWheatBurger();
        }
        else if(type == "standard") {
            return new StandardWheatBurger();
        }
        else if(type == "premium") {
            return new PremiumWheatBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

// Client 
int main() {
    string type = "premium";

    BurgerFactory* factory = new KingBurger();
    Burger* burger = factory->createBurger(type);
    burger->prepare();

    cout<<"------------------------------------"<<endl;

    BurgerFactory* factory1 = new SinghBurger();
    Burger* burger1 = factory1->createBurger(type);
    burger1->prepare();

    return 0;
}