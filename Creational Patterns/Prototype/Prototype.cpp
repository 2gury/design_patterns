//Example of `prototype' design pattern in C++

#include <iostream>

class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual ~Prototype() {};
};

class ConcretePrototype1 : public Prototype {
    int data;
public:
    ConcretePrototype1(int other_data): data(other_data) {}
    ConcretePrototype1(const ConcretePrototype1 &prototype): data(prototype.data) {}
    Prototype* clone() {return new ConcretePrototype1(* this);}
};

class ConcretePrototype2 : public Prototype {
    int data;
public:
    ConcretePrototype2(int other_data): data(other_data) {}
    ConcretePrototype2(const ConcretePrototype2 &prototype): data(prototype.data) {}
    Prototype* clone() {return new ConcretePrototype2(* this);}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
