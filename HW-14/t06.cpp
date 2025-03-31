#include <iostream>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int v): val(v), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
    int sz;
public:
    Deque(): head(nullptr), tail(nullptr), sz(0) {}
    void push_front(int x) {
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
        cout << "ok" << "\n";
    }
    void push_back(int x) {
        Node* node = new Node(x);
        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
        cout << "ok" << "\n";
    }
    void pop_front() {
        if (!head) { cout << "error" << "\n"; return; }
        int v = head->val;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr; else tail = nullptr;
        delete temp;
        sz--;
        cout << v << "\n";
    }
    void pop_back() {
        if (!tail) { cout << "error" << "\n"; return; }
        int v = tail->val;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr; else head = nullptr;
        delete temp;
        sz--;
        cout << v << "\n";
    }
    void front() {
        if (!head) { cout << "error" << "\n"; return; }
        cout << head->val << "\n";
    }
    void back() {
        if (!tail) { cout << "error" << "\n"; return; }
        cout << tail->val << "\n";
    }
    void size() {
        cout << sz << "\n";
    }
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        sz = 0;
        cout << "ok" << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Deque d;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push_front") {
            int x; cin >> x;
            d.push_front(x);
        } else if (cmd == "push_back") {
            int x; cin >> x;
            d.push_back(x);
        } else if (cmd == "pop_front") d.pop_front();
        else if (cmd == "pop_back") d.pop_back();
        else if (cmd == "front") d.front();
        else if (cmd == "back") d.back();
        else if (cmd == "size") d.size();
        else if (cmd == "clear") d.clear();
        else if (cmd == "exit") { cout << "bye" << "\n"; break; }
    }
    return 0;
}