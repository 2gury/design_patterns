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
