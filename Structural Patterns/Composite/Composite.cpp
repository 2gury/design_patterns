//Example of `composite' design pattern in C++

#include <iostream>
#include <vector>

class Component {
public:
    virtual ~Component() {};
    virtual void Operation() = 0;
    virtual void Add(Component*) = 0;
    virtual void Remove(Component*) = 0;
    virtual Component* GetChild(int) = 0;
};

class Leaf : public Component {
public:
    void Operation() {
        //...code of implementation
    }
};

class Composite : public Component {
public:
    ~Composite() {
        for (int i = 0; i < this->components.size(); ++i) {
            delete components[i];
        }
    }
    void Operation() {
        for (int i = 0; i< components.size(); ++i) {
            this->components[i]->Operation();
        }
    }
    void Add(Component* other_component) {
        this->components.push_back(other_component);
    }
    //... other implementation of functions
    
protected:
    std::vector<Component*> components;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
