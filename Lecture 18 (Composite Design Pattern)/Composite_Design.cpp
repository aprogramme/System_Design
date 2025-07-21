#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

// Base interface for files and folders 
class FileSystemItem {
    public:
    virtual ~FileSystemItem() {}
    virtual void ls(int inden = 0) = 0;
    virtual void openAll(int inden = 0) = 0;
    virtual int getSize() = 0;
    virtual FileSystemItem* cd(const string& name) = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;
};

// Leaf: File 
class File : public FileSystemItem {
    private:
    string name;
    int size;

    public:
    File(const string& n, int s) {
        name = n;
        size = s;
    }

    void ls(int indent = 0) override {
        cout<<string(indent, ' ')<<name<<"\n";
    }

    void openAll(int indent = 0) override {
        cout<<string(indent, ' ')<<name<<"\n";
    }

    int getSize() override {
        return size;
    }

    FileSystemItem* cd(const string&) override {
        return nullptr;
    }

    string getName() override {
        return name;
    }

    bool isFolder() override {
        return false;
    }
};

class Folder : public FileSystemItem {
    private:
    string name;
    vector<FileSystemItem*> items;

    public:
    Folder(const string& n) {
        name = n;
    }

    ~Folder() {
        for (auto item : items) {
            delete item;
        }
    }

    void add(FileSystemItem* item) {
        items.push_back(item);
    }

    void ls(int indent = 0) override {
        for(auto child : items) {
            if(child->isFolder()) {
                cout<<string(indent, ' ')<<"+ "<<child->getName()<<"\n";
            }
            else {
                cout<<string(indent, ' ')<<child->getName()<<"\n";
            }
        }
    }

    void openAll(int indent = 0) override {
        cout<<string(indent, ' ')<<"+ "<<name<<"\n";
        for (auto item : items) {
            item->openAll(indent + 4 );
        }
    }

    int getSize() override {
        int totalSize = 0;
        for (auto item : items) {
            totalSize += item->getSize();
        }
        return totalSize;
    }

    FileSystemItem* cd(const string& target) override {
        for (auto item : items) {
            if (item->getName() == name && item->isFolder()) {
                return item;
            }
        }
        // not found or not a folder 
        throw runtime_error("Folder not found");
    }

    string getName() override {
        return name;
    }

    bool isFolder() override {
        return true;
    }
};

int main() {
    // Build file System 
    Folder* root = new Folder("root");
    root->add(new File("file1.txt", 100));
    root->add(new File("file2.txt", 200));

    Folder* docs = new Folder("docs");
    docs->add(new File("resume.pdf", 300));
    docs->add(new File("notes.txt", 150));
    root->add(docs);

    Folder* images = new Folder("images");
    images->add(new File("photo1.jpg", 500));
    root->add(images);

    // root->ls();

    // docs->ls();

    // root->openAll();

    // FileSystemItem* cwd = root->cd("docs");
    // if(cwd != nullptr) {
    //     cwd->ls();
    // }
    // else {
    //     cout<<"\n Could not cd into docs \n";
    // }

    cout<<root->getSize();

    // CleanUp
    delete root;
    return 0;
}