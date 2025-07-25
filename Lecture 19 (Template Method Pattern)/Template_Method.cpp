#include<iostream>
#include<string>

using namespace std;

// ----------------------------------------------------
// 1. Base class defining the template method 
// ----------------------------------------------------

class ModelTrainer {
    public:
    // The template method - final so subclasses can't change the sequence 
    void trainPipeline(const string& dataPath) {
        loadData(dataPath);
        preprocessData();
        trainModel();         // subclass-spcific
        evaluateModel();      // subclass-spcific
        saveModel();          // subclass-spcific or default
    }

    protected:
    void loadData(const string& dataPath) {
        cout << "[Common] Loading data from: " << dataPath << endl;
    }

    virtual void preprocessData() {
        cout << "[Common] Splitting into train/test and normalizing" << endl;
    }

    virtual void trainModel() = 0; // Pure virtual function, must be implemented by subclasses
    virtual void evaluateModel() = 0; // Pure virtual function, must be implemented by subclasses

    // Provide a default save, but subcclasses can override if needed
    virtual void saveModel() {
        cout << "[Common] Saving model to disk as default format" << endl;
    }
};

// -------------------------------------------------
// 2. Concrete subclass: Neural Network 
// -------------------------------------------------

class NeuralNetworkTrainer : public ModelTrainer {
    protected:
    void trainModel() override {
        cout << "[Neural Network] Training neural network model for 100 epochs..." << endl;
        // pseudo-code : forrward/backward passes, gradient descent...
    }
    void evaluateModel() override {
        cout << "[Neural Network] Evaluating accuracy and loss on validation set..." << endl;
        // pseudo-code : calculate accuracy, loss...
    }
    void saveModel() override {
        cout << "[Neural Network] Serializing network weights to .hs file\n" << endl;
    }
};

// --------------------------------------------
// 3. Concrete subclass: Decision Tree 
// --------------------------------------------

class DecisionTreeTrainer : public ModelTrainer {
    protected:
    // Use the default preprocessData() (train/test split + normalize)

    void trainModel() override {
        cout << "[Decision Tree] Building decision tree with max depth of 10..." << endl;
        // pseudo-code : recursive tree building...
    }
    void evaluateModel() override {
        cout << "[Decision Tree] Computing classification report (precision/recall)..." << endl;
        // pseudo-code : calculate Gini impurity, accuracy...
    }

    // use the default save implementation
};

// ---------------------------------------
// 4. User 
// ---------------------------------------

int main() {
    cout<<"--- Neural network Training ---\n";
    ModelTrainer* nnTrainer = new NeuralNetworkTrainer();
    nnTrainer->trainPipeline("data/image");

    cout<<"--- Decision Tree Training ---\n";
    ModelTrainer* dtTrainer = new DecisionTreeTrainer();
    dtTrainer->trainPipeline("data/iris.csv");

    return 0;
}