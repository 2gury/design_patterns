//
//  main.cpp
//  State
//
//  Created by Egor Timonin on 23/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class State {
public:
    virtual ~State() {};
    virtual void Handle() = 0;
};

class ConcreteStateA : public State {
public:
    void Handle() {
        //implementation for Request of the state A
    }
};

class ConcreteStateB : public State {
public:
    void Handle() {
        //implementation for Request of the state B
    }
};

class Context {
public:
    Context(State* state): current_state(state) {};
    void SetState(State* new_current_state) {
        current_state = new_current_state;
    }
    void Request() {
        current_state->Handle();
    }
private:
    State* current_state;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
