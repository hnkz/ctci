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

Node* Node::ithFromTail(int target, int &i) {
    Node *n = nullptr;
    if(next == nullptr) {
        i = 0;
    } else {
        n = next->ithFromTail(target, i);
        i += 1;
    }

    if(n != nullptr) {
        return n;
    } else if(target == i) {
        return this;
    } else {
        return nullptr;
    }
}

bool Node::deleteNode() {
    if(next == nullptr) {
        return false;
    } else {
        data = next->data;
        next = next->next;
        return true;
    }
}

void Node::devideAt(int d) {
    Node *p = this;

    while(p->data < d) {
        p = p->next;
    }

    Node *node = p->next;
    while(node != nullptr) {
        if(node->data < d) {
            int tmp = p->data;
            p->data = node->data;
            node->data = tmp;
            p = p->next;
        }
        node = node->next;
    }
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


Node* addNode(Node *n1, Node *n2) {
    Node *result = nullptr;

    Node *node1 = n1;
    Node *node2 = n2;
    int c = 0;
    while(node1 != nullptr || node2 != nullptr) {
        int sc = 0;
        if(node1 != nullptr) {
            sc += node1->data;
            node1 = node1->next;
        }
        if(node2 != nullptr) {
            sc += node2->data;
            node2 = node2->next;
        }

        int s = sc % 10 + c;
        c = sc / 10;

        if(result == nullptr) {
            result = new Node(s);
        } else {
            result->appendToTail(s);
        }
    }
    if(c != 0) {
        result->appendToTail(c);
    }

    return result;
}
