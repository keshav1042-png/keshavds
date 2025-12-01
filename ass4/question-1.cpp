#include <bits/stdc++.h>
using namespace std;

class SimpleQueue {
    int *arr, capacity;
    int frontIdx, rearIdx;
public:
    SimpleQueue(int cap=100) {
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0; rearIdx = -1;
    }
    ~SimpleQueue(){ delete[] arr; }

    bool isEmpty(){ return rearIdx < frontIdx; }
    bool isFull(){ return rearIdx - frontIdx + 1 == capacity; }

    void enqueue(int x){
        if(isFull()){ cout<<"Queue is full\n"; return; }
        arr[++rearIdx] = x;
    }
    int dequeue(){
        if(isEmpty()){ cout<<"Queue is empty\n"; return INT_MIN; }
        return arr[frontIdx++];
    }
    int peek(){
        if(isEmpty()){ cout<<"Queue is empty\n"; return INT_MIN; }
        return arr[frontIdx];
    }
    void display(){
        if(isEmpty()){ cout<<"Queue is empty\n"; return; }
        for(int i=frontIdx;i<=rearIdx;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    SimpleQueue q(10);
    int choice, val;
    while(true){
        cout<<"\n1-enqueue 2-dequeue 3-peek 4-display 5-isEmpty 6-isFull 0-exit\n>";
        cin>>choice;
        if(choice==0) break;
        switch(choice){
            case 1: cin>>val; q.enqueue(val); break;
            case 2: {int v=q.dequeue(); if(v!=INT_MIN) cout<<"Dequeued "<<v<<"\n";} break;
            case 3: {int v=q.peek(); if(v!=INT_MIN) cout<<"Front: "<<v<<"\n";} break;
            case 4: q.display(); break;
            case 5: cout<<(q.isEmpty()?"Empty":"Not Empty")<<"\n"; break;
            case 6: cout<<(q.isFull()?"Full":"Not Full")<<"\n"; break;
            default: cout<<"Invalid\n";
        }
    }
    return 0;
}
