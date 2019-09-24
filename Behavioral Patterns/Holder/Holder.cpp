#include <iostream>

template <typename T>
class Holder;

template <typename T>
class Trule {
public:
    ~Trule() {delete ptr;};
    Trule(Holder<T>& h) {
        ptr = h.release();
    }
private:
    T* ptr;
    Trule(Trule<T>* t);
    Trule& operator= (Trule<T>&);
    friend class Holder<T>;
};

template <typename T>
class Holder {
public:
    Holder(): ptr(0) {};
    explicit Holder(T* p): ptr(p) {};
    ~Holder() {delete ptr;};
    T& operator *() const {return *ptr;};
    T& get() const {return *ptr;};
    T* operator->() const {return ptr;};
    void exchange(Holder<T>& h);
    Holder(Trule<T> const t) {
        ptr = t.ptr;
        const_cast<Trule<T>>(t).ptr = 0;
    }
    Holder<T>& operator= (Trule<T> const& t) {
        delete ptr;
        ptr = t.ptr;
        const_cast<Trule<T>>(t).ptr = 0;
        return *this;
    }
    T* release() {
        T* p = ptr;
        ptr = 0;
        return p;
    }
private:
    T* ptr;
    Holder(Holder<T> const&);
    Holder<T>& operator= (Holder<T> const&);
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
