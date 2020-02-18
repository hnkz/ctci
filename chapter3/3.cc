#include <iostream>
#include <optional>

class Optional {
    int val;
    bool isset;
public:
    Optional(int value): val{value}, isset{true}{};
    Optional(): val{0}, isset{false}{};
    void set(int value) {
        val = value;
    }
    int get() {
        return val;
    }
    bool has_value() {
        return isset;
    }
};
class SetOfStacks {
    int arr[5];
    int sp;
    SetOfStacks *next;
public:
    SetOfStacks() {
        for(int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
        sp = 0;
        next = nullptr;
    }

    ~SetOfStacks() {
        if(next != nullptr) {
            delete next;
        }
    }

    void push(int value) {
        if(sp < 5) {
            arr[sp] = value;
            sp += 1;
        } else {
            if(next == nullptr) {
                next = new SetOfStacks();
            }
            next->push(value);
        }
        
    }

    Optional pop() {
        int result;
        if(sp > 0) {
            if(next != nullptr) {
                Optional res = next->pop();
                if(!res.has_value()) {
                    delete next;
                    next = nullptr;
                    sp -= 1;
                    result = arr[sp];
                } else {
                    result = res.get();
                }
            } else {
                sp -= 1;
                result = arr[sp];
            }
        } else {
            return Optional();
        }
        return Optional(result);
    }
};

int main() {
    SetOfStacks s = SetOfStacks();
    for(int i = 0; i < 20; i++) {
        s.push(i);
    }

    for(int i = 0; i < 21; i++) {
        Optional a = s.pop();
        if(a.has_value())
            std::cout << a.get() << " ";
        else
            std::cout << "nonvalue..." << std::endl;
    }
    std::cout << std::endl;
}
