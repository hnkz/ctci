#include <iostream>
#include "Node.h"
#include <random>

int main() {
    std::random_device rnd;
    Node head = Node(0);

    for(int i = 0; i < 20; i++) {
        head.appendToTail(rnd() % 10);
    }

    head.showNode();
    head.deleteDeplication();
    head.showNode();

    // no extra memory
    Node head2 = Node(0);

    for(int i = 0; i < 20; i++) {
        head2.appendToTail(rnd() % 10);
    }

    head2.showNode();
    head2.deleteDeplication2();
    head2.showNode();

}
