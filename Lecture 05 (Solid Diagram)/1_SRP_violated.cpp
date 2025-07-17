#include<iostream>
#include<vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
    public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Violated SRP: ShoppingCart is handling multiple responsibility
class ShoppingCart {
    private:
    vector<Product*> products;  // ShoppingCart->Product (has a relationship)

    public:
    // setter 
    void addProduct(Product *p) {
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

    // 2. Viotating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout<<"Shopping Cart Invoice\n";
        for(auto p : products) {
            cout<<p->name<<" - $"<<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }

    // 3. Viotating SRP - Save to DB (Should be in a separate class)
    void saveToDB() {
        cout<<"Saving shopping cart to database..."<<endl;
    }

};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 500));

    cart->printInvoice();
    cart->saveToDB();

    return 0;
}