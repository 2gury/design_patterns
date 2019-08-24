//
//  main.cpp
//  Template Method
//
//  Created by Egor Timonin on 23/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class AbstractClass {
public:
    virtual ~AbstractClass() {};
    void ConcreteOperation1() {
        std::cout << "It's a Template Method version ";
    }
    void ConcreteOperation2() {
        std::cout << "I wish you to be ";
    }
    void ConcreteOperation3() {
        std::cout << "Have a good day!" << std::endl;
    }
    void ConcreteOperation4() {
        std::cout << std::endl;
    }
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    
    void TemplateMethod() {
        ConcreteOperation1();
        PrimitiveOperation1();
        ConcreteOperation2();
        PrimitiveOperation2();
        ConcreteOperation3();
        ConcreteOperation4();
    }
};

class ConcreteClass1 : public AbstractClass {
public:
    void PrimitiveOperation1() {
        std::cout << "of ConcreteClass1" << std::endl;
    }
    void PrimitiveOperation2() {
        std::cout << "free" << std::endl;
    }
};

class ConcreteClass2 : public AbstractClass {
public:
    void PrimitiveOperation1() {
        std::cout << "of ConcreteClass2" << std::endl;
    }
    void PrimitiveOperation2() {
        std::cout << "healthy" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    ConcreteClass1 class1;
    ConcreteClass2 class2;
    class1.TemplateMethod();
    class2.TemplateMethod();
    return 0;
}
