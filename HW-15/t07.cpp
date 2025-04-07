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

    void ReorderList() {
        if (!head || !head->next) return;
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *second = slow->next;
        slow->next = NULL;
        second = reverseList(second);
        Node *first = head;
        while (second) {
            Node *tmp1 = first->next;
            Node *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
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

private:
    Node* reverseList(Node *node) {
        Node *prev = NULL, *cur = node;
        while (cur) {
            Node *nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
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
    lst.ReorderList();
    lst.Print();
    return 0;
}