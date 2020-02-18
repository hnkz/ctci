#include <iostream>
#include <utility>
#include <random>

template <typename T>
class Stack {
    std::pair<T, T> arr[1024];
    int bp;
    int sp;
public:
    Stack(T default_value) {
        bp = 0;
        sp = 0;
        for(int i = 0; i < 1024; i++) {
            arr[i] = std::make_pair(default_value, default_value);
        }
    }

    bool push(T value) {
        if(sp < 1024) {
            T min = sp > 0 ? arr[sp-1].second : value;
            min = min > value ? value : min;
            arr[sp] = std::make_pair(value, min); 
            sp += 1;
            return true;
        } else {
            return false;
        }
    }

    T pop() {
        if(sp > 0) {
            sp -= 1;
            std::pair<T, T> p = arr[sp];
            return p.first;
        } else {
            throw "Stack is empty!";
        }
    }

    T min() {
        if(sp > 0) {
            return arr[sp-1].second;
        } else {
            throw "Stack is empty!";
        }
    }

};

int main() {
    std::random_device rnd;
    Stack<int> s(0);
    for(int i = 0; i < 10; i++) {
        int value = rnd() % 100;
        std::cout << value << " "; 
        s.push(value);
    }
    std::cout << std::endl;

    for(int i = 0; i < 10; i++) {
        int min = s.min();
        int a = s.pop();
        std::cout << a << " " << min << std::endl;
    }
}
