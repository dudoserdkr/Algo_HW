#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
    int sz;
public:
    Queue(): head(nullptr), tail(nullptr), sz(0) {}
    void push(int x) {
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        sz++;
    }
    int pop() {
        int v = head->val;
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        sz--;
        return v;
    }
    int front() {
        return head->val;
    }
    bool empty() {
        return head == nullptr;
    }
};

bool firstWins(int a, int b, int n) {
    if(a == 0 && b == n-1) return true;
    if(b == 0 && a == n-1) return false;
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Queue p1, p2;
    for (int i = 0; i < n/2; i++){
        int x;
        cin >> x;
        p1.push(x);
    }
    for (int i = 0; i < n/2; i++){
        int x;
        cin >> x;
        p2.push(x);
    }
    int moves = 0;
    while(!p1.empty() && !p2.empty() && moves <= 200000){
        int c1 = p1.front();
        int c2 = p2.front();
        p1.pop();
        p2.pop();
        if(firstWins(c1, c2, n)){
            p1.push(c1);
            p1.push(c2);
        } else {
            p2.push(c1);
            p2.push(c2);
        }
        moves++;
    }
    if(moves > 200000)
        cout << "draw" << "\n";
    else if(p2.empty())
        cout << "first " << moves << "\n";
    else if(p1.empty())
        cout << "second " << moves << "\n";
    return 0;
}