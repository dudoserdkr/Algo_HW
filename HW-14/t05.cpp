#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) { val=v; next=nullptr; }
};

class MyQueue {
private:
    Node* head;
    Node* tail;
    int sz;
public:
    MyQueue() { head=nullptr; tail=nullptr; sz=0; }
    void push(int x) {
        Node* n=new Node(x);
        if(!head) {
            head=n; tail=n;
        } else {
            tail->next=n;
            tail=n;
        }
        sz++;
        cout<<"ok\n";
    }
    void clear() {
        while(head) {
            Node* t=head;
            head=head->next;
            delete t;
        }
        tail=nullptr;
        sz=0;
        cout<<"ok\n";
    }
    int pop() {
        if(!head) return -1;
        Node* t=head;
        int v=t->val;
        head=head->next;
        if(!head) tail=nullptr;
        delete t;
        sz--;
        return v;
    }
    int front() {
        if(!head) return -1;
        return head->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz==0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MyQueue q;
    while(true) {
        string cmd;
        cin>>cmd;
        if(cmd=="push") {
            int n;
            cin>>n;
            q.push(n);
        } else if(cmd=="pop") {
            if(q.empty()) cout<<"error\n";
            else cout<<q.pop()<<"\n";
        } else if(cmd=="front") {
            if(q.empty()) cout<<"error\n";
            else cout<<q.front()<<"\n";
        } else if(cmd=="size") {
            cout<<q.size()<<"\n";
        } else if(cmd=="clear") {
            q.clear();
        } else if(cmd=="exit") {
            cout<<"bye\n";
            break;
        }
    }
    return 0;
}