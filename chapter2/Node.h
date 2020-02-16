#include <memory>

class Node {
public:
    int data;
    Node *next;

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
    int length();
    bool isBatch();
};

Node* addNode(Node *n1, Node *n2);
