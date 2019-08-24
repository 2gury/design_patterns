//
//  main.cpp
//  Adapter
//
//  Created by Egor Timonin on 14/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class AbstractTarget {
public:
    virtual ~AbstractTarget() {};
    virtual void Request() = 0;
};

class ConcreteTarget : public AbstractTarget {
public:
    void Request() {
        //...реализация
    }
};

class AbstractAdaptee {
public:
    virtual ~AbstractAdaptee() {};
    virtual void SpecificRequest() = 0;
};

class ConcreteAdaptee : public AbstractAdaptee {
public:
    void SpecificRequest() {
        //...адаптируемая реализация
    }
};

class Adapter: public AbstractTarget, private AbstractAdaptee {
public:
    void Request() {
        SpecificRequest();
    }
};

//class AbstractTarget {
//public:
//    virtual ~AbstractTarget() {};
//    virtual void Request() = 0;
//};
//
//class ConcreteTarget : public AbstractTarget {
//public:
//    void Request() {
//        //...реализация
//    }
//};
//
//class AbstractAdaptee {
//public:
//    virtual ~AbstractAdaptee() {};
//    virtual void SpecificRequest() = 0;
//};
//
//class ConcreteAdaptee : public AbstractAdaptee {
//public:
//    void SpecificRequest() {
//        //...адаптируемая реализация
//    }
//};
//
//class Adapter : public AbstractTarget {
//public:
//    Adapter(AbstractAdaptee* other_adaptee): adaptee(other_adaptee) {};
//    void Request() {
//        this->adaptee->SpecificRequest();
//    }
//protected:
//    AbstractAdaptee* adaptee;
//};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
