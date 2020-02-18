#include <iostream>

template <typename T, int ARRAY_LEN>
class ArrayStack {
    T arr[ARRAY_LEN];
    int bp1;
    int bp2;
    int bp3;
    int sp1;
    int sp2;
    int sp3;
public:
    ArrayStack(T default_value) {
        bp1 = 0;
        sp1 = 0;
        bp2 = ARRAY_LEN / 3;
        sp2 = ARRAY_LEN / 3;
        bp3 = ARRAY_LEN / 3 * 2;
        sp3 = ARRAY_LEN / 3 * 2;
        for(int i = 0; i < ARRAY_LEN; i++) {
            arr[i] = default_value;
        }
    }

    bool push1(T value) {
        if(sp1 < bp2) {
            arr[sp1] = value;
            sp1 += 1;
            return true;
        } else {
            return false;
        }
    }

    bool push2(T value) {
        if(sp2 < bp3) {
            arr[sp2] = value;
            sp2 += 1;
            return true;
        } else {
            return false;
        }
    }

    bool push3(T value) {
        if(sp3 < ARRAY_LEN) {
            arr[sp3] = value;
            sp3 += 1;
            return true;
        } else {
            return false;
        }
    }

    T pop1() {
        if(sp1 > bp1) {
            sp1 -= 1;
            T result = arr[sp1];
            return result;
        } else {
            throw "stack is empty!";
        }
    }

    T pop2() {
        if(sp2 > bp2) {
            sp2 -= 1;
            T result = arr[sp2];
            return result;
        } else {
            throw "stack is empty!";
        }
    }

    T pop3() {
        if(sp3 > bp3) {
            sp3 -= 1;
            T result = arr[sp3];
            return result;
        } else {
            throw "stack is empty!";
        }
    }

};

int main () {
    ArrayStack<int, 1024> s(0);
    for(int i = 0; i < 10; i++) {
        s.push1(i * 1);
        s.push2(i * 2);
        s.push3(i * 3);
    }
    for(int i = 0; i < 10; i++) {
        int a = s.pop1();
        int b = s.pop2();
        int c = s.pop3();
        std::cout << a << " " << b << " " << c << std::endl;
    }
}
