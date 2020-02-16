#include <iostream>
#include "Node.h"
#include <random>

int main() {
    std::random_device rnd;
    Node head = Node(0);

    for(int i = 0; i < 10; i++) {
        head.appendToTail(rnd() % 10);
    }

    head.showNode();
    head.devideAt(5);
    head.showNode();
}
