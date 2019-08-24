#include <iostream>

class Subsystem1 {
public:
    void Operation() {};
};

class Subsystem2 {
public:
    void  Operation() {};
};

class Subsystem3 {
public:
    void Operation() {};
};

class Facade {
public:
    Facade() {
        subsys1 = new Subsystem1;
        subsys2 = new Subsystem2;
        subsys3 = new Subsystem3;
    }
    
    void Action1() {
        subsys1->Operation();
        subsys2->Operation();
    }
    
    void Action2() {
        subsys3->Operation();
    }
private:
    Subsystem1 *subsys1;
    Subsystem2 *subsys2;
    Subsystem3 *subsys3;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
