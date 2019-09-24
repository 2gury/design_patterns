//Example of `iterator' design pattern in C++

#include <iostream>

template <typename type>
class ListNode {
public:
    ListNode(): next(nullptr), data(0) {};
    ListNode(type data_for_initialize): data(data_for_initialize) {};
    void SetNext(std::shared_ptr<ListNode<type>> ptr_for_set) {
        next = ptr_for_set;
    }
    std::shared_ptr<ListNode<type>> GetNext() {
        return next;
    }
    void SetData(type data_for_set) {
        data = data_for_set;
    }
    type GetData() {
        return data;
    }
private:
    std::shared_ptr<ListNode<type>> next;
    type data;
};

template <typename type>
class Iterator {
public:
    virtual ~Iterator() {};
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual type GetCurrent() = 0;
    virtual bool IsDone() = 0;
};

template <typename type>
class ListIterator : public Iterator<type> {
public:
    ListIterator(): current(nullptr) {};
    ListIterator(std::weak_ptr<ListNode<type>> ptr_for_initialize):
    current(ptr_for_initialize) {};
    void Next() {
        current = current.lock()->GetNext;
    }
    type GetCurrent() {
        return current.lock()->GetData();
    }
    bool IsDone() {
        return current.lock()->GetNext() == nullptr;
    }
private:
    std::weak_ptr<ListNode<type>> current;
};

template <typename type>
class AbstractList {
public:
    virtual ~AbstractList() {};
    virtual ListIterator<type> CreateIterator() = 0;
};

template <typename type>
class List : public AbstractList<type> {
public:
    List(): head(nullptr), size(0) {};
    int GetSize() {
        return size;
    }
    ListIterator<type> CreateIterator() {
        return ListIterator<type>(head);
    }
    void Append(type data_for_append) {
        ListIterator<type> it = CreateIterator();
        for(; !it.IsDone();) {
            it.Next();
        }
        std::shared_ptr<ListNode<type>> node;
        node->SetData(data_for_append);
        it.lock()->SetNext(node);
        ++size;
    }
private:
    std::shared_ptr<ListNode<type>> head;
    int size;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
