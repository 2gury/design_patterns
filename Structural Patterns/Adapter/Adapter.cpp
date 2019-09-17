//Example of `adapter' design pattern in C++

#include <iostream>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The class adapter implementation/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class AbstractTarget {
public:
    virtual ~AbstractTarget() {};
    virtual void Request() = 0;
};

class ConcreteTarget : public AbstractTarget {
public:
    void Request() {
        //...implementation
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
        //...adapted implementation
    }
};

class Adapter: public AbstractTarget, private AbstractAdaptee {
public:
    void Request() {
        SpecificRequest();
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//The object adapter implementation////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class AbstractTarget {
public:
   virtual ~AbstractTarget() {};
   virtual void Request() = 0;
};

class ConcreteTarget : public AbstractTarget {
public:
   void Request() {
       //...implementation
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
       //...adapted implementation
   }
};

class Adapter : public AbstractTarget {
public:
   Adapter(AbstractAdaptee* other_adaptee): adaptee(other_adaptee) {};
   void Request() {
       this->adaptee->SpecificRequest();
   }
protected:
   AbstractAdaptee* adaptee;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
