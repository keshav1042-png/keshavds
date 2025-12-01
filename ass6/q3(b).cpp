#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

int sizeOfCLL(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Create Circular Linked List: 5 -> 10 -> 15 -> 20 -> (back to 5)
    Node* head = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(15);
    Node* fourth = new Node(20);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // circular connection

    cout << "Size of Circular Linked List: " << sizeOfCLL(head) << endl;

    // cleanup manually breaking the circle first
    fourth->next = nullptr;
    Node* temp = head;
    while (temp) {
        Node* nxt = temp->next;
        delete temp;
        temp = nxt;
    }
    return 0;
}
