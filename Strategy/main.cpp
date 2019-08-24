//
//  main.cpp
//  Strategy
//
//  Created by Egor Timonin on 23/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class Strategy {
public:
    virtual ~Strategy() {};
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void AlgorithmInterface() {
        //implementation of algorithm S
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
