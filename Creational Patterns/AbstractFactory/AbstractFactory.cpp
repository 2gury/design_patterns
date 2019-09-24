//Example of `abstract factory' design pattern in C++

#include <iostream>

class AbstractProductA {
public:
    virtual void paint() = 0;
};

class AbstractProductB {
public:
    virtual void paint() = 0;
};

class ProductA1 : public AbstractProductA {
public:
    void paint() {
        std::cout << "ProductA1" << std::endl;
    }
};

class ProductA2 : public AbstractProductA {
public:
    void paint() {
        std::cout << "ProductA2" << std::endl;
    }
};

class ProductB1 : public AbstractProductB {
public:
    void paint() {
        std::cout << "ProductB1" << std::endl;
    }
};

class ProductB2 : public AbstractProductB {
public:
    void paint() {
        std::cout << "ProductB2" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() {
        return new ProductA1;
    }
    AbstractProductB* CreateProductB() {
        return new ProductB1;
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* CreateProductA() {
        return new ProductA2;
    }
    AbstractProductB* CreateProductB() {
        return new ProductB2;
    }
};

int main()
{
    AbstractFactory *AF;
    AbstractProductB *APB;
    AbstractProductA *APA;

    AF = new ConcreteFactory2;
    APA = AF->CreateProductA();
    APB = AF->CreateProductB();
    
    APA->paint();
    APB->paint();
    return 0;
}
