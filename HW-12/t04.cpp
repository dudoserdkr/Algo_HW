#include <stdexcept>
#include <iostream>
#include <vector>

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
            pop();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void push(int n) {
        Node* node = new Node(n);
        node->next = head;
        head = node;
        elementCount++;
    }

    int pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* temp = head;
        head = head->next;
        int value = temp->data;
        delete temp;
        elementCount--;
        return value;
    }

    int back() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return head->data;
    }
};


int main() {
    int n;
    while (std::cin >> n && n != 0) {
        while (true) {
            std::vector<int> arr(n);

            std::cin >> arr[0];
            if (arr[0] == 0) {
                std::cout << std::endl;
                break;
            }

            for (int i = 1; i < n; i++) {
                std::cin >> arr[i];
            }

            Stack stack;
            int current = 1;
            bool isPossible = true;

            for (int i = 0; i < n; i++) {
                while (current <= n && (stack.isEmpty() || stack.back() != arr[i])) {
                    stack.push(current);
                    current++;
                }

                if (!stack.isEmpty() && stack.back() == arr[i]) {
                    stack.pop();
                } else {
                    isPossible = false;
                    break;
                }
            }

            std::cout << (isPossible ? "Yes" : "No") << std::endl;
        }
    }
}
