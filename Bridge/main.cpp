//
//  main.cpp
//  Bridge
//
//  Created by Egor Timonin on 14/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class Implementor {
public:
    virtual ~Implementor() {};
    virtual void OperationImp() = 0;
};

class ConcreteImplementor1 : public Implementor {
public:
    void OperationImp() {
        //...first implementation
    }
};

class ConcreteImplementor2 {
public:
    void OperationImp() {
        //...second implementation
    }
};

class Abstraction {
public:
    virtual ~Abstraction() {};
    virtual void Operation() = 0;
protected:
    Implementor* imp;
};

class RefinedAbstraction : public Abstraction {
public:
    void Operation() {
        //...code
        imp->OperationImp();
        //...code
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
