#include<iostream>
#include<vector>

using namespace std;

// Product class representing any item in eCommerce 
class Product {
    public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// 1. ShoppingCart: Only responsible for Cart related business logic.
class ShoppingCart {
    private:
    vector<Product*> products;  // Store heap-allocated products

    public:
    // setter 
    void addProduct(Product* p) {
        products.push_back(p);
    }
    // getter 
    const vector<Product*> &getProducts() {
        return products;
    }

    // 1. Calculating total price in cart 
    double calculateTotal() {
        double total = 0;
        for(auto p : products) {
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices 
class ShoppingCartPrinter {
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout<<"Shopping Cart Invoice\n";
        for(auto p : cart->getProducts()) {
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }

};

// Abstraction 
class Persistence {
    private:
    ShoppingCart* cart;

    public:
    virtual void save(ShoppingCart* cart) = 0; // Pure virtual function
};

class SQLPersistence : public Persistence {
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to SQL database..."<<endl;
    }
};

class MongodbPersistence : public Persistence {
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to Mongodb database..."<<endl;
    }
};

class FilePersistence : public Persistence {
    void save(ShoppingCart* cart) override {
        cout<<"Saving shopping cart to file..."<<endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 1000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* sql = new SQLPersistence();
    Persistence* mongo = new MongodbPersistence();
    Persistence* file = new FilePersistence();

    sql->save(cart); // Save to SQL database
    mongo->save(cart); // Save to Mongodb database
    file->save(cart); // Save to file database

    return 0;
}