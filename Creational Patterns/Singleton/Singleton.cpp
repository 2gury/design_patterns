#include <iostream>

class Singleton {
public:
    static Singleton* Instance() {
        if (unique_instance == 0) {
            return new Singleton;
        }
        return unique_instance;
    }
private:
    Singleton() {};
    Singelton(Singleton*);
    Singleton(const Singleton&);
    Singleton& operator=(Singleton&);
    
    static Singleton* unique_instance;
};

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
