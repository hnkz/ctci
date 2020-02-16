#include <memory>

class Node {
    int data;
    Node *next;

public:
    Node(int d): data{d}, next{nullptr}{};
    ~Node();
    void appendToTail(int d);
    void deleteDeplication();
    void deleteDeplication2();
    Node* ithFromTail(int target, int &i);
    bool deleteNode();
    void devideAt(int d);
    void showNode();
    void clean();
};
