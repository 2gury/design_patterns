#include <iostream>
#include <map>

class Flyweight {
public:
    virtual ~Flyweight() {};
    virtual void Operation(int extrinsic_state) = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(int intrinsic_state): state(intrinsic_state) {};
    void Operation(int extrinsic_state) {};
private:
    int state;
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight(int all_state): state(all_state) {};
    void Operation(int extrinsic_state) {};
private:
    int state;
};

class FlyweightFactory {
public:
    ~FlyweightFactory() {
        for (auto it = flies.begin(); it != flies.end(); ++it) {
            delete it->second;
        }
        flies.clear();
    }
    Flyweight* GetFlyweight(int key) {
        if (flies.find(key) != flies.end()) {
            return flies[key];
        } else {
            Flyweight* fly = new ConcreteFlyweight(key);
            flies.insert(std::pair<int, Flyweight*>(key, fly));
            return fly;
        }
    }
private:
    std::map<int, Flyweight*> flies;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
