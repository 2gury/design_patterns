//Example of `strategy' design pattern in C++

#include <iostream>

class Strategy {
public:
    virtual ~Strategy() {};
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void AlgorithmInterface() {
        //implementation of algorithm A
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void AlgorithmInterface() {
        //implementation of algorithm B
    }
};

class Context {
public:
    Context(Strategy* strategy_for_use): used_strategy(strategy_for_use) {};
    void SetStrategy(Strategy* strategy_for_use) {
        used_strategy = strategy_for_use;
    }
    void ContextInterface() {
        used_strategy->AlgorithmInterface();
    }
private:
    Strategy* used_strategy;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
