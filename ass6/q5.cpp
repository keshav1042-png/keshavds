#include <bits/stdc++.h>
using namespace std;
struct Node { int data; Node* next; Node(int x): data(x), next(nullptr) {} };

bool isCircular(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Quick demo building a circular list if requested
int main() {
    // demo: build 2->4->6->7->5 and make it circular by connecting tail->next = head
    Node* a = new Node(2);
    Node* b = new Node(4);
    Node* c = new Node(6);
    Node* d = new Node(7);
    Node* e = new Node(5);
    a->next=b; b->next=c; c->next=d; d->next=e;
    // make circular:
    e->next = a; // comment this to test non-circular
    cout << (isCircular(a) ? "True\n" : "False\n");
    // skip freeing demo nodes for brevity
    return 0;
}
