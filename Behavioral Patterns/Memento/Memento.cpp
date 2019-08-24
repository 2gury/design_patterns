#include <iostream>

class Memento {
private:
    friend class Originator;
    Memento(int other_state): state(other_state) {};
    int GetState() {
        return state;
    }
    void SetState(int other_state) {
        state = other_state;
    }
    int state;
};

class Originator {
public:
    Originator(int other_state): state(other_state) {};
    Memento* CreateMemento() {
        return new Memento(this->state);
    }
    void SetMemento(Memento* other_memento) {
        state = other_memento->state;
    }
private:
    int state;
};

class Caretaker {
public:
    Caretaker(Memento* memento_to_save): saved_memento(memento_to_save) {};
    void SetMemento(Memento* memento_to_save) {
        saved_memento = memento_to_save;
    }
    Memento* GetMemento() {
        return saved_memento;
    }
private:
    Memento* saved_memento;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
