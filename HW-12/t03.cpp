#include <iostream>
#include <string>


struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};


class Stack {
    Node* head;
    int elementCount = 0;
public:
    Stack() : head(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return this->head == nullptr;
    }

    void push(int n) {
        Node* newNode = new Node(n);
        newNode->next = this->head;
        this->head = newNode;

        this->elementCount++;

        std::cout << "ok" << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "error" << std::endl;
            return;
        }
        Node* temp = this->head;
        this->head = this->head->next;
        this->elementCount--;
        std::cout << temp->data << std::endl;
        delete temp;
    }

    void size() {
        std::cout << this->elementCount << std::endl;
    }

    void back() const {
        if (isEmpty()) {
            std::cout << "error" << std::endl;
            return;
        }
        std::cout << this->head->data << std::endl;
    }

    void clear() {
        while (!isEmpty()) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->elementCount = 0;
        std::cout << "ok" << std::endl;
    }
};


int main(){
    std::string command;
    Stack stack;
    while (std::cin >> command) {
        if (command == "push") {
            int n;
            std::cin >> n;
            stack.push(n);
        }
        else if (command == "pop") {
            stack.pop();
        }
        else if (command == "back") {
            stack.back();
        }
        else if (command == "size") {
            stack.size();
        }
        else if (command == "clear") {
            stack.clear();
        }
        else if (command == "exit") {
            std::cout << "bye" << std::endl;
            break;
        }
    }
}