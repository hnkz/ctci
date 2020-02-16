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
    for(int i = 0; i < 10; i++) {
        int j = 0;
        Node *n = head.ithFromTail(i, j);
        n->showNode();
    }
}
