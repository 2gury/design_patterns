//
//  main.cpp
//  Chain of Responsibility
//
//  Created by Egor Timonin on 20/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class Handler {
public:
    Handler(): next(nullptr) {};
    virtual ~Handler() {};
    virtual void HandleRequest(int data_request) {
        if (next) {
            next->HandleRequest(data_request);
        }
    }
    void SetNextHandler(Handler* next_handler) {
        if (next) {
            next->SetNextHandler(next_handler);
        } else {
            next = next_handler;
        }
    }
private:
    Handler* next;
};

class ConcreteHandler1 : public Handler {
public:
    void HandleRequest(int data_request) {
        //if can handle it do it
            //implementation of HadleRequest
        //else
        std::cout << "ConcreteHandler1" << std::endl;
        Handler::HandleRequest(data_request);
    }
};

class ConcreteHandler2 : public Handler {
public:
    void HandleRequest(int data_request) {
        //if can handle it do it
            //implementation of HadleRequest
        //else
        std::cout << "ConcreteHandler2" << std::endl;
        Handler::HandleRequest(data_request);
    }
};

int main(int argc, const char * argv[]) {
    Handler* handler = new Handler;
    int data = 0;
    handler->SetNextHandler(new ConcreteHandler1());
    handler->SetNextHandler(new ConcreteHandler2());
    handler->HandleRequest(data);
    return 0;
}
