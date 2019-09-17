//Example of `proxy' design pattern in C++

#include <iostream>

class Subject {
public:
    virtual ~Subject() {};
    virtual void Request() = 0;
};

class RealSubject : public Subject {
public:
    void Request() {
        //...implementation
    };
};

class Proxy : public Subject {
public:
    Proxy(): real_subject(new RealSubject()) {};
    ~Proxy() {
        delete real_subject;
    };
    void Request() {
        this->real_subject->Request();
    }
private:
    Subject* real_subject;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
