#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node() : next(NULL) {}
    Node(int data, Node *next = NULL) : data(data), next(next) {}
};

class List {
public:
    Node *head, *tail;
    List() : head(NULL), tail(NULL) {}
    
    void addToTail(int val) {
        Node *newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Print() {
        Node *cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }

    void PrintReverse() {
        PrintReverseHelper(head);
        std::cout << "\n";
    }

private:
    void PrintReverseHelper(Node *node) {
        if (!node) return;
        PrintReverseHelper(node->next);
        std::cout << node->data << " ";
    }
};

int main() {
    int n;
    std::cin >> n;
    List lst;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        lst.addToTail(x);
    }
    lst.Print();
    lst.PrintReverse();
    return 0;
}