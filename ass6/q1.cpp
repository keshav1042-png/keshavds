#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int x): data(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList(): head(nullptr) {}
    ~DoublyLinkedList() {
        Node* cur = head;
        while(cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void insertFront(int x) {
        Node* n = new Node(x);
        n->next = head;
        if (head) head->prev = n;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* cur = head;
        while(cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }

    bool insertAfter(int key, int x) {
        Node* cur = head;
        while(cur && cur->data != key) cur = cur->next;
        if (!cur) return false;
        Node* n = new Node(x);
        n->next = cur->next;
        n->prev = cur;
        if (cur->next) cur->next->prev = n;
        cur->next = n;
        return true;
    }

    bool insertBefore(int key, int x) {
        Node* cur = head;
        while(cur && cur->data != key) cur = cur->next;
        if (!cur) return false;
        if (cur == head) {
            insertFront(x);
            return true;
        }
        Node* n = new Node(x);
        n->next = cur;
        n->prev = cur->prev;
        cur->prev->next = n;
        cur->prev = n;
        return true;
    }

    bool deleteNode(int key) {
        Node* cur = head;
        while(cur && cur->data != key) cur = cur->next;
        if (!cur) return false;
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        delete cur;
        return true;
    }

    Node* search(int key) {
        Node* cur = head;
        while(cur) {
            if (cur->data == key) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    int size() {
        int cnt = 0;
        Node* cur = head;
        while(cur) { cnt++; cur = cur->next; }
        return cnt;
    }

    void displayForward() {
        if (!head) { cout << "List empty\n"; return; }
        Node* cur = head;
        while(cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    void displayBackward() {
        if (!head) { cout << "List empty\n"; return; }
        Node* cur = head;
        while(cur->next) cur = cur->next;
        while(cur) {
            cout << cur->data;
            if (cur->prev) cout << " <-> ";
            cur = cur->prev;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    while (true) {
        cout << "\nDoubly Linked List Menu\n";
        cout << "1. Insert Front\n2. Insert End\n3. Insert After value\n4. Insert Before value\n5. Delete value\n6. Search value\n7. Display Forward\n8. Display Backward\n9. Size\n0. Exit\nChoose: ";
        int ch; if(!(cin>>ch)) return 0;
        if (ch == 0) break;
        int x, key;
        bool res;
        switch(ch) {
            case 1: cout<<"Value: "; cin>>x; dll.insertFront(x); break;
            case 2: cout<<"Value: "; cin>>x; dll.insertEnd(x); break;
            case 3: cout<<"Key to insert after: "; cin>>key; cout<<"Value: "; cin>>x;
                    res = dll.insertAfter(key,x);
                    if (!res) cout<<"Key not found\n"; break;
            case 4: cout<<"Key to insert before: "; cin>>key; cout<<"Value: "; cin>>x;
                    res = dll.insertBefore(key,x);
                    if (!res) cout<<"Key not found\n"; break;
            case 5: cout<<"Delete value: "; cin>>key;
                    res = dll.deleteNode(key);
                    if (!res) cout<<"Value not found\n"; break;
            case 6: cout<<"Search value: "; cin>>key;
                    res = (dll.search(key)!=nullptr);
                    cout << (res ? "Found\n" : "Not found\n"); break;
            case 7: dll.displayForward(); break;
            case 8: dll.displayBackward(); break;
            case 9: cout<<"Size: "<<dll.size()<<"\n"; break;
            default: cout<<"Invalid choice\n";
        }
    }
    return 0;
}
