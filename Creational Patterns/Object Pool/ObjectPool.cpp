#include <iostream>
#include <vector>

class Object {};

class ObjectPool {
public:
    Object* CreateObject() {
        for(int i = 0; i < object_pool.size(); ++i) {
            if (!object_pool[i].second) {
                object_pool[i].second = true;
                return object_pool[i].first;
            }
        }
        std::pair<Object*, bool> object;
        object.first = new Object;
        object.second = true;
        
        object_pool.push_back(object);
        return object.first;
    }
    void DeleteObject(Object* concrete_object) {
        for(int i = 0; i < object_pool.size(); ++i) {
            if (object_pool[i].first == concrete_object) {
                object_pool[i].second = false;
                break;
            }
        }
    }
    ~ObjectPool() {
        for(int i = 0; i < object_pool.size(); ++i) {
            delete object_pool[i].first;
        }
    }
private:
    std::vector<std::pair<Object*, bool>> object_pool;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
