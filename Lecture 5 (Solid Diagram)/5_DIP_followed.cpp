#include<iostream>
using namespace std;

// Abstraction (Interface)
class Database {
    public:
    virtual void save(string data) = 0;  // Pure virtual function
};

// MySQL implementation (Low-Level module)
class MySQLDatabase : public Database {
    public:
    void save(string data) override {
        cout<<"Executing SQL Query: INSERT INTO users VALUES('"<<data<<"')"<<endl;
    }
};

// MongoDb implementation (Low-Level module)
class MongoDbDatabase : public Database {
    public:
    void save(string data) {
        cout<<"Executing MongoDB Function: db.users.insert({name: "<<data<<"'})"<<endl;
    }
};

// High-Level module (Now loosely coupled)
class UserService {
    private:
    Database* db; // Dependency Injection

    public:
    UserService(Database* database) {
        db = database;
    }

    void storeUser(string user) {
        db->save(user);
    }
};

int main() {
    MySQLDatabase mySql;
    MongoDbDatabase mongodb;

    UserService service1(&mySql);
    service1.storeUser("Aayush");

    UserService service2(&mongodb);
    service2.storeUser("Raj");
}