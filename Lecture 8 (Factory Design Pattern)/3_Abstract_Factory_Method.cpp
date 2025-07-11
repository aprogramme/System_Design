#include<iostream>
using namespace std;

// Product 1 --> Burger
class Burger {
    public:
    virtual void prepare() = 0; // Pure virtual function
    virtual ~Burger() {} // Virtual destructor
};

class SimpleBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Simple Burger with bun, patty and ketchup!"<<endl;
    }
};

class CheeseBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Cheese Burger with bun, patty, cheese and lettuce!"<<endl;
    }
};

class ChickenBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Chicken Burger with gourmet bun, premium patty, cheese, lettuce and secret sauce!"<<endl;
    }
};

class SimpleWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Simple Wheat Burger with wheat, bun, patty and ketchup!"<<endl;
    }
};

class CheeseWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Cheese Wheat Burger with wheat, bun, patty, cheese and lettuce!"<<endl;
    }
};

class ChickenWheatBurger : public Burger {
    public:
    void prepare() override {
        cout<<"Preparing Chicken Wheat Burger with wheat, gourmet bun, premium patty, cheese, lettuce, chicken and secret sauce!"<<endl;
    }
};

// Product 2 --> Garlic Bread
class GarlicBread {
    public:
    virtual void prepare() = 0; // Pure virtual function
};

class SimpleGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Simple Garlic Bread with butter and garlic!"<<endl;
    }
};

class CheeseGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Cheese Garlic Bread with extra cheese and butter!"<<endl;
    }
};

class ChickenGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Chicken Garlic Bread with cheese, butter, chicken and garlic!"<<endl;
    }
};

class SimpleWheatGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Simple Wheat Garlic Bread with wheat, butter and garlic!"<<endl;
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Cheese Wheat Garlic Bread with extra wheat, cheese and butter!"<<endl;
    }
};

class ChickenWheatGarlicBread : public GarlicBread {
    public:
    void prepare() override {
        cout<<"Preparing Chicken Wheat Garlic Bread with wheat, cheese, butter, chicken and garlic!"<<endl;
    }
};

// factory and its concretions
class MealFactory {
    public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger : public MealFactory {
    public:
    Burger* createBurger(string& type) override {
        if(type == "simple") {
            return new SimpleBurger();
        }
        else if(type == "cheese") {
            return new CheeseBurger();
        }
        else if(type == "chicken") {
            return new ChickenBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "simple") {
            return new SimpleGarlicBread();
        }
        else if(type == "cheese") {
            return new CheeseGarlicBread();
        }
        else if(type == "chicken") {
            return new ChickenGarlicBread();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

class KingBurger : public MealFactory {
    Burger* createBurger(string& type) override {
        if(type == "simple") {
            return new SimpleWheatBurger();
        }
        else if(type == "cheese") {
            return new CheeseWheatBurger();
        }
        else if(type == "chicken") {
            return new ChickenWheatBurger();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "simple") {
            return new SimpleWheatGarlicBread();
        }
        else if(type == "cheese") {
            return new CheeseWheatGarlicBread();
        }
        else if(type == "chicken") {
            return new ChickenWheatGarlicBread();
        }
        else {
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

// Client 
int main() {
    string burgerType = "cheese";
    string garlicBreadType = "chicken";

    MealFactory* factory = new KingBurger ();

    Burger* burger = factory->createBurger(burgerType);
    GarlicBread* garlicbread = factory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicbread->prepare();

    return 0;
}