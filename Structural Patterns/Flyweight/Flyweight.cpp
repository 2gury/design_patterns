//Example of `flyweight' design pattern in C++

#include <iostream>
#include <map>

class Flyweight {
public:
    virtual ~Flyweight() {};
    virtual void Operation(int extrinsic_state) = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    ConcreteFlyweight(int intrinsic_state_for_initialize):
    intrinsic_state(intrinsic_state_for_initialize) {};
    void Operation(int extrinsic_state) {
        //...implementation
    };
private:
    int intrinsic_state;
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
    UnsharedConcreteFlyweight(int all_state_for_initialize): 
    all_state(all_state_for_initialize) {};
    void Operation(int extrinsic_state) {
        //...implementation
    };
private:
    int all_state;
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
            //not only ConcreteFlyweight you can use for crete
            //you can analyze 'key' and choose needed Flyweight
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
