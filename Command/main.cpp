//
//  main.cpp
//  Command
//
//  Created by Egor Timonin on 20/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class Command {
public:
    virtual ~Command() {};
    virtual void Execute() = 0;
};

class Receiver {
public:
    void Action1() {};
    void Action2() {};
};

class ConcreteCommand1 : public Command {
public:
    ConcreteCommand1(Receiver* other_purpose): purpose(other_purpose) {};
    void Execute() {
        purpose->Action1();
    }
private:
    Receiver* purpose;
};

class ConcreteCommand2 : public Command {
public:
    ConcreteCommand2(Receiver* other_purpose): purpose(other_purpose) {};
    void Execute() {
        purpose->Action2();
    }
private:
    Receiver* purpose;
};

class Invoker {
public:
    void SetCommand(Command* other_cmd) {
        this->cmd = other_cmd;
    }
    void ExecuteCommand() {
        this->cmd->Execute();
    }
private:
    Command* cmd;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
