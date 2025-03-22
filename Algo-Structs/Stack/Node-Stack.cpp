#include <stdexcept>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


class Stack {
    Node* head;
    int elementCount;
public:
    Stack() : elementCount(0), head(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            this->pop();
        }
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    void push(int n) {
        if (isEmpty()) {
            this->head = new Node(n);
        }
        else {
            this->head->next = new Node(n);
        }
        this->elementCount++;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    int back() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return this->head->data;
    }
};