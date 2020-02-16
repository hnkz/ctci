#include <iostream>
#include "Node.h"
#include <random>

int main() {
    std::random_device rnd;
    Node h1 = Node(3);
    h1.appendToTail(1);
    h1.appendToTail(5);
    h1.appendToTail(5);
    h1.appendToTail(1);
    h1.appendToTail(3);

    h1.showNode();
    if(h1.isBatch()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    
    h1 = Node(3);
    h1.appendToTail(1);
    h1.appendToTail(5);
    h1.appendToTail(5);
    h1.appendToTail(1);

    h1.showNode();
    if(h1.isBatch()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    h1 = Node(3);
    h1.appendToTail(1);
    h1.appendToTail(5);
    h1.appendToTail(1);
    h1.appendToTail(3);

    h1.showNode();
    if(h1.isBatch()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}
