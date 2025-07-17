#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// Abstraction for document elements 
class DocumentElement {
    public:
    virtual string render() = 0;
};

// Concrete implementation for text elements 
class TextElement : public DocumentElement {
    private:
    string text;

    public:
    TextElement(string text) {
        this->text = text;
    }

    string render() override {
        return text;
    }
}; 

// Concrete implementation for image elements 
class ImageElement : public DocumentElement {
    private:
    string imagePath;

    public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }

    string render() override {
        return "[Image: "+ imagePath + " ]";
    }
};

// NewLineElement represent a line break in the document. 
class NewLineElement : public DocumentElement {
    public:
    string render() override {
        return "\n";
    }
};

// TabSpaceElement represent a tab space in the document. 
class TabSpaceElement : public DocumentElement {
    public:
    string render() override {
        return "\t";
    }
};

// Document class responsible for holding a collection of element 
class Document {
    private:
    vector<DocumentElement*> DocumentElements;

    public:
    void addElement(DocumentElement* element) {
        DocumentElements.push_back(element);
    }

    // Render the document by concatenating the render output of all elements.
    string render() {
        string result;
        for(auto element : DocumentElements) {
            result += element->render();
        }
        return result;
    }
};

// Persistance Interface 
class Persistance {
    public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistance 
class FileStorage : public Persistance {
    public:
    void save(string data) override {
        ofstream outFile("document1.txt");
        if(outFile) {
            outFile<<data;
            outFile.close();
            cout<<"Document saved to document.txt"<<endl;
        }
        else {
            cout<<"Error: Unable to open file for writing."<<endl;
        }
    }
};

// Placeholder DBStorage implementation 
class DBStorage : public Persistance {
    public:
    void save(string data) override {
        // Save to db
    }
};

// DocumentEditor class manageing client interaction 
class DocumentEditor {
    private:
    Document* document;
    Persistance* storage;
    string renderedDocument;

    public:
    DocumentEditor(Document* document, Persistance* storage) {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }

    void addImage(string ImagePath) {
        document->addElement(new ImageElement(ImagePath));
    }

    // Add a new line to the document 
    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    // Add a tab space to the document 
    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument() {
        storage->save(renderDocument());
    }
};

// Client usage Example 
int main() {
    Document* document = new Document();
    Persistance* persistance = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistance);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello World");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("image.jpg");

    // Render and display the final document.
    cout<<editor->renderDocument()<<endl;

    editor->saveDocument();

    return 0;
}
