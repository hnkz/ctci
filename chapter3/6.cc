#include <iostream>
enum Type {
    Dog,
    Cat,
    None,
};
class Node {
public:
    Type type;
    int num;
    Node *next;
    Node(Type t, int n) {
        type = t;
        num = n;
        next = nullptr;
    }
    ~Node() {
        if(next != nullptr) {
            delete next;
        }
    }
    void appendToTail(Node *newNode) {
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

    bool deleteHead() {
        if(next == nullptr)
            return false;
        type = next->type;
        num = next->num;
        next = next->next;
        return true;
    }

    void showNode() {
        if(type == Dog) {
            std::cout << "Dog";
        } else {
            std::cout << " Cat";
        }
        std::cout << "(" << num << ")";
        if(next == nullptr) {
            std::cout << std::endl;
        } else {
            std::cout << " -> ";
            next->showNode();
        }
    }
};
class DogAndCatQueue {
    Node *headAny;
    Node *headDog;
    Node *headCat;
public:
    DogCatNode(Type type) {
        headAny = nullptr;
        headDog = nullptr;
        headCat = nullptr;
    }

    ~DogCatNode() {
        if(headAny != nullptr) {
            delete headAny;
        }
        if(headDog != nullptr) {
            delete headDog;
        }
        if(headCat != nullptr) {
            delete headCat;
        }
    }

    void enqueue(Type t, int n) {
        if(t == None) {
            return;
        }
        Node *newNode = new Node(t, n);
        if(headAny == nullptr) {
            headAny = newNode;
        } else {
            headAny->appendToTail(newNode);
        }
        if(type == Dog) {
            if(headDog == nullptr) {
                headDog = newNode;
            } else {
                headDog->appendToTail(newNode);
            }
        } else if(type == Cat) {
            if(headCat == nullptr) {
                headCat = newNode;
            } else {
                headCat->appendToTail(newNode);
            }
        }
    }

    Type dequeueAny() {
        Type t;
        if(headAny == nullptr) {
            return None;
        } else {
            t = headAny->type;
            if(!headAny->removeHead()) {
                delete headAny;
                headAny = nullptr;
            }
            if(t == Dog) {
                if(!headDog->removeHead()) {
                    delete headDog;
                    headDog = nullptr;
                }
            } else if(t == Cat) {
                if(!headCat->removeHead()) {
                    delete headCat;
                    headCat = nullptr;
                }
            }
        }
        return t;
    }

    Type dequeueDog() {

    }

    Type dequeueCat() {

    }
}
