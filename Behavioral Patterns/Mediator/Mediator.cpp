#include <iostream>

class Colleague;

class Mediator {
public:
    virtual ~Mediator() {};
    virtual void Send(std::string message, Colleague* colleague) = 0;
};

class Colleague {
public:
    virtual ~Colleague() {};
    Colleague(Mediator* other_mediator): mediator(other_mediator) {};
protected:
    Mediator* mediator;
};

class ConcreteColleague1 : public Colleague {
public:
    ConcreteColleague1(Mediator* other_mediator): Colleague(other_mediator) {};
    void Send(std::string message) {
        mediator->Send(message, this);
    }
    void Notify(std::string message) {
        std::cout << "ConcreteColleague1 got message " << message << std::endl;
    }
};
class ConcreteColleague2 : public Colleague {
public:
    ConcreteColleague2(Mediator* other_mediator): Colleague(other_mediator) {};
    void Send(std::string message) {
        mediator->Send(message, this);
    }
    void Notify(std::string message) {
        std::cout << "ConcreteColleague2 got message " << message << std::endl;
    }
};

class ConcreteMediator : public Mediator {
public:
    void SetColleague1(ConcreteColleague1* other_colleague1) {
        colleague1 = other_colleague1;
    }
    void SetColleague2(ConcreteColleague2* other_colleague2) {
        colleague2 = other_colleague2;
    }
    void Send(std::string message, Colleague* colleague) {
        if (colleague == colleague1) {
            colleague1->Notify(message);
        } else if (colleague == colleague2) {
            colleague2->Notify(message);
        }
    }
protected:
    ConcreteColleague1* colleague1;
    ConcreteColleague2* colleague2;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
