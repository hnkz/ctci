#include <iostream>
#include "Node.h"
#include <unordered_map>

Node::~Node() {
    clean();
}

void Node::appendToTail(int d) {
    Node *newNode = new Node(d);
    Node *n = next;
    if(n == nullptr) {
        next = newNode;
    } else {
        while(n->next != nullptr) {
            n = n->next;
        }
        n->next = newNode;
    }
}

void Node::deleteDeplication() {
    std::unordered_map<int, int> um;
    Node *n = next;
    Node *b = this;
    um[data] = data;
    while(n != nullptr) {
        if(um.find(n->data) == um.end()) {
            um[n->data] = n->data;
            b = n;
        } else {
            b->next = n->next;
        }
        n = n->next;
    }
}

void Node::deleteDeplication2() {
    Node *i = this;
    while(i != nullptr) {
        Node *bef = i;
        Node *j = i->next;
        while(j != nullptr) {
            if(i->data == j->data) {
                bef->next = j->next;
            } else {
                bef = j;
            }
            j = j->next;
        }
        i = i->next;
    }
}

Node* Node::deleteNode(int d) {
    return nullptr;
}

void Node::showNode() {
    std::cout << data ;
    if(next == nullptr) {
        std::cout << std::endl;
    } else {
        std::cout << " -> ";
        next->showNode();
    }
}

void Node::clean() {
    if(next != nullptr)
        delete next;
}
