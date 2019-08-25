#include <iostream>

class Memento {
private:
    friend class Originator;
    
    Memento(): state(0) {};
    Memento(int state_for_initialize): state(state_for_initialize) {};
    
    void SetState(int state_for_set) {
        state = state_for_set;
    }
    int GetState() {
        return state;
    }
    
    int state;
};

class Originator {
public:
    Originator(): state(0) {};
    Originator(int state_for_initialize):
    state(state_for_initialize) {};
    Originator(Memento* memento_for_initialize):
    state(memento_for_initialize->GetState()) {};
    
    void SetMemento(Memento* memento_for_set) {
        state = memento_for_set->GetState();
    }
    Memento* CreateMemento() {
        return new Memento(state);
    }
private:
    int state;
};

class Caretaker {
public:
    Caretaker(Memento* memento_for_save):
    saved_memento(memento_for_save) {};
    
    void SetMemento(Memento* memento_for_set) {
        saved_memento = memento_for_set;
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
