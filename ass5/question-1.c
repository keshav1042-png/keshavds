#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(NULL) {}
};

Node* head = NULL;

void insertAtBeg(int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtEnd(int val){
    Node* n = new Node(val);
    if(!head){ head = n; return; }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = n;
}

void insertBeforeAfter(int key, int val, bool before){
    if(!head){ cout<<"List empty\n"; return; }
    if(before && head->data==key){ insertAtBeg(val); return; }
    Node* prev=NULL, *curr=head;
    while(curr && curr->data!=key){ prev=curr; curr=curr->next; }
    if(!curr){ cout<<"Key not found\n"; return; }
    Node* n = new Node(val);
    if(before){
        prev->next = n; n->next = curr;
    } else {
        n->next = curr->next; curr->next = n;
    }
}

void deleteBeg(){
    if(!head){ cout<<"List empty\n"; return; }
    Node* temp=head; head=head->next; delete temp;
}

void deleteEnd(){
    if(!head){ cout<<"List empty\n"; return; }
    if(!head->next){ delete head; head=NULL; return; }
    Node* temp=head;
    while(temp->next->next) temp=temp->next;
    delete temp->next; temp->next=NULL;
}

void deleteNode(int key){
    if(!head) return;
    if(head->data==key){ Node* t=head; head=head->next; delete t; return; }
    Node* curr=head;
    while(curr->next && curr->next->data!=key) curr=curr->next;
    if(curr->next){ Node* t=curr->next; curr->next=t->next; delete t; }
    else cout<<"Not found\n";
}

void searchNode(int key){
    Node* temp=head; int pos=1;
    while(temp){
        if(temp->data==key){ cout<<"Found at "<<pos<<"\n"; return; }
        temp=temp->next; pos++;
    }
    cout<<"Not found\n";
}

void display(){
    Node* temp=head;
    while(temp){ cout<<temp->data<<" "; temp=temp->next; }
    cout<<"\n";
}

int main(){
    int ch,x,key; bool before;
    while(true){
        cout<<"\n1-InsertBeg 2-InsertEnd 3-InsertBefore 4-InsertAfter 5-DelBeg 6-DelEnd 7-DelNode 8-Search 9-Display 0-Exit\n>";
        cin>>ch; if(ch==0) break;
        switch(ch){
            case 1: cin>>x; insertAtBeg(x); break;
            case 2: cin>>x; insertAtEnd(x); break;
            case 3: cin>>key>>x; insertBeforeAfter(key,x,true); break;
            case 4: cin>>key>>x; insertBeforeAfter(key,x,false); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: cin>>key; deleteNode(key); break;
            case 8: cin>>key; searchNode(key); break;
            case 9: display(); break;
        }
    }
}
