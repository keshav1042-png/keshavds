#include <bits/stdc++.h>
using namespace std;

struct Node { char data; Node *prev, *next; Node(char c): data(c), prev(nullptr), next(nullptr) {} };

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node* tail = head;
    while(tail->next) tail = tail->next;
    Node* l = head;
    Node* r = tail;
    while(l != r && l->prev != r) {
        if (l->data != r->data) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

// small helper to build list from string:
Node* buildFromString(const string &s) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for(char c : s) {
        Node* n = new Node(c);
        if (!head) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
    }
    return head;
}

int main() {
    string s;
    cout << "Enter string (characters to insert in DLL): ";
    if(!(cin >> s)) return 0;
    Node* head = buildFromString(s);
    cout << (isPalindrome(head) ? "True\n" : "False\n");
    // free memory (simple)
    Node* cur = head;
    while(cur) { Node* nxt = cur->next; delete cur; cur = nxt; }
    return 0;
}
