#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Abstract Observer Interface : Subscribers must implement update()
class ISubscriber {
    public:
    virtual void update() = 0;
    virtual ~ISubscriber() {} // virtual destructor for interface
};

// Abstract Observable Interface : A youtube channel interface 
class IChannel {
    public:
    virtual void subscriber(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

// Concrete Subject: a Youtube channel that observers can subscribe to 
class Channel : public IChannel {
    private:
    vector<ISubscriber*> subscribers; // list of subscriber
    string name;     // channel name
    string latestVideo;  // latest uploaded video title44

    public:
    Channel(const string& name) {
        this->name = name;
    }

    // Add a subscriber (avoid duplicates)
    void subscriber(ISubscriber* subscriber) override {
        if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    // Remove a subscriber if present 
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if(it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    // Notify all subscribers of the latest video 
    void notifySubscribers() override {
        for(ISubscriber* sub : subscribers) {
            sub->update();
        }
    }

    void UpdloadVideo(const string& title) {
        latestVideo = title;
        cout<<"\n["<<name<<" uploaded \""<<title<<"\"\n]";
        notifySubscribers();
    }

    // Read Video Data 
    string getVideoData() {
        return "\nCheckout our new video: " + latestVideo + "\n";
    }
};

// Concrete Observer: represents a subscriber to the channel 
class Subscriber : public ISubscriber {
    private:
    string name;      // subscriber name
    Channel* channel;

    public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel= channel;
    }

    // Called by Channel: prints notification message 
    void update() override {
        cout<<"Hey "<<name<<","<<this->channel->getVideoData();
    }
};

int main() {
    // Create a channel and subscriber 
    Channel* channel = new Channel("CoderArmy");

    Subscriber* sub1 = new Subscriber("Varun", channel);
    Subscriber* sub2 = new Subscriber("Rohit", channel);

    // Varun and Rohit subscribe to CoderArmy
    channel->subscriber(sub1);  // insert into subscriber list
    channel->subscriber(sub2);  // insert into subscriber list

    // Upload a video: both Varun and Rohit are notified
    channel->UpdloadVideo("Observer Pattern Design");

    // Varun unsubscriber, Rohit remains subscribed
    channel->unsubscribe(sub1);

    // Upload another video: Only Rohit is notified
    channel->UpdloadVideo("Factory Pattern Design");

    return 0;
}