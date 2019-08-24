//
//  main.cpp
//  Singleton
//
//  Created by Egor Timonin on 06/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

class Singleton {
private:
    Singleton() {};
    Singleton(const Singleton&);
    Singleton& operator=(Singleton&);
    static Singleton* instance;
public:
    static Singleton* Instance() {
        if (instance == 0) {
            instance = new Singleton;
        }
        return instance;
    }
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
