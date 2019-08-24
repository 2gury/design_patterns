//
//  main.cpp
//  Composite
//
//  Created by Egor Timonin on 15/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

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














class Component {
public:
    virtual ~Component() {};
    virtual void Operation() = 0;
    virtual void Add(Component*) = 0;
    virtual void Remove(Component*) = 0;
    virtual void GetChild(int) = 0;
};

class Leaf : public Component {
public:
    void Operation() {
        //...code
    }
};

class Composite : public Component {
public:
    void Operation() {
        //...for each item do Operation()
    }
    void Add(Component* item) {
        this->items.push_back(item);
    }
private:
    std::vector<Component*> items;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
