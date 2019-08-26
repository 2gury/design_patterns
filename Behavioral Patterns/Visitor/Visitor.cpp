#include <iostream>

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
    virtual ~Visitor() {};
    virtual void Visit(ConcreteElementA *element) = 0;
    virtual void Visit(ConcreteElementB *element) = 0;
};

class Element {
public:
    virtual ~Element() {};
    virtual void Accept(Visitor *concrete_visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void Accept(Visitor *concrete_visitor) {
        concrete_visitor->Visit(this);
    }
    void OperationA1() {};
    void OperationA2() {};
};

class ConcreteElementB : public Element {
public:
    void Accept(Visitor *concrete_visitor) {
        concrete_visitor->Visit(this);
    }
    void OperationB1() {};
    void OperationB2() {};
};


class ConcreteVisitor1 : public Visitor {
public:
    void Visit(ConcreteElementA *element) {
        element->OperationA1();
    };
    void Visit(ConcreteElementB *element) {
        element->OperationB1();
    };
};

class ConcreteVisitor2 : public Visitor {
public:
    void Visit(ConcreteElementA *element) {
        element->OperationA2();
    }
    void Visit(ConcreteElementB *element) {
        element->OperationB2();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
