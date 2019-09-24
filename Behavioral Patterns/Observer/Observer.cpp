//Example of `observer' design pattern in C++

#include <iostream>
#include <vector>

class Observer;
class ConcreteSubject;

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(ConcreteSubject* subject_to_follow):
    followed_subject(subject_to_follow) {
        followed_subject->Attach(this);
    }
    void Update() {
        state = followed_subject->GetState();
    }
private:
    ConcreteSubject* followed_subject;
    int state;
};

class Subject {
public:
    virtual ~Subject() {};
    virtual void Attach(Observer* follower_to_attach) {
        followers.push_back(follower_to_attach);
    }
    virtual void Detach(int index) {
        followers.erase(followers.begin() + index);
    }
    virtual void Notify() {
        for (int i = 0; i < followers.size(); ++i) {
            followers[i]->Update();
        }
    }
private:
    std::vector<Observer*> followers;
};

class ConcreteSubject : public Subject {
public:
    void SetState(int state_to_set) {
        state = state_to_set;
    }
    int GetState() {
        return state;
    }
private:
    int state;
};

class Observer {
public:
    virtual ~Observer() {};
    virtual void Update() = 0;
};

class Observer;

class Subject {
public:
    virtual ~Subject() {};
    virtual void attach(Observer* follower) {
        followers.push_back(follower);
    }
    virtual void detach(int index) {
        followers.erase(followers.begin() + index);
    }
    virtual void Notify() {
        for (int i = 0; i < followers.size(); ++i) {
            followers[i]->Update();
        }
    }
private:
    std::vector<Observer*> followers;
};

class ConcreteSubject : public Subject {
public:
    int GetState() {
        return SubjectState;
    }
    void SetState(int NewSubjectState) {
        SubjectState = NewSubjectState;
    }
private:
    int SubjectState;
};

class Observer {
public:
    virtual ~Observer() {};
    virtual void Update() = 0;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(ConcreteSubject* subject_to_follow) {
        FollowedSubject = subject_to_follow;
        FollowedSubject->attach(this);
    }
    void Update() {
        ObserverState = FollowedSubject->GetState();
    }
private:
    ConcreteSubject* FollowedSubject;
    int ObserverState;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
