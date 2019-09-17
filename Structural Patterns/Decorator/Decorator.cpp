//Example of `decorator' design pattern in C++

#include <iostream>

class Component {
public:
    virtual ~Component() {};
    virtual void Operation() = 0;
};

class ConcreteComponent : public Component {
public:
    void Operation() {
        //...implementation
    };
};

class Decorator : public Component {
public:
    Decorator(Component* component_for_initialize): 
    component(component_for_initialize) {};
    virtual ~Decorator() {};
    void  Operation() {
        this->concrete_component->Operation();
    }
private:
    Component* concrete_component;
};

class ConcreteDecoratorA :  public Decorator  {
public:
    ConcreteDecoratorA(Component*  component_for_initialize): 
    Decorator(component_for_initialize) {};
    void Operation () {
        Decorator::Operation();
        //...code of decorator implementation
    }
};

class ConcreteDecoratorB : public Decorator{
public:
    ConcreteDecoratorB(Component* component_for_initialize): 
    Decorator(component_for_initialize) {
        Decorator::Operation();
        //...code of decorator implementation
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
