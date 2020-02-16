#include <iostream>
#include "Node.h"
#include <random>

int main() {
    std::random_device rnd;
    Node h1 = Node(3);
    h1.appendToTail(1);
    h1.appendToTail(5);

    Node h2 = Node(9);
    h2.appendToTail(3);
    h2.appendToTail(6);

    h1.showNode();
    h2.showNode();
    Node *result = addNode(&h1, &h2);
    result->showNode();

    delete result;
}
