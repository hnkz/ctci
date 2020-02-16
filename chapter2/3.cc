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

    int i = 0;
    Node *node = head.ithFromTail(5, i);

    if(node != nullptr) {
        node->deleteNode();
        head.showNode();
    }

    i = 0;
    node = head.ithFromTail(9, i);

    if(node != nullptr) {
        node->deleteNode();
        head.showNode();
    }
}
