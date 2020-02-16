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
    Node* deleteNode(int d);
    void showNode();
    void clean();
};
