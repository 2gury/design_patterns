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
    virtual ~Decorator() {};
    Decorator(Component* other_component): component(other_component) {};
    void  Operation() {
        this->component->Operation();
    }
private:
    Component* component;
};

class ConcreteDecoratorA :  public Decorator  {
public:
    ConcreteDecoratorA(Component*  other_component): Decorator(other_component) {};
    void Operation () {
        Decorator::Operation();
        //...code of decorator implementation
    }
};

class ConcreteDecoratorB : public Decorator{
public:
    ConcreteDecoratorB(Component* other_component): Decorator(other_component) {
        Decorator::Operation();
        //...code of decorator implementation
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
