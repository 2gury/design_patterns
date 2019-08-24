//
//  main.cpp
//  Iterator
//
//  Created by Egor Timonin on 20/08/2019.
//  Copyright © 2019 Egor Timonin. All rights reserved.
//

#include <iostream>

template <typename Type>
class Iterator;

template <typename Type>
class ListIterator;

template <typename Type>
class ListNode;

template <typename Type>
class AbstractList {
public:
    virtual ~AbstractList() {};
    virtual Iterator<Type>* CreateIterator() const = 0;
    virtual int Count() = 0;
    virtual void Append(Type item) = 0;
};

template <typename Type>
class List : public AbstractList<Type> {
public:
    int Count() {
        return size;
    }
    void Append(Type data){
        Iterator<Type> it = this->CreateIterator();
        for (it; !it.IsDone(); ) {
            it.Next();
        }
        std::shared_ptr<ListNode<Type>> node;
        node->SetData(data);
        it.lock->SetNextPtr(node);
    }
    Iterator<Type> CreateIterator() {
        return ListIterator<Type>(this->head);
    }
private:
    int size;
    std::shared_ptr<ListNode<Type>> head;
};

template <typename Type>
class Iterator {
public:
    virtual ~Iterator() {};
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type* CurrentItem() const = 0;
};

template <typename Type>
class ListIterator : public Iterator<Type> {
public:
    void Next() {
        this->current = this->current.lock()->GetNextPtr();
    }
    bool IsDone() {
        if (this->current.lock() == nullptr) {
            return 1;
        } else {
            return 0;
        }
    }
    Type* CurrentItem() {
        this->current.lock()->GetData();
    }
private:
    std::weak_ptr<ListNode<Type>> current;
};

template <typename Type>
class ListNode {
public:
    void SetData(Type other_data) {
        data = other_data;
    }
    Type GetData() {
        return data;
    }
    void SetNextPtr(std::shared_ptr<ListNode<Type>> other_ptr) {
        next = other_ptr;
    }
    std::shared_ptr<ListNode<Type>> GetNextPtr() {
        return next;
    }
private:
    Type data;
    std::shared_ptr<ListNode<Type>> next;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
