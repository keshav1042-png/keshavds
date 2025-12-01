#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

int sizeOfDLL(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Create a simple Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Size of Doubly Linked List: " << sizeOfDLL(head) << endl;

    // cleanup
    Node* temp = head;
    while (temp) {
        Node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    return 0;
}
