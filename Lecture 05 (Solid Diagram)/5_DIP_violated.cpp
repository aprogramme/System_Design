#include<iostream>
using namespace std;

class MySQLDatabase {  // Low-Level Module
    public:
    void saveToSQL(string data) {
        cout<<"Executing SQL Query: INSERT INTO users VALUES('"<<data<<"')"<<endl;
    }
};

class MongoDbDatabase {  // Low-Level Module
    public:
    void saveToMongo(string data) {
        cout<<"Executing MongoDB Function: db.users.insert({name: "<<data<<"'})"<<endl;
    }
};

class UserService {  // High-Level module (Tightly coupled)
    private:
    MySQLDatabase sqlDb;  // Direct dependency on MySQL
    MongoDbDatabase mongoDb;   // Direct dependency on MySQL

    public:
    void storeUserToSQL(string user) {
        // MySQL-specific code 
        sqlDb.saveToSQL(user);
    }

    void storeUserToMongo(string user) {
        // Mongodb-specific code 
        mongoDb.saveToMongo(user);
    }
};

int main() {
    UserService service;
    service.storeUserToSQL("Aayush");
    service.storeUserToMongo("Raj");
}